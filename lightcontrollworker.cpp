#include <QEventLoop>
#include <QTimer>
#include <QThread>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>
#include "lightcontrollworker.h"
#include "lightCmdList.h"

lightControllWorker::lightControllWorker(QString connectType, QString topic, QString ip, int port, int sendingInterval,
                                         int sendingCount, QString version, QObject *parent)
    : QObject{parent}
    , m_sendingInterval(sendingInterval)    //单位 ms
    , m_sendingCount(sendingCount)          //发送数量
    , m_controllIp(ip)
    , m_controllPort(port)
    , m_topic(topic)
    , m_topic2("weatherWarning")
    , m_deviceId("")
    , m_contentStr("")
    , m_currentColor("橙")
    , m_flicker("0,0")
    , m_luminance(30)
    , m_version(version)
    , m_connectType(connectType)
{

    //m_timer.setInterval(30 * 60 * 1000);
    //m_timer.start();
    //connect(&m_timer, &QTimer::timeout, this, [/*this*/]{
        //slotSendDatagram(m_lastList, m_sbbh, m_name);
    //});

    if(m_connectType == "TCP"){
        initTcpSocket();
    }else{
        initUcpSocket();
    }
}

lightControllWorker::~lightControllWorker()
{
    if(m_tcpSocket)
    {
        delete m_tcpSocket;
    }
}

bool lightControllWorker::connectControll()
{
    emit showMsg(QString("控制器:%1:%2[正在连接]").arg(m_controllIp).arg(m_controllPort));
    m_tcpSocket->connectToHost(m_controllIp, m_controllPort);
    m_tcpSocket->setSocketOption(QTcpSocket::KeepAliveOption, 1);

    if (m_tcpSocket->waitForConnected(1000))  // 连接
    {
        emit showMsg(QString("控制器【%1:%2】连接成功").arg(m_controllIp).arg(m_controllPort));
        return true;
    }else{
        emit showMsg(QString("控制器【%1:%2】连接失败").arg(m_controllIp).arg(m_controllPort));
        return false;
    }
}

void lightControllWorker::SendDatagram1(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList, int TermIdSize)
{
    QStringList sendDataListTmp = sendDataList;
    if(Luminance != -1) m_luminance = Luminance;
    if(FlickerList != "no") m_flicker = FlickerList;

    m_currentColor = "橙";
    m_deviceId = DeviceId;
    m_contentStr = ContentStr;
    m_lastList = sendDataList;
    QString tmp;
    QJsonObject json;
    QJsonObject topic2Json;
    QJsonDocument jsonDoc;
    QEventLoop eventloop;


    json.insert("stateId", m_deviceId);
    json.insert("deviceId", m_deviceId);
    json.insert("checkDate", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    json.insert("handleState", "1");

    if(ContentStr.isEmpty()) ContentStr = "关闭";
    json.insert("value", ContentStr);
    json.insert("source", "1");
    json.insert("color", m_currentColor);
    json.insert("light", Luminance);
    json.insert("pl", m_flicker);

    if(m_tcpSocket && m_tcpSocket->state() != QAbstractSocket::ConnectedState){
        //qDebug() << m_tcpSocket->state();

        if(!connectControll()){
            json.insert("deviceState", "2");
            emit showMsg(QString("控制器:%1[网络故障]").arg(m_controllIp));
            jsonDoc.setObject(json);
            emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
            emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataListTmp, DeviceId, TermIdSize)).toJson(), "light");
            return;
        }
    }

    //qDebug() << (sendDataList);

    if(m_tcpSocket && m_tcpSocket->state() == QAbstractSocket::ConnectedState){
        //qDebug() << m_tcpSocket->state();
        while(!sendDataList.isEmpty()){
            // 将闪烁 和 亮度 和 颜色 命令发送，并休眠 10s
            if(    sendDataList.first().toUpper().contains("FF 66 FF")
                || sendDataList.first().toUpper().contains("FF 77 FF")
                || sendDataList.first().toUpper().contains("FF 88 FF")
                || sendDataList.first().toUpper().contains("FF 40 FF")  )
            {

                m_tcpSocket->write(QByteArray::fromHex(sendDataList.first().toLatin1()));
                m_tcpSocket->waitForBytesWritten();
                emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp).arg(sendDataList.first()));

                QTimer::singleShot(1000, &eventloop, SLOT(quit()));
                eventloop.exec();
                sendDataList.removeFirst();
                continue;
            }

            for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
                tmp = tmp + sendDataList.first() + " ";
                sendDataList.removeFirst();
            }

            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();
            emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp).arg(tmp));
            //msleep(m_sendingInterval);

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();
            //msleep(m_sendingInterval);

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();

            tmp.clear();
        }
        json.insert("deviceState", "1");
    }

    jsonDoc.setObject(json);
    emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataListTmp, DeviceId, TermIdSize)).toJson(), "light");
}

