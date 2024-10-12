#include <QEventLoop>
#include <QTimer>
#include <QThread>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>
#include "lightcontrollworkerUDP.h"

lightControllWorkerUDP::lightControllWorkerUDP(QString topic, QString ip, int port, int sendingInterval,
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
{
    m_udpSocket = new QUdpSocket(this);
    connect(m_udpSocket,SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

}

lightControllWorkerUDP::~lightControllWorkerUDP()
{
    if(m_udpSocket)
    {
        delete m_udpSocket;
    }
}

bool lightControllWorkerUDP::connectControll()
{
    emit showMsg(QString("控制器：%1:%2[正在连接]").arg(m_controllIp).arg(m_controllPort));
    m_udpSocket->connectToHost(m_controllIp, m_controllPort);
    //m_udpSocket->setSocketOption(QTcpSocket::KeepAliveOption, 1);

    if (m_udpSocket->waitForConnected(1000))  // 连接
    {
        emit showMsg(QString("控制器【%1：%2】连接成功").arg(m_controllIp).arg(m_controllPort));
        return true;
    }else{
        emit showMsg(QString("控制器【%1：%2】连接失败").arg(m_controllIp).arg(m_controllPort));
        return false;
    }
}

void lightControllWorkerUDP::SendDatagram1(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList)
{
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

    if(m_udpSocket && m_udpSocket->state() != QAbstractSocket::ConnectedState){
        qDebug() << m_udpSocket->state();

        if(!connectControll()){
            json.insert("deviceState", "2");
            emit showMsg(QString("控制器：%1[网络故障]").arg(m_controllIp));
            jsonDoc.setObject(json);
            emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
            emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataList, DeviceId)).toJson(), "light");
            return;
        }
    }

    //qDebug() << (sendDataList);

    if(m_udpSocket && m_udpSocket->state() == QAbstractSocket::ConnectedState){
        qDebug() << m_udpSocket->state();
        while(!sendDataList.isEmpty()){
            // 将闪烁 和 亮度 和 颜色 命令发送，并休眠 10s
            if(    sendDataList.first().toUpper().contains("FF 66 FF")
                || sendDataList.first().toUpper().contains("FF 77 FF")
                || sendDataList.first().toUpper().contains("FF 88 FF")
                || sendDataList.first().toUpper().contains("FF 40 FF")  )
            {

                m_udpSocket->write(QByteArray::fromHex(sendDataList.first().toLatin1()));
                m_udpSocket->waitForBytesWritten();
                emit showMsg(QString("控制器：%1[%2]").arg(m_controllIp).arg(sendDataList.first()));

                QTimer::singleShot(1000, &eventloop, SLOT(quit()));
                eventloop.exec();
                sendDataList.removeFirst();
                continue;
            }

            for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
                tmp = tmp + sendDataList.first() + " ";
                sendDataList.removeFirst();
            }

            m_udpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_udpSocket->waitForBytesWritten();
            emit showMsg(QString("控制器：%1[%2]").arg(m_controllIp).arg(tmp));
            //msleep(m_sendingInterval);

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_udpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_udpSocket->waitForBytesWritten();
            //msleep(m_sendingInterval);

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_udpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_udpSocket->waitForBytesWritten();

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_udpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_udpSocket->waitForBytesWritten();

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_udpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_udpSocket->waitForBytesWritten();

            tmp.clear();
        }
        json.insert("deviceState", "1");
    }

    jsonDoc.setObject(json);
    emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataList, DeviceId)).toJson(), "light");
}

void lightControllWorkerUDP::SendDatagram2(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList)
{
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


    if(m_udpSocket && m_udpSocket->state() != QAbstractSocket::ConnectedState){
        if(!connectControll()){
            json.insert("deviceState", "2");
            emit showMsg(QString("控制器：%1[网络故障]").arg(m_controllIp));
            jsonDoc.setObject(json);
            emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
            emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataList, DeviceId)).toJson(), "light");
            return;
        }
    }

    if(m_udpSocket && m_udpSocket->state() == QAbstractSocket::ConnectedState){

        for(int i=0; i<sendDataList.size(); i++){
            QString cmd = sendDataList.at(i);
            if(cmd.contains("FF 40")){
                m_udpSocket->write(QByteArray::fromHex(cmd.toLatin1()));
                m_udpSocket->waitForBytesWritten();
                emit showMsg(QString("控制器：%1[%2]").arg(m_controllIp, cmd));
                sendDataList.removeAt(i);
            }
        }

        while(!sendDataList.isEmpty()){
            tmp.clear();
            for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
                QString firstData = sendDataList.first();
                tmp = tmp + firstData + " ";
                sendDataList.removeFirst();
            }

            m_udpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_udpSocket->waitForBytesWritten();
            emit showMsg(QString("控制器：%1[%2]").arg(m_controllIp, tmp));
        }
        json.insert("deviceState", "1");
    }

    jsonDoc.setObject(json);

    emit write2Kafka(m_topic, jsonDoc.toJson(), "light");
    emit write2Kafka(m_topic2, QJsonDocument(getTopic2Json(sendDataList, DeviceId)).toJson(), "light");
}

QJsonObject lightControllWorkerUDP::getTopic2Json(QStringList sendDataList, QString DeviceId)
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

    // FF 88 FF D3 EA AA
    foreach(QString str, list){
        QStringList tmp = str.split(" ", Qt::SkipEmptyParts);
        QJsonObject jsonTmp;
        jsonTmp.insert("device_id", DeviceId + QString("%1").arg(tmp.at(2).toInt(nullptr, 16), 3, 10, QLatin1Char('0')));
        //qDebug() << DeviceId + QString("%1").arg(tmp.at(2).toInt(nullptr, 16), 3, 10, QLatin1Char('0'));
        if(tmp.at(3) + tmp.at(4) == "A0F0"){
            jsonTmp.insert("txt", "");
        }else{
            jsonTmp.insert("txt", hex2QStr(tmp.at(3) + tmp.at(4)));
        }
        jsonTmp.insert("state", "1");
        jsonTmp.insert("type", "1");
        jsonTmp.insert("pl", m_flicker);
        qDebug() << "FlickerList: " << m_flicker;
        jsonTmp.insert("time", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        jsonArray << jsonTmp;
    }

    json.insert("roadid", "");
    json.insert("data", jsonArray);

    return json;
}

QString lightControllWorkerUDP::hex2QStr(QString hex)
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

void lightControllWorkerUDP::slotSendDatagram(QStringList sendDataList, QString DeviceId, QString ContentStr, int version, int fontColor, int Luminance, QString FlickerList)
{
    if(version == 1){
        SendDatagram1(sendDataList, DeviceId, ContentStr, Luminance, FlickerList);
    }else if(version == 2){
        SendDatagram2(sendDataList, DeviceId, ContentStr, fontColor, Luminance, FlickerList);
    }
}

void lightControllWorkerUDP::slotReadyRead()
{
    //emit sigReceiveData(m_udpSocket->readAll());
}

void lightControllWorkerUDP::slotSetIntervalAndCount(int sendingInterval, int sendingCount)
{
    m_sendingInterval = sendingInterval;
    m_sendingCount = sendingCount;
}

void lightControllWorkerUDP::slotConnectToControl()
{
    connectControll();
}
