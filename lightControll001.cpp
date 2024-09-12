#include <QEventLoop>
#include "lightControll.h"

lightControll::lightControll(QString controllIp, int controllPort, QThread *parent)
    : QThread(parent)
    , m_controllIp(controllIp)
    , m_controllPort(controllPort)
    , m_sendingInterval(500)
    , m_sendingCount(5)
    , m_runFlag(true)
    , m_sendFlag(false)
{

}

lightControll::~lightControll()
{

}

void lightControll::run()
{
    //初始化TCP客户端
    m_tcpClient = new QTcpSocket();   //实例化tcpClient
    m_tcpClient->abort();                 //取消原有连接
    connect(m_tcpClient, SIGNAL(readyRead()), this, SLOT(ReadData()));

    /*m_timer.setInterval(5*60*1000);
    connect(&m_timer, &QTimer::timeout, this, [this]{
        sendDataTcp(m_sendDataList);
    });*/

    if(connectControll()){
        emit showMsg(QString("控制器：%1 --> 连接成功").arg(m_controllIp));
        sendDataTcp(m_sendDataList);    //发送数据
        //msleep(m_sendingInterval);
        //sendDataTcp(m_sendDataList);    //发送数据
        //msleep(m_sendingInterval);
        //sendDataTcp(m_sendDataList);    //发送数据

        disconnectControll();
    }else{
        emit showMsg(QString("控制器：%1 --> 连接失败").arg(m_controllIp));
    }

    m_tcpClient->deleteLater();
}

bool lightControll::connectControll()
{
    m_tcpClient->connectToHost(m_controllIp, m_controllPort);
    m_tcpClient->setSocketOption(QTcpSocket::KeepAliveOption, 1);

    if (m_tcpClient->waitForConnected(1000))  // 连接
    {
        return true;
    }else{
        return false;
    }
}

void lightControll::disconnectControll()
{
    if (m_tcpClient->state() == QAbstractSocket::ConnectedState)
        m_tcpClient->disconnectFromHost();
    if (m_tcpClient->state() == QAbstractSocket::UnconnectedState \
            || m_tcpClient->waitForDisconnected(1000))  //已断开连接则进入if{}
    {
        qDebug() << "连接已断开";
    }
}

void lightControll::sendDataTcp(QStringList sendDataList)
{
    QString tmp;
    //if(m_timer.isActive()) m_timer.stop();

    if(m_tcpClient){
        while(!sendDataList.isEmpty()){
            for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
                tmp = tmp + sendDataList.first() + " ";
                sendDataList.removeFirst();
            }
            m_tcpClient->write(QByteArray::fromHex(tmp.toLatin1()));
            //QEventLoop eventloop;
            //QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            //eventloop.exec();
            m_tcpClient->waitForBytesWritten();
            msleep(m_sendingInterval);

            m_tcpClient->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpClient->waitForBytesWritten();
            msleep(m_sendingInterval);

            m_tcpClient->write(QByteArray::fromHex(tmp.toLatin1()));
            m_tcpClient->waitForBytesWritten();
            emit showMsg( QString("控制器：%1[%2]").arg(m_controllIp).arg(tmp));
            tmp.clear();
        }
    }
    //m_timer.start();
    m_sendFlag = false;
}

void lightControll::sendDataUART(QSerialPort *m_serialPort, QStringList sendDataList)
{
    QString tmp;
    if(m_serialPort){
        while(!sendDataList.isEmpty()){
            for(int i = 0; i<m_sendingCount && !sendDataList.isEmpty() ; i++){
                tmp = tmp + sendDataList.first() + " ";
                sendDataList.removeFirst();
            }
            m_serialPort->write(QByteArray::fromHex(tmp.toLatin1()));
            QEventLoop eventloop;
            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_serialPort->write(QByteArray::fromHex(tmp.toLatin1()));
            QTimer::singleShot(m_sendingInterval, &eventloop, SLOT(quit()));
            eventloop.exec();
            m_serialPort->write(QByteArray::fromHex(tmp.toLatin1()));
            emit showMsg(QString("控制器：%1[%2]").arg(m_controllIp).arg(tmp));
            tmp.clear();
        }
    }
}

void lightControll::ReadData()
{
    QByteArray buffer = m_tcpClient->readAll();
        if(!buffer.isEmpty())
        {
            qDebug() << "ReadData: " << buffer;
        }

}

void lightControll::ReadError(QAbstractSocket::SocketError error)
{
    qDebug() << "last error" << error;
}
