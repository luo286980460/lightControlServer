#include "widget.h"
#include "ui_widget.h"
#include "producer.h"
#include "lightcontroll.h"
#include "myhttpserver.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDir>
#include <QLockFile>
#include <QDateTime>
#include <QMenu>
#include <QTime>
#include <QFile>
#include <QTextCodec>

#define INIFILE_PORT         "/ports.ini"
#define INIFILE_LIGHT        "/Controllers.ini"
#define INIFILE_KAFKA        "/kafka.ini"
#define INIFILE_MAINSETTINGS "/mainSeeting.ini"
#define INIFILE_FILEWATCHER  "/fileWatcher.ini"
#define CZX_URL              "http://127.0.0.1:6789/SetJXJTProgramFTemp"
//#define CZX_URL              "http://127.0.0.1:8888/light"
#define LOG "/log.txt"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_isOpen(false)
    , m_ff88Flag(0)
    , m_ff88("FF 88 FF 10 00 AA")
{
    //setWindowIconText("123");
    ui->setupUi(this);
    ui->testBtn->hide();
    setFixedSize(size());
    setWindowTitle("前端设备控制服务_2024年10月12日_by:ls");//.arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日hh时mm分ss秒")));
    initSystemTray();   // 初始化系统托盘
    //initRoadState();    // 初始化车道开启状态

    ui->OpenBtn->hide();

    //m_timer.setInterval(5*60*1000);
    m_timer.setInterval(5000);
    connect(&m_timer, &QTimer::timeout, this, [this](){
        m_roadIsOpen = "0";
        updateRoadStateSetting("0");
        m_timer.stop();

        showMsg(QString("应急车道状态已更新，当前可行状态为：关闭"));
    });

    m_settings = new QSettings(QCoreApplication::applicationDirPath() + INIFILE_PORT, QSettings::IniFormat, this);
    //on_OpenBtn_clicked();

    // 秒级定时器
    connect(&m_mscTimer, &QTimer::timeout, this, [this](){
        // 刷新雾灯闪烁
        if(m_ff88Flag == 300){
            m_ff88Flag = 0;
            sendFF88();
        }else{
            m_ff88Flag++;
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::open()
{
    ui->OpenBtn->click();
}

void Widget::initPostRequest()
{
    //初始化 light 请求资源
    m_manager= new QNetworkAccessManager(this);
    m_postRequest = new QNetworkRequest;
    QMetaObject::Connection connRet = connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);
    m_postRequest->setHeader(QNetworkRequest::ContentTypeHeader, "Content/json");  //设置请求头
    m_postRequest->setHeader(QNetworkRequest::UserAgentHeader,
                                  "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:48.0) Gecko/20100101 Firefox/48.0");
}

void Widget::initRoadState()
{
    QString iniPath = QCoreApplication::applicationDirPath() + INIFILE_MAINSETTINGS;
    if(!QFileInfo::exists(iniPath)){
        showMsg("****** mainSeeting.ini 配置文件丢失 ******");
        return;
    }
    QSettings settings(QCoreApplication::applicationDirPath() + INIFILE_MAINSETTINGS, QSettings::IniFormat);
    m_roadIsOpen = settings.value("roadState/m_roadIsOpen", "0").toString();

}

void Widget::openHttpServer()
{
    m_httpServer = new MyHttpServer(this);
    connect(m_httpServer, &MyHttpServer::showMsg, this, &Widget::showMsg);
    connect(m_httpServer, &MyHttpServer::sigalUpdateRoadState, this, &Widget::slotUpdateRoadState);
    connect(m_httpServer, &MyHttpServer::sigleUpdateTermListUi, this, &Widget::soltUpdateTermListUi);
    connect(m_httpServer, &MyHttpServer::sigleUpdateControllerUi, this, &Widget::slotUpdateControllerUi);
    connect(m_httpServer, &MyHttpServer::signalUpdateFF88, this, &Widget::slotUpdateFF88);
    connect(m_httpServer, &MyHttpServer::signalWrite2Kafka, this, &Widget::write2Kafka);
    m_httpServer->create(QHostAddress::Any, m_settings->value("httpServer/httpServerPort", 8886).toInt());

    openControlls();

    m_httpServer->updateLightControllList(&m_lightControllList);

    soltUpdateTermListUi();
}

void Widget::openProducer()
{
    QString iniPath = QCoreApplication::applicationDirPath() + INIFILE_KAFKA;
        if(!QFileInfo::exists(iniPath)){
            showMsg("****** kafka.ini 配置文件丢失 ******");
            return;
        }
    QSettings settings(iniPath, QSettings::IniFormat);
    int topicCount = settings.value("topics/topicCount", 0).toInt();
    QString kafkaIp = settings.value("kafka/ip", 0).toString();

    for(int i=0; i<topicCount; i++){
        QString strTopic = settings.value(QString("topics/topic%1").arg(i+1,2,10,QLatin1Char('0')), "test_ls").toString(); //kafka主题
        m_producer = new producer(this);
        connect(m_producer, &producer::showMsg, this, &Widget::showMsg);
        connect(this, &Widget::write2Kafka, m_producer, &producer::slotProduceMessvoidJson);
        m_producer->setTopic(strTopic);
        m_producer->setkafkaIp(kafkaIp);
        m_producer->start();
        m_producer->init();
        emit m_producer->sigleInitWork();
        m_producerList.append(m_producer);
    }
}

void Widget::openControlls()
{
    if(m_lightControllList.size() != 0)
            qDeleteAll(m_lightControllList);
    m_lightControllList.clear();
    m_controllCount = 0;

    QString iniPath = QCoreApplication::applicationDirPath() + INIFILE_LIGHT;
    if(!QFileInfo::exists(iniPath)){
            showMsg("******雾灯配置文件读取失败");
            return;
    }
    QSettings settings(QCoreApplication::applicationDirPath() + INIFILE_LIGHT, QSettings::IniFormat);
    m_controllCount = settings.value("Controllers/ControllersCount").toInt();

    //获取发送间隔 和 发送命令数量
    QString ConnectType = settings.value("Controllers/ConnectType", "UDP").toString().toUpper();//控制器 连接方式
    int sendingInterval = settings.value(QString("Controllers/SendingInterval"), 500).toInt();
    int sendingCount = settings.value(QString("Controllers/SendingCount"), 5).toInt();
    QString topic = settings.value("Controllers/Topic", "test_ls").toString();      //控制器 主题

    if(ConnectType != "UDP" && ConnectType != "TCP" ){
        ConnectType = "UDP";
    }

    for(int i=0; i<m_controllCount; i++){
            lightcontroll* controll;    //控制器
            QString controllIp = settings.value(QString("Controllers/Ip%1").arg(i+1,2,10,QLatin1Char('0'))).toString();   //控制器 IP
            int controllPort = settings.value(QString("Controllers/Port%1").arg(i+1,2,10,QLatin1Char('0'))).toInt();      //控制器 port
            QString version = settings.value(QString("Controllers/Version%1").arg(i+1,2,10,QLatin1Char('0')), "1").toString();

            //创建控制器
            controll = new lightcontroll(ConnectType, topic, controllIp, controllPort, sendingInterval, sendingCount, version, this);
            m_lightControllList.append(controll);

            connect(controll, SIGNAL(showMsg(QString)), this, SLOT(showMsg(QString)));
            connect(this, &Widget::write2Light, controll, &lightcontroll::sigSendDatagram);
            connect(controll, SIGNAL(write2Kafka(QString,QString,QString)), this, SIGNAL(write2Kafka(QString,QString,QString)));

            controll->start();
            emit controll->sigConnectToControl();

            /*if(!controll->connectControll()){
            emit showMsg("控制器：" + controllIp + " 连接失败");
            emit sigleUpdateControllerUi( "控制器：" + controllIp + " 离线");
        }else{
            emit showMsg("控制器：" + controllIp + " 连接成功");
            emit sigleUpdateControllerUi( "控制器：" + controllIp + " 在线");
        }*/

    }
}

void Widget::updateRoadStateSetting(QString state)
{
    // 获取屏幕配置文件
    QString iniPath = QCoreApplication::applicationDirPath() + INIFILE_MAINSETTINGS;
    if(!QFileInfo::exists(iniPath)){
        showMsg("******屏幕配置文件读取失败");
        return;
    }
    QSettings settings(QCoreApplication::applicationDirPath() + INIFILE_MAINSETTINGS, QSettings::IniFormat);
    settings.setValue("roadState/m_roadIsOpen", state);
}

void Widget::closeEvent(QCloseEvent* event)
{
    if(trayIcon->isVisible())
        {
            hide(); //隐藏窗口
            event->ignore(); //忽略事件
    }
}

void Widget::initSystemTray()
{
    //托盘初始化
        QIcon icon = QIcon(":/icon.png");
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(icon);
        trayIcon->setToolTip("江苏尤特智能科技有限公司");
        trayIcon->show(); //必须调用，否则托盘图标不显示

        //创建菜单项动作(以下动作只对windows有效)
        minimizeAction = new QAction("最小化~", this);
        connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide())); //绑定信号槽

        maximizeAction = new QAction("最大化~", this);
        connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

        restoreAction = new QAction("还原~", this);
        connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

        quitAction = new QAction("退出~", this);
        connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit())); //关闭应用，qApp对应的是程序全局唯一指针

        //创建托盘菜单(必须先创建动作，后添加菜单项，还可以加入菜单项图标美化)
        trayIconMenu = new QMenu(this);
        trayIconMenu->addAction(minimizeAction);
        trayIconMenu->addAction(maximizeAction);
        trayIconMenu->addAction(restoreAction);
        trayIconMenu->addSeparator();
        trayIconMenu->addAction(quitAction);
        trayIcon->setContextMenu(trayIconMenu);


        connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