void lightControllWorker::SendDatagram2(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList, int TermIdSize)
{
    QStringList sendDataListTmp = sendDataList;
    if(Luminance != -1) m_luminance = Luminance;
    if(FlickerList != "no") m_flicker = FlickerList;
    //1红 2绿 3蓝 4白 5黄 6青 7洋红 8黑 9橙
    switch(fontColor){
    case 1:
        m_currentColor = "红";
        break;
    case 2:
        m_currentColor = "绿";
        break;
    case 3:
        m_currentColor = "蓝";
        break;
    case 4:
        m_currentColor = "白";
        break;
    case 5:
        m_currentColor = "黄";
        break;
    case 6:
        m_currentColor = "青";
        break;
    case 7:
        m_currentColor = "洋";
        break;
    case 8:
        m_currentColor = "黑";
        break;
    case 9:
        m_currentColor = "橙";
        break;
    case -1:
        break;
    default:
        m_currentColor = "橙";
        break;
    }

    m_deviceId = DeviceId;
    m_contentStr = ContentStr;
    m_lastList = sendDataList;

    QString tmp;
    QJsonObject json;
    QJsonObject topic2Json;
    QJsonDocument jsonDoc;
    QEventLoop eventloop;

    json.insert("stateId", m_deviceId);
    json.insert("deviceId", m_deviceId);
    json.insert("checkDate", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    json.insert("handleState", "1");

    if(ContentStr.isEmpty()) ContentStr = "关闭";
    json.insert("value", ContentStr);
    json.insert("source", "1");
    json.insert("color", m_currentColor);
    json.insert("light", m_luminance);
    json.insert("pl", m_flicker);


    if(m_tcpSocket && m_tcpSocket->state() != QAbstractSocket::ConnectedState){
        if(!connectControll()){
            json.insert("deviceState", "2");
            emit showMsg(QString("控制器:%1[网络故障]").arg(m_controllIp));
            jsonDoc.setObject(json);
            emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
            emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataListTmp, DeviceId, TermIdSize)).toJson(), "light");
            return;
        }
    }

    if(m_tcpSocket && m_tcpSocket->state() == QAbstractSocket::ConnectedState){

        for(int i=0; i<sendDataList.size(); i++){
            QString cmd = sendDataList.at(i);
            if(cmd.contains("FF 40")){
                m_tcpSocket->write(QByteArray::fromHex(cmd.toLatin1()));
                m_tcpSocket->waitForBytesWritten();
                emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp, cmd));
                //sendDataList.removeAt(i);
            }
        }

        while(!sendDataList.isEmpty()){
            tmp.clear();
            for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
                QString firstData = sendDataList.first();
                if(!firstData.contains("FF 40")){
                    tmp = tmp + firstData + " ";
                }
                sendDataList.removeFirst();
            }

            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();
            emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp, tmp));
        }
        json.insert("deviceState", "1");
    }

    jsonDoc.setObject(json);

    emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataListTmp, DeviceId, TermIdSize)).toJson(), "light");
}

