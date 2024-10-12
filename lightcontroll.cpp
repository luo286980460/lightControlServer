#include "lightcontroll.h"
#include "lightcontrollworker.h"

lightcontroll::lightcontroll(QString connectType, QString topic, QString ip, int port, int sendingInterval,
                              int sendingCount, QString version, QObject *parent)
    : QObject{parent}
    , m_controllIp(ip)                      //控制器 ip
    , m_controllPort(port)                  //控制器 port
    , m_sendingInterval(sendingInterval)    //单位 ms
    , m_sendingCount(sendingCount)          //发送数量
    , m_topic(topic)
    , m_version(version)
{
    m_work = new lightControllWorker(connectType, m_topic, ip, port, m_sendingInterval, m_sendingCount, version);
    m_work->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);

    connect(m_work,SIGNAL(showMsg(QString)), this, SIGNAL(showMsg(QString)));
    connect(this,&lightcontroll::sigSendDatagram, m_work,&lightControllWorker::slotSendDatagram);

    connect(m_work,SIGNAL(sigReceiveData(QByteArray)), this, SLOT(slotReceiveTcpData(QByteArray)));
    connect(this, &lightcontroll::siglSetIntervalAndCount, m_work, &lightControllWorker::slotSetIntervalAndCount);
    connect(this, SIGNAL(sigConnectToControl()), m_work, SLOT(slotConnectToControl()));
    connect(m_work,SIGNAL(write2Kafka(QString,QString,QString)), this, SIGNAL(write2Kafka(QString,QString,QString)));
}

lightcontroll::~lightcontroll()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void lightcontroll::start()
{
    m_workerThread.start();
}

void lightcontroll::stop()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

QString lightcontroll::getControllIp()
{
    return m_controllIp;
}

int lightcontroll::getControllPort()
{
    return m_controllPort;
}

void lightcontroll::slotReceiveTcpData(QByteArray msg){
    emit showMsg(msg);
    return;
}