QString Widget::utf8ToGb2312(char *strUtf8)
{
    //printf("~~~~utf8  strUtf8:%s\n", strUtf8);
    QTextCodec* utf8Codec= QTextCodec::codecForName("utf-8");
    QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");

    QString strUnicode= utf8Codec ->toUnicode(strUtf8);
    QByteArray ByteGb2312= gb2312Codec ->fromUnicode(strUnicode);

    strUtf8= ByteGb2312.data();
    //printf("~~~~~gb2312	strUtf8toGb2312:%s\n", strUtf8);
    return QString::fromLocal8Bit(strUtf8);//注意这里要fromLocal8Bit()
}

QString Widget::gb2312ToUtf8(QString strGb2312)
{
    //printf("@@@ gb2312 str is:%s\n",strGb2312.toLocal8Bit().data());
    QTextCodec* utf8Codec= QTextCodec::codecForName("utf-8");
    QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");

    QString strUnicode= gb2312Codec->toUnicode(strGb2312.toLocal8Bit().data());
    QByteArray ByteUtf8= utf8Codec->fromUnicode(strUnicode);

    //char *utf8code = ByteUtf8.data();
    return QString::fromUtf8(ByteUtf8.data());
    //printf("@@@ Utf8  strGb2312toUtf8:%s\n",utf8code);
}

