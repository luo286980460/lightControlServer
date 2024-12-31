#include "controllerworker.h"

#include <QDateTime>
#include <QTimer>
#include <QEventLoop>
#include <QJsonDocument>

ControllerWorker::ControllerWorker(QString ip, int port, int sendingInterval, int sendingCount, QString ConnectType, QObject *parent)
    : QObject{parent}
    , m_sendingInterval(sendingInterval)
    , m_sendingCount(sendingCount)
    , m_ConnectType(ConnectType)
    , m_ControllerIp(ip)
    , m_ControllerPort(port)
{

}

void ControllerWorker::boadCast(QStringList cmdList)
{
    QEventLoop eventloop;
    while(cmdList.size() > 0){
        m_tcpSocket->write(QByteArray::fromHex(cmdList.first().toLatin1()));
        QTimer::singleShot(1000, &eventloop, SLOT(quit()));
        eventloop.exec();
        cmdList.removeFirst();
    }
}

void ControllerWorker::boadCastNot(QStringList cmdList)
{
    while(cmdList.size() > 0){
        QString cmd;
        for(int i = 0; i<m_sendingCount && !cmdList.isEmpty() ; i++){
            cmd += (cmdList.first() + " ");
            cmdList.removeFirst();
        }
        m_tcpSocket->write(QByteArray::fromHex(cmd.toLatin1()));
    }
}

int ControllerWorker::getLightIdFromCmd(QString cmd)
{
    QStringList strList= cmd.toUpper().split(" ");
    if(strList.size() != 6) return -1;

    return strList.at(2).toInt(nullptr, 16);
}

void ControllerWorker::initCheckTimer()
{
    m_checkTimer = new QTimer;
    m_checkTimer->setInterval(250);

    connect(m_checkTimer, &QTimer::timeout, this, [=]{

        //qDebug() << "m_cmdList: " << m_cmdList;

        if(workMode == 1){              // 控灯模式
            sendCmd2Controller();
            workMode = 2;

        }else if(workMode ==2){         // 查询模式
            // 是否在等数据返回
            if(waitForData > 0){

                if(m_ConnectType == "TCP"){
                    slotReadyReadTcp();
                }else{
                    slotReadyReadUdp();
                }
                if(waitForData > 0 && waitForData <= 1000){
                    return;
                }else{
                    waitForData = 0;
                    if(m_cmdCheckState.isEmpty() && m_cmdCheckPowerState.isEmpty()
                        && m_cmdCheckPathTrackingDelay.isEmpty() && m_cmdCheckPathTrackingMode.isEmpty()){
                        emit signalWrite2Kafka();
                    }
                }
            }


            // 当前是什么查询状态

            QStringList* cmdList = nullptr;
            QString cmd;
            switch(m_checkstate){
            case 0:
                break;
            case 1:
                // 需要查1
                if(!m_cmdCheckState.isEmpty()){
                    cmdList = &m_cmdCheckState;
                }
                break;
            case 2:
                // 需要查2
                if(!m_cmdCheckPowerState.isEmpty()){
                    cmdList = &m_cmdCheckPowerState;
                }
            case 3:
                // 需要查3
                if(!m_cmdCheckPathTrackingDelay.isEmpty()){
                    cmdList = &m_cmdCheckPathTrackingDelay;
                }
                break;
            case 4:
                // 需要查4
                if(!m_cmdCheckPathTrackingMode.isEmpty()){
                    cmdList = &m_cmdCheckPathTrackingMode;
                }
                break;
            case 5:
                if(!m_cmdCheckState.isEmpty()){
                    cmdList = &m_cmdCheckState;
                }else if(!m_cmdCheckPowerState.isEmpty()){
                    cmdList = &m_cmdCheckPowerState;
                }else if(!m_cmdCheckPathTrackingDelay.isEmpty()){
                    cmdList = &m_cmdCheckPathTrackingDelay;
                }
                break;
            default:
                break;
            }

            if(cmdList){
                cmd = cmdList->first();
                cmdList->removeFirst();
                currentCheckLightId = getLightIdFromCmd(cmd);
                m_tcpSocket->write(QByteArray::fromHex(cmd.toLatin1()));

                emit showMsg(QString("控制器:%1[%2]").arg(m_ControllerIp).arg(cmd));
                waitForData = 250;
            }else{
                m_checkstate = 0;
            }
        }
    });

    m_checkTimer->start();
}

void ControllerWorker::sendCmd2Controller()
{
    QString tmp;
    QEventLoop eventloop;

    //qDebug() << m_cmdList;
    if(m_tcpSocket && m_tcpSocket->state() == QAbstractSocket::ConnectedState){
        //qDebug() << m_tcpSocket->state();
        while(!m_cmdList.isEmpty()){
            // 将闪烁 和 亮度 和 颜色 命令发送，并休眠 1s
            if(    m_cmdList.first().toUpper().contains("FF 66 FF")
                || m_cmdList.first().toUpper().contains("FF 77 FF")
                || m_cmdList.first().toUpper().contains("FF 88 FF")
                || m_cmdList.first().toUpper().contains("FF 40 FF")  )
            {

                m_tcpSocket->write(QByteArray::fromHex(m_cmdList.first().toLatin1()));
                m_tcpSocket->waitForBytesWritten();
                emit showMsg(QString("控制器:%1[%2]").arg(m_ControllerIp).arg(m_cmdList.first()));

                QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
                eventloop.exec();
                m_cmdList.removeFirst();
                continue;
            }

            for(int i = 0; i<m_sendingCount && !m_cmdList.isEmpty() ; i++){
                tmp = tmp + m_cmdList.first() + " ";
                m_cmdList.removeFirst();
            }

            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();
            //msleep(m_sendingInterval);

            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_tcpSocket->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpSocket->waitForBytesWritten();
            //msleep(m_sendingInterval);

            emit showMsg(QString("控制器:%1[%2]").arg(m_ControllerIp).arg(tmp));
            tmp.clear();
        }
    }
}