void lightControllWorker::SendDatagram1Udp(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList, int TermIdSize)
{
    QStringList sendDataListTmp = sendDataList;
    if(Luminance != -1) m_luminance = Luminance;
    if(FlickerList != "no") m_flicker = FlickerList;

    m_currentColor = "橙";
    m_deviceId = DeviceId;
    m_contentStr = ContentStr;
    m_lastList = sendDataList;
    QString tmp;
    QJsonObject json;
    QJsonObject topic2Json;
    QJsonDocument jsonDoc;
    QEventLoop eventloop;


    json.insert("stateId", m_deviceId);
    json.insert("deviceId", m_deviceId);
    json.insert("checkDate", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    json.insert("handleState", "1");

    if(ContentStr.isEmpty()) ContentStr = "关闭";
    json.insert("value", ContentStr);
    json.insert("source", "1");
    json.insert("color", m_currentColor);
    json.insert("light", Luminance);
    json.insert("pl", m_flicker);


    //    判断是否在线
    // if(!connectControll()){
    //     json.insert("deviceState", "2");
    //     emit showMsg(QString("控制器:%1[网络故障]").arg(m_controllIp));
    //     jsonDoc.setObject(json);
    //     emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    //     emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataList, DeviceId)).toJson(), "light");
    //     return;
    // }

    //qDebug() << (sendDataList);

    while(!sendDataList.isEmpty()){
        // 将闪烁 和 亮度 和 颜色 命令发送，并休眠 10s
        if( sendDataList.first().toUpper().contains("FF 66 FF")
            || sendDataList.first().toUpper().contains("FF 77 FF")
            || sendDataList.first().toUpper().contains("FF 88 FF")
            || sendDataList.first().toUpper().contains("FF 40 FF"))
        {
            m_udpSocket->writeDatagram(QByteArray::fromHex(sendDataList.first().toLatin1()), QHostAddress(m_controllIp), m_controllPort);
            //m_udpSocket->waitForBytesWritten();
            emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp).arg(sendDataList.first()));

            QTimer::singleShot(1000, &eventloop, SLOT(quit()));
            eventloop.exec();
            sendDataList.removeFirst();
            continue;
        }

        for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
            tmp = tmp + sendDataList.first() + " ";
            sendDataList.removeFirst();
        }

        m_udpSocket->writeDatagram(QByteArray::fromHex(tmp.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //m_udpSocket->waitForBytesWritten();
        emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp).arg(tmp));
        //msleep(m_sendingInterval);

        QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
        eventloop.exec();
        m_udpSocket->writeDatagram(QByteArray::fromHex(tmp.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //m_udpSocket->waitForBytesWritten();
        //msleep(m_sendingInterval);

        QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
        eventloop.exec();
        m_udpSocket->writeDatagram(QByteArray::fromHex(tmp.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //m_udpSocket->waitForBytesWritten();

        QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
        eventloop.exec();
        m_udpSocket->writeDatagram(QByteArray::fromHex(tmp.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //m_udpSocket->waitForBytesWritten();

        QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
        eventloop.exec();
        m_udpSocket->writeDatagram(QByteArray::fromHex(tmp.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //m_udpSocket->waitForBytesWritten();

        tmp.clear();
    }
    json.insert("deviceState", "1");


    jsonDoc.setObject(json);
    emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataListTmp, DeviceId, TermIdSize)).toJson(), "light");
}

void lightControllWorker::SendDatagram2Udp(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList, int TermIdSize)
{
    QStringList sendDataListTmp = sendDataList;
    if(Luminance != -1) m_luminance = Luminance;
    if(FlickerList != "no") m_flicker = FlickerList;
    //1红 2绿 3蓝 4白 5黄 6青 7洋红 8黑 9橙
    switch(fontColor){
    case 1:
        m_currentColor = "红";
        break;
    case 2:
        m_currentColor = "绿";
        break;
    case 3:
        m_currentColor = "蓝";
        break;
    case 4:
        m_currentColor = "白";
        break;
    case 5:
        m_currentColor = "黄";
        break;
    case 6:
        m_currentColor = "青";
        break;
    case 7:
        m_currentColor = "洋";
        break;
    case 8:
        m_currentColor = "黑";
        break;
    case 9:
        m_currentColor = "橙";
        break;
    case -1:
        break;
    default:
        m_currentColor = "橙";
        break;
    }

    m_deviceId = DeviceId;
    m_contentStr = ContentStr;
    m_lastList = sendDataList;

    QString tmp;
    QJsonObject json;
    QJsonObject topic2Json;
    QJsonDocument jsonDoc;
    QEventLoop eventloop;
    QStringList colorCmdList;

    json.insert("stateId", m_deviceId);
    json.insert("deviceId", m_deviceId);
    json.insert("checkDate", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    json.insert("handleState", "1");

    if(ContentStr.isEmpty()) ContentStr = "关闭";
    json.insert("value", ContentStr);
    json.insert("source", "1");
    json.insert("color", m_currentColor);
    json.insert("light", m_luminance);
    json.insert("pl", m_flicker);


    //    判断是否在线
    // if(!connectControll()){
    //     json.insert("deviceState", "2");
    //     emit showMsg(QString("控制器:%1[网络故障]").arg(m_controllIp));
    //     jsonDoc.setObject(json);
    //     emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    //     emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataList, DeviceId)).toJson(), "light");
    //     return;
    // }

    for(int i=0; i<sendDataList.size(); i++){

        QString cmd = sendDataList.at(i);
        if(cmd.contains("FF 40")){
            m_udpSocket->writeDatagram(QByteArray::fromHex(cmd.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
            //m_udpSocket->waitForBytesWritten();
            emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp, cmd));
        }
    }

    //qDebug() << QString(" ******************* debug ******************* Version  %1");

    while(!sendDataList.isEmpty()){
        tmp.clear();
        for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
            QString firstData = sendDataList.first();
            if(!firstData.contains("FF 40")){
                tmp = tmp + firstData + " ";
            }
            sendDataList.removeFirst();
        }

        m_udpSocket->writeDatagram(QByteArray::fromHex(tmp.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //m_udpSocket->waitForBytesWritten();
        emit showMsg(QString("控制器:%1[%2]").arg(m_controllIp, tmp));
    }

    json.insert("deviceState", "1");
    jsonDoc.setObject(json);

    emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataListTmp, DeviceId, TermIdSize)).toJson(), "light");
}

QJsonObject lightControllWorker::getTopic2Json(QStringList sendDataList, QString DeviceId, int TermIdSize)
{
    QJsonObject json;
    QJsonArray jsonArray;
    QStringList list;

    while(!sendDataList.isEmpty()){
        // 将闪烁 和 亮度 和 颜色 命令发送，并休眠 10s
        if(    sendDataList.first().toUpper().contains("FF 66 FF")
            || sendDataList.first().toUpper().contains("FF 40 FF")
            || sendDataList.first().toUpper().contains("FF 77 FF")
            || sendDataList.first().toUpper().contains("FF 88 FF"))
        {
            sendDataList.removeFirst();
        }else{
            list << sendDataList.first();
            sendDataList.removeFirst();
        }
    }

    // // FF 88 FF D3 EA AA
    // int i = 1;
    // foreach(QString str, list){
    //     QStringList tmp = str.split(" ", Qt::SkipEmptyParts);
    //     QJsonObject jsonTmp;
    //     //jsonTmp.insert("device_id", DeviceId + QString("%1").arg(tmp.at(2).toInt(nullptr, 16), 3, 10, QLatin1Char('0')));
    //     jsonTmp.insert("device_id", DeviceId + QString("%1").arg(i++, 2, 10, QLatin1Char('0')));
    //     //qDebug() << DeviceId + QString("%1").arg(tmp.at(2).toInt(nullptr, 16), 3, 10, QLatin1Char('0'));
    //     if(tmp.at(3) + tmp.at(4) == "A0F0"){
    //         jsonTmp.insert("txt", "");
    //     }else{
    //         jsonTmp.insert("txt", hex2QStr(tmp.at(3) + tmp.at(4)));
    //     }
    //     jsonTmp.insert("state", "1");
    //     jsonTmp.insert("type", "1");
    //     jsonTmp.insert("pl", m_flicker);
    //     //qDebug() << "FlickerList: " << m_flicker;
    //     jsonTmp.insert("time", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    //     jsonArray << jsonTmp;
    // }

    //qDebug() << "TermIdSize: " << TermIdSize;
    //qDebug() << "list: " << list;

    for(int i=1; i<=TermIdSize; i++){
        //QStringList tmp = str.split(" ", Qt::SkipEmptyParts);
        QJsonObject jsonTmp;
        QStringList tmp;
        // if(list.size() > 0){
        //     tmp = list.at(0).split(" ", Qt::SkipEmptyParts);
        //     if(tmp.at(3) + tmp.at(4) == "A0F0"){
        //         jsonTmp.insert("txt", "");
        //     }else{
        //         jsonTmp.insert("txt", hex2QStr(tmp.at(3) + tmp.at(4)));
        //     }
        // }else{
        //     jsonTmp.insert("txt", "");
        // }

        if(list.size() == 1){
            tmp = list.at(0).split(" ", Qt::SkipEmptyParts);
            if(tmp.at(3) + tmp.at(4) == "A0F0"){
                jsonTmp.insert("txt", "");
            }else{
                jsonTmp.insert("txt", hex2QStr(tmp.at(3) + tmp.at(4)));
            }
        }else{
            tmp = list.at(i-1).split(" ", Qt::SkipEmptyParts);
            jsonTmp.insert("txt", hex2QStr(tmp.at(3) + tmp.at(4)));
        }
        //jsonTmp.insert("device_id", DeviceId + QString("%1").arg(tmp.at(2).toInt(nullptr, 16), 3, 10, QLatin1Char('0')));
        jsonTmp.insert("device_id", DeviceId + QString("%1").arg(i, 2, 10, QLatin1Char('0')));
        //qDebug() << DeviceId + QString("%1").arg(tmp.at(2).toInt(nullptr, 16), 3, 10, QLatin1Char('0'));

        jsonTmp.insert("state", "1");
        jsonTmp.insert("type", "1");
        jsonTmp.insert("pl", m_flicker);
        //qDebug() << "FlickerList: " << m_flicker;
        jsonTmp.insert("time", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        jsonArray << jsonTmp;
    }

    json.insert("roadId", "");
    json.insert("data", jsonArray);

    //qDebug() << "************************************ json : " << json;
    emit showMsg("************lightControllWorker::getTopic2Json: " + QJsonDocument(json).toJson());

    //qDebug() << QString("发文字时间:%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz"));
    return json;
}

QString lightControllWorker::hex2QStr(QString hex)
{
    hex.replace(" ", "");
    QString m_outstr;
    if(hex.isEmpty())
        return "";
    m_outstr.clear();
    m_outstr=hex.trimmed();
    QString temp;      //get 1 hex num
    QByteArray encodedString;  //store char code
    int i,n;
    n=m_outstr.length();
    for(i=2;i<=n;i+=2){
        temp=m_outstr.left(i);
        temp=temp.right(2);
        encodedString.append(QByteArray::fromHex(temp.toLatin1()));
    }
    m_outstr=QString::fromLocal8Bit(encodedString);
    return m_outstr;
}

void lightControllWorker::initTcpSocket()
{
    m_tcpSocket = new QTcpSocket(this);
    //connect(m_tcpSocket,SIGNAL(readyRead()), this, SLOT(slotReadyReadTcp()));
    //connect(m_tcpSocket, SIGNAL(disconnected()));
    connect(m_tcpSocket, &QTcpSocket::stateChanged, [this](){
        emit showMsg(QString("[%1] stateChanged to %2").arg(m_controllIp).arg(m_tcpSocket->state()));
    });
    connect(m_tcpSocket, &QTcpSocket::disconnected, [this](){
        emit showMsg(QString("[%1] disconnected!").arg(m_controllIp));
    });

}

void lightControllWorker::initUcpSocket()
{
    m_udpSocket = new QUdpSocket(this);
    //m_udpSocket->bind(8886);
    connect(m_udpSocket,SIGNAL(readyRead()), this, SLOT(slotReadyReadUdp()));

    //connect(m_tcpSocket, SIGNAL(disconnected()));
    // connect(m_tcpSocket, &QUdpSocket::stateChanged, [this](){
    //     emit showMsg(QString("[%1] stateChanged to %2").arg(m_controllIp).arg(m_tcpSocket->state()));
    // });
    // connect(m_tcpSocket, &QUdpSocket::disconnected, [this](){
    //     emit showMsg(QString("[%1] disconnected!").arg(m_controllIp));
    // });

}

void lightControllWorker::slotInit()
{
    initChenkTimer();
}

void lightControllWorker::slotSendDatagram(QStringList sendDataList, QString DeviceId, QString ContentStr, int version, int fontColor, int Luminance, QString FlickerList, int TermIdSize)
{
    if(version == 1){
        m_connectType == "TCP"
            ? SendDatagram1(sendDataList, DeviceId, ContentStr, Luminance, FlickerList, TermIdSize)
            : SendDatagram1Udp(sendDataList, DeviceId, ContentStr, Luminance, FlickerList, TermIdSize);

    }else if(version == 2){
        m_connectType == "TCP"
            ? SendDatagram2(sendDataList, DeviceId, ContentStr, fontColor, Luminance, FlickerList, TermIdSize)
            : SendDatagram2Udp(sendDataList, DeviceId, ContentStr, fontColor, Luminance, FlickerList, TermIdSize);

    }
}

void lightControllWorker::slotReadyReadTcp()
{
    QByteArray ba = m_tcpSocket->readAll().toHex();
    //m_tcpSocket->flush();
    //qDebug() << "*************ba: " << ba;
    QString str = ba.toUpper();
    int state = -1;
    //int state = -1;
    if(str.size() == 4){ // 查询结果
        if(str.at(0) == 'F'){
            if(str.at(1) == '5'){           // 查询控制板状态:
                if( str.at(3) == '5'){
                    state = QString(str.at(2)).toInt();
                    // 返回信息f5 x5两个字节, x=0灯关闭 x=1 灯亮   x=3灯亮且闪烁  x=4内部通讯故障
                    switch (state) {
                    case -1:
                        //m_checkResultList << "灯离线";
                        m_checkResultList << "5";
                        break;
                    case 0:
                        //m_checkResultList << "灯关闭";
                        m_checkResultList << "0";
                        break;
                    case 1:
                        //m_checkResultList << "灯亮";
                        m_checkResultList << "1";
                        break;
                    case 3:
                        //m_checkResultList << "灯亮且闪烁";
                        m_checkResultList << "3";
                        break;
                    case 4:
                        //m_checkResultList << "内部通讯故障";
                        m_checkResultList << "4";
                        break;
                    default:
                        break;
                    }
                    return;
                }
            }else if(str.at(1) == '6'){     // 查询控制板电源状态

            }else if(str.at(1) == 'a'){     // 轨迹跟踪延时时间查询
                m_pathTrackingDelay = QString(str.at(2)).toInt();
                emit signalUpdatePathTrackingStateJson(m_pathTrackingMode, m_pathTrackingDelay);
                return;
            }else if(str.at(1) == 'b'){     // 轨迹跟踪状态查询
                if( str.at(3) == '5'){
                    m_pathTrackingMode = QString(str.at(2)).toInt();
                    emit signalUpdatePathTrackingStateJson(m_pathTrackingMode, m_pathTrackingDelay);
                    return;
                }
            }
        }
    }
}

void lightControllWorker::slotReadyReadUdp()
{
    // qDebug() << "m_udpSocket->hasPendingDatagrams();";
    // qDebug() << m_udpSocket->readAll();
}

void lightControllWorker::slotSetIntervalAndCount(int sendingInterval, int sendingCount)
{
    m_sendingInterval = sendingInterval;
    m_sendingCount = sendingCount;
}

void lightControllWorker::slotConnectToControl()
{
    if(m_connectType == "TCP"){
        connectControll();
    }
}

void lightControllWorker::slotLightPowerOn(bool on)
{
    if(m_lightPowerOn == on) return;

    m_lightPowerOn = on;

    // 灯柱电源开关
    QString cmd = on ? CMD_POWER_ON : CMD_POWER_OFF;

    if(on){
        //qDebug() << QString("开电时间:%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz"));
        emit showMsg(QString("[%1]  控制器:%2[%3]  开电").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")).arg(m_controllIp).arg(cmd));
    }else{
        //qDebug() << QString("关电时间:%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz"));
        emit showMsg(QString("[%1]  控制器:%2[%3]  关电").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")).arg(m_controllIp).arg(cmd));
    }

    if(m_connectType == "TCP"){
        m_tcpSocket->write(QByteArray::fromHex(cmd.toLatin1()));
        m_tcpSocket->waitForBytesWritten();
    }else{
        m_udpSocket->writeDatagram(QByteArray::fromHex(cmd.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
    }

    QThread::msleep(500);

}

void lightControllWorker::slotOpenPathTracking(int mode)
{
    // 轨迹跟踪 0 - 关闭; 1 - 模式1; 2 - 模式2

    QString cmd;

    switch(mode){
    case 0:     // 0 - 关闭
        cmd = QString(CMD_PATH_TRACKING_OFF).arg("FF");
        break;
    case 1:     // 1 - 模式1
        cmd = QString(CMD_PATH_TRACKING_ON_1).arg("FF");
        break;
    case 2:     // 2 - 模式2
        cmd = QString(CMD_PATH_TRACKING_ON_2).arg("FF");
        break;
    default:
        break;
    }

    if(m_connectType == "TCP"){
        m_tcpSocket->write(QByteArray::fromHex(cmd.toLatin1()));
        m_tcpSocket->waitForBytesWritten();
    }else{
        m_udpSocket->writeDatagram(QByteArray::fromHex(cmd.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
    }

    //qDebug() << "轨迹:    " << cmd;
    QThread::msleep(500);
}

void lightControllWorker::slotCheckLightState(QStringList idlist)
{
    emit signalIsCheckingLightState(true);

    m_checkIdList = idlist;
    //qDebug() << " m_checkIdList : " << m_checkIdList;

    m_checkResultList.clear();  // 查询灯状态返回的结果列表
    //m_checkIdList.clear();      // 查询灯状态的ID列表
    m_checkRCmdList.clear();

    QString cmd;
    int idCount = idlist.size();

    for(int i=0; i<idCount; i++){
        // if(i != 0)
        //     m_checkResultList << m_checkResultListTmp;
        cmd = QString(CMD_STATUS_QUERY_1).arg(idlist.at(i).toInt(), 2, 16, QLatin1Char('0'));
        //qDebug() << "cmd : " << cmd;

        m_checkRCmdList << cmd;

        // if(m_connectType == "TCP"){
        //     m_tcpSocket->write(QByteArray::fromHex(cmd.toLatin1()));
        //     m_tcpSocket->waitForBytesWritten();
        // }else{
        //     m_udpSocket->writeDatagram(QByteArray::fromHex(cmd.toLatin1()), QHostAddress(m_controllIp), m_controllPort);
        //     qDebug() << cmd;
        // }

        // emit signalUpdateProgress(QString("%1/%2").arg(i).arg(idCount));
        // slotReadyReadTcp();

        /// QThread::msleep(1000);
        // slotReadyReadTcp();
    }

    m_checkTimer->start();

    // m_checkResultList << m_checkResultListTmp;

    // int ResultListSize = m_checkResultList.size();
    // int IdListSize = m_checkIdList.size();

    // ResultListSize = ResultListSize < IdListSize ? ResultListSize : IdListSize;

    // for(int i=0; i<ResultListSize; i++){
    //     qDebug() << QString("ID [ %1 ]  res [ %2 ]").arg(m_checkIdList.at(i)).arg(m_checkResultList.at(i));
    // }

    // qDebug() << "m_checkIdList: " << m_checkIdList;
    // qDebug() << "m_checkResultList: " << m_checkResultList;

    // emit signalIsCheckingLightState(false);

}

void lightControllWorker::slotCheckPathTrackingState()
{
    // qDebug() << "QByteArray::fromHex(QString(CMD_STATUS_QUERY_3).toLatin1()): " << QByteArray::fromHex(QString(CMD_STATUS_QUERY_3).toLatin1());
    if(m_pathTrackingFlag != 0) return;

    if(m_connectType == "TCP"){
        m_tcpSocket->write(QByteArray::fromHex(QString(CMD_STATUS_QUERY_3).toLatin1()));
        m_tcpSocket->waitForBytesWritten();
    }else{
        m_udpSocket->writeDatagram(QByteArray::fromHex(QString(CMD_STATUS_QUERY_3).toLatin1()), QHostAddress(m_controllIp), m_controllPort);
    }
    m_pathTrackingFlag = 2;
    m_checkTimer->start();
}

void lightControllWorker::slotTest(QByteArray ba)
{
    // qDebug() << "**************************" ;
    m_tcpSocket->write(ba);
    m_tcpSocket->waitForBytesWritten();
}

void lightControllWorker::initChenkTimer()
{
    connect(this, &lightControllWorker::signalTest, this, &lightControllWorker::slotTest);
    m_checkTimer = new QTimer;
    m_checkTimer->setInterval(1000);
    connect(m_checkTimer, &QTimer::timeout, this, [this](){
        // 轨迹状态查询
        if(m_pathTrackingFlag == 2){
            slotReadyReadTcp();
            m_pathTrackingFlag = 1;

            if(m_connectType == "TCP"){
                m_tcpSocket->write(QByteArray::fromHex(QString(CMD_STATUS_QUERY_5).toLatin1()));
                m_tcpSocket->waitForBytesWritten();
            }else{
                m_udpSocket->writeDatagram(QByteArray::fromHex(QString(CMD_STATUS_QUERY_5).toLatin1()), QHostAddress(m_controllIp), m_controllPort);
            }

            return;
        }else if(m_pathTrackingFlag == 1){
            slotReadyReadTcp();
            m_pathTrackingFlag = 0;
            m_checkTimer->stop();
            return;
        }


        // 灯状态查询
        if(m_checkIndex > 0){
            slotReadyReadTcp();
        }

        if(m_checkIndex == m_checkIdList.size()){
            m_checkIndex = 0;

            //qDebug() <<" m_checkIdList : " << m_checkIdList;
            //qDebug() <<" m_checkResultList : " << m_checkResultList;

            m_checkTimer->stop();
            emit signalUpdateLightStateJson(m_checkIdList, m_checkResultList);
            emit signalIsCheckingLightState(false);
            return;
        }

        if(m_checkIndex < m_checkRCmdList.size()){
            if(m_connectType == "TCP"){
                m_tcpSocket->write(QByteArray::fromHex(m_checkRCmdList.at(m_checkIndex).toLatin1()));
                m_tcpSocket->waitForBytesWritten();
            }else{
                m_udpSocket->writeDatagram(QByteArray::fromHex(m_checkRCmdList.at(m_checkIndex).toLatin1()), QHostAddress(m_controllIp), m_controllPort);
            }
            m_checkIndex++;
            emit signalUpdateProgress(QString(" %1 : %2/%3 ").arg(m_controllIp).arg(m_checkIndex).arg(m_checkIdList.size()));
        }
    });

}

void lightControllWorker::initWatchTcpReceive()
{
    m_watchTcpReceive = new QTimer();
    m_watchTcpReceive->setInterval(250);
    connect(m_watchTcpReceive, &QTimer::timeout, this, [=]{

    });
    m_watchTcpReceive->start();
}