void Widget::on_clearBtn_clicked()
{
    ui->history->clear();
}

void Widget::showMsg(QString msg)
{
    ui->history->appendPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " --> " + msg);

    QString logPath = QCoreApplication::applicationDirPath() + LOG;
    QFile file(logPath);
    if(file.open(QIODevice::Append)){
        file.write(msg.toLocal8Bit());
        file.write("\n");
    }else{
        ui->history->appendPlainText("log文件打开失败");
    }
}


void Widget::on_OpenBtn_clicked()
{
    if(m_isOpen){
        ui->history->clear();
        ui->OpenBtn->setText("打开服务器");

        if(m_lightControllList.size() != 0)
            qDeleteAll(m_lightControllList);
        m_lightControllList.clear();
        m_controllCount = 0;

        if(m_producerList.size() != 0)
            qDeleteAll(m_producerList);
        m_producerList.clear();
        m_httpServer->deleteLater();
        m_isOpen = !m_isOpen;
    }else{
        ui->history->clear();
        ui->OpenBtn->setText("关闭服务器");

        openProducer();
        openHttpServer();   // 打开http服务，可控雾灯、右转屏、音响
        //openUdpServer();  // 打开UDP服务用来接收数据
        //openFileWatcher();  // 超速摄像头文件监控模块
        //m_isOpen = !m_isOpen;
    }
}

void Widget::slotUpdateRoadState(QString roadIsOpen)
{
    if(roadIsOpen == "1"){     // 需要打开

        if(m_timer.isActive()){
            m_timer.stop();
        }
        m_roadIsOpen = "1";
        updateRoadStateSetting("1");
        showMsg(QString("应急车道状态已更新为： 开启"));
    }else{              // 需要关闭
        m_roadIsOpen = "3";
        updateRoadStateSetting("3");

        if(m_timer.isActive()){
            m_timer.stop();
        }
        m_timer.start();
    }

}

void Widget::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        //trayIcon->showMessage("title","你单击了"); //后面两个默认参数
        show();
        break;
    case QSystemTrayIcon::DoubleClick:
        show();
        break;
    case QSystemTrayIcon::MiddleClick:
        trayIcon->showMessage("title","你中键了");
        break;
    default:
        break;
    }
}

void Widget::soltUpdateTermListUi()
{
    int nCurSel = ui->termListComboBox->currentIndex();
    ui->termListComboBox->clear();

    QString strText;
    for(int i=0; i<m_httpServer->m_nTermCnt; i++)
    {
        strText = QString("ID:[%1]  名称:[%2]  IP:[%3]  状态:[%4]")
                .arg(QString::number(m_httpServer->m_TermList[i].dwTermID, 16)
                , m_httpServer->m_TermList[i].TermName
                , m_httpServer->m_TermList[i].TermIp
                , m_httpServer->m_TermState[i].eState==TSDK_DEV_STATE_OFFLINE ? "不在线":"在线");

        ui->termListComboBox->addItem(strText);
    }

    if(m_httpServer->m_nTermCnt > 0)
    {
        if(nCurSel >= 0 && nCurSel < m_httpServer->m_nTermCnt)
            ui->termListComboBox->setCurrentIndex(nCurSel);
        else
            ui->termListComboBox->setCurrentIndex(0);
    }
}

