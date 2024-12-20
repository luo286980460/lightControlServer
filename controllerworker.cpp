#include "controllerworker.h"

#include <QDateTime>
#include <QTimer>
#include <QEventLoop>

ControllerWorker::ControllerWorker(QObject *parent)
    : QObject{parent}
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

void ControllerWorker::slotInitWorker()
{

}

void ControllerWorker::slotInitTcp()
{
    m_tcpSocket = new QTcpSocket(this);
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
    //m_tcpSocket->flush();
    qDebug() << "*************ba: " << ba;
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
                        //m_checkResultList << "5";
                        break;
                    case 0:
                        //m_checkResultList << "灯关闭";
                        //m_checkResultList << "0";
                        break;
                    case 1:
                        //m_checkResultList << "灯亮";
                        //m_checkResultList << "1";
                        break;
                    case 3:
                        //m_checkResultList << "灯亮且闪烁";
                        //m_checkResultList << "3";
                        break;
                    case 4:
                        //m_checkResultList << "内部通讯故障";
                        //m_checkResultList << "4";
                        break;
                    default:
                        break;
                    }
                    return;
                }
            }else if(str.at(1) == '6'){     // 查询控制板电源状态

            }else if(str.at(1) == 'a'){     // 轨迹跟踪延时时间查询
                //m_PathTrackingTime = QString(str.at(2)).toInt();
                //emit signalUpdatePathTrackingStateJson(m_PathTracking, m_PathTrackingTime);
                return;
            }else if(str.at(1) == 'b'){     // 轨迹跟踪状态查询
                if( str.at(3) == '5'){
                    //m_PathTracking = QString(str.at(2)).toInt();
                    //emit signalUpdatePathTrackingStateJson(m_PathTracking, m_PathTrackingTime);
                    return;
                }
            }
        }
    }
}

void ControllerWorker::slotReadyReadUdp()
{
    qDebug() << "m_udpSocket->hasPendingDatagrams();";
    qDebug() << m_udpSocket->readAll();
}