void ControllerWorker::slotInitWorker()
{
    initCheckTimer();
}

void ControllerWorker::slotInitTcp(QString ip, int port)
{
    m_tcpSocket = new QTcpSocket(this);

    emit showMsg(QString("控制器:%1:%2[正在连接]").arg(ip).arg(port));
    m_tcpSocket->connectToHost(ip, port);
    m_tcpSocket->setSocketOption(QTcpSocket::KeepAliveOption, 1);

    if (m_tcpSocket->waitForConnected(1000))  // 连接
    {
        emit showMsg(QString("控制器【%1:%2】连接成功").arg(ip).arg(port));
        return;
    }else{
        emit showMsg(QString("控制器【%1:%2】连接失败").arg(ip).arg(port));
        return;
    }


    //connect(m_tcpSocket,SIGNAL(readyRead()), this, SLOT(slotReadyReadTcp()));
    //connect(m_tcpSocket, SIGNAL(disconnected()));
    // connect(m_tcpSocket, &QTcpSocket::stateChanged, this, [this](){
    //     emit showMsg(QString("[%1] stateChanged to %2").arg(m_ControllerIpPort).arg(m_tcpSocket->state()));
    // });
    // connect(m_tcpSocket, &QTcpSocket::disconnected, this, [this](){
    //     emit showMsg(QString("[%1] disconnected!").arg(m_ControllerIpPort));
    // });
}

void ControllerWorker::slotInitUdp()
{
    m_udpSocket = new QUdpSocket(this);

    //connect(m_udpSocket,SIGNAL(readyRead()), this, SLOT(slotReadyReadUdp()));

    //connect(m_tcpSocket, SIGNAL(disconnected()));
    // connect(m_tcpSocket, &QUdpSocket::stateChanged, [this](){
    //     emit showMsg(QString("[%1] stateChanged to %2").arg(m_controllIp).arg(m_tcpSocket->state()));
    // });
    // connect(m_tcpSocket, &QUdpSocket::disconnected, [this](){
    //     emit showMsg(QString("[%1] disconnected!").arg(m_controllIp));
    // });
}

void ControllerWorker::slotReadyReadTcp()
{
    QByteArray ba = m_tcpSocket->readAll().toHex();
    //qDebug() << "*************ba: " << ba;
    QString str;
    QString msg;

    str = ba.toUpper();

    // 没有数据
    if(str.size() != 4 && str.size() != 2){
        waitForData += 250;
        if(waitForData > 1000){
            qDebug() << "ip: " << m_ControllerIp << "   id : " << currentCheckLightId << "  状态: 通信失败";
            emit signalLightIsOff(currentCheckLightId);
        }
        return;
    }

    int state;
    if(str.left(2) == "F5"){
        state = QString(str.at(2)).toInt();
        switch (state) {
        case 0:
            msg = "灯关闭";
            emit signalLightIsOff(currentCheckLightId);
            break;
        case 1:
            msg = "灯亮";
            break;
        case 3:
            msg = "灯亮且闪烁";
            break;
        case 4:
            emit signalLightIsOff(currentCheckLightId);
            msg = "内部通讯故障";
            break;
        default:
            break;
        }
        qDebug() << "id : " << currentCheckLightId << "  状态: " << msg;
        waitForData = 0;
    }else if(str.left(2) == "F6"){

    }else if(str.left(2) == "FB"){
        state = str.right(2).toInt(nullptr, 16) / 10;
        qDebug() << "id : " << currentCheckLightId << "  轨迹跟踪延时: " << state;
        waitForData = 0;
        return;
    }

}

void ControllerWorker::slotReadyReadUdp()
{
    // qDebug() << "m_udpSocket->hasPendingDatagrams();";
    //qDebug() << m_udpSocket->readAll();
}

void ControllerWorker::slotCmd2Controller(QStringList cmdList)
{
    m_cmdList = cmdList;
    workMode = 1;
}

void ControllerWorker::slotFlushAutoCheckCmd(QStringList cmdCheckState, QStringList cmdCheckPowerState, QStringList cmdCheckPathTrackingDelay)
{
    m_cmdCheckState = cmdCheckState;
    m_cmdCheckPowerState = cmdCheckPowerState;
    m_cmdCheckPathTrackingDelay = cmdCheckPathTrackingDelay;
}

void ControllerWorker::slotSendControlCmd(QStringList cmdList)
{
    m_cmdList = cmdList;
    workMode = 1;

    //qDebug() << m_ControllerIp << " *** " << m_cmdList;
}

void ControllerWorker::slotSendCheckCmd(QStringList cmdList)
{
    m_cmdCheckState = cmdList;
    m_checkstate = 1;
    // workMode = 1;

    //qDebug() << "slotSendCheckCmd:  " << cmdList;

}