void Widget::slotUpdateControllerUi(QString str)
{
    //ui->controllerLIstComboBox->addItem(str);
}

void Widget::slotUpdateFF88(QString ff88)
{
    m_ff88 = ff88;
}

void Widget::sendFF88()
{
    /*此处发送同步命令， 并更新同步命令变量*/
    QStringList sendDataList;
    sendDataList.append(m_ff88);
    emit write2Light(sendDataList,  "no",  "", 2, 9, -1, "-1,-1");
}

void Widget::openFileWatcher()
{
    initPostRequest();
    // 获取屏幕配置文件
    QString iniPath = QCoreApplication::applicationDirPath() + INIFILE_FILEWATCHER;
    if(!QFileInfo::exists(iniPath)){
        showMsg("******文件路径 配置文件读取失败");
        return;
    }

    m_fileWather = new QFileSystemWatcher(this);
    connect(m_fileWather, SIGNAL(directoryChanged(QString)), this, SLOT(dealPicFiles(QString)));


    QSettings settings(QCoreApplication::applicationDirPath() + INIFILE_FILEWATCHER, QSettings::IniFormat);
    m_path = settings.value("PicPath/picPath01", "").toString();         // 摄像头文件保存路径
    m_screenIp = settings.value("PicPath/Ip01", "").toString();          // 摄像头文件保存路径
    m_screenPort = settings.value("PicPath/Port01", 5000).toInt();       // 摄像头文件保存路径

    m_path = m_path + "/" + QDate::currentDate().toString("yyyyMMdd");
    QDir dir(m_path);
    //ui->history->clear();
    //showMsg(path);
    if(!dir.exists()){
        dir.mkpath(m_path);
    }
    m_fileWather->addPath(m_path);
    showMsg("监控文件夹已更改: " + m_path);
}

QString Widget::getBackUpPath(QString filePath)
{
    filePath.insert(3, "backUp");
    QDir dir(filePath);

    if(!dir.exists()){
        bool ismkdir = dir.mkpath(filePath);
        if(!ismkdir)
            qDebug() << "Create path fail";
        else
            qDebug() << "Create fullpath success";
    }
    return filePath;
}

void Widget::on_testBtn_clicked()
{
    emit m_httpServer->forTest();
}

void Widget::dealPicFiles(QString path)
{
    QEventLoop eventloop;
    QTimer::singleShot(300, &eventloop, SLOT(quit()));
    eventloop.exec();

    QJsonObject json;
    QJsonDocument jsonDoc;
    QString backUpPath = getBackUpPath(path);
    QString picUrl = backUpPath + "/";

    QDir dir(path);   //打开目录

    //筛选不要 . 和 .. 文件 , 只要文件(如果需要文件夹,加上 QDir::Dirs
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files);

    //提取文件信息链表
    QFileInfoList inforList = dir.entryInfoList();

    //遍历文件信息链表,并进行相关操作
    foreach (QFileInfo info, inforList) {
        picUrl = backUpPath + "/";
        QString fileName = info.fileName();
        QString fileNamePath = info.filePath();

        if(!fileName.contains(".jpg")){          // 照片文件类型不是jpg 删除
            remove(fileNamePath.toLocal8Bit());
            continue;
        }

        rename(fileNamePath.toLocal8Bit(), (backUpPath + "/" + fileName).toLocal8Bit());

        QString plate;
        QStringList strList = fileName.split("_", Qt::SkipEmptyParts);

        if(strList.size() != 12){                // 照片文件名格式不对 删除
            showMsg("******照片文件名格式错误");
            remove(fileNamePath.toLocal8Bit());
            continue;
        }

        plate = strList.at(1);

        QJsonObject jsonTmp1, jsonTmp2;
        QJsonArray jsonArray;

        json.insert("DEVICEID", "1001");
        json.insert("IPADDRESS", m_screenIp);
        json.insert("PORTNUMBER", QString::number(m_screenPort));
        json.insert("SPEED", strList.at(4));

        jsonTmp1.insert("COLOR", "green");
        jsonTmp1.insert("CONTENT", plate);
        jsonArray.append(jsonTmp1);
        jsonTmp2.insert("COLOR", "red");
        jsonTmp2.insert("CONTENT", "超速行驶");
        jsonArray.append(jsonTmp2);

        json.insert("INFO1", jsonArray);
        json.insert("INFO2", jsonArray);
        json.insert("KAFKAPARAMS", "5");
        jsonDoc.setObject(json);

        m_postRequest->setUrl(QUrl(CZX_URL));      //设置Url
        m_manager->post(*m_postRequest, jsonDoc.toJson(QJsonDocument::Compact));
        emit showMsg(jsonDoc.toJson());
    }
}

void Widget::requestFinished(QNetworkReply *reply)
{

}


