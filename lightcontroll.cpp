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
    , m_progress("0/0")
{
    m_work = new lightControllWorker(connectType, m_topic, ip, port, m_sendingInterval, m_sendingCount, version);
    m_work->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);

    connect(this,&lightcontroll::signalInitWorker, m_work,&lightControllWorker::slotInit);
    connect(m_work,SIGNAL(showMsg(QString)), this, SIGNAL(showMsg(QString)));
    connect(this,&lightcontroll::sigSendDatagram, m_work,&lightControllWorker::slotSendDatagram);

    connect(m_work,SIGNAL(sigReceiveData(QByteArray)), this, SLOT(slotReceiveTcpData(QByteArray)));
    connect(this, &lightcontroll::siglSetIntervalAndCount, m_work, &lightControllWorker::slotSetIntervalAndCount);
    connect(this, SIGNAL(sigConnectToControl()), m_work, SLOT(slotConnectToControl()));
    connect(m_work,SIGNAL(write2Kafka(QString,QString,QString)), this, SIGNAL(write2Kafka(QString,QString,QString)));
    connect(this,&lightcontroll::signalLightPowerOn, m_work,&lightControllWorker::slotLightPowerOn);
    connect(this,&lightcontroll::signalOpenPathTracking, m_work,&lightControllWorker::slotOpenPathTracking);
    connect(this,&lightcontroll::signalCheckLightState, m_work,&lightControllWorker::slotCheckLightState);
    connect(m_work,&lightControllWorker::signalIsCheckingLightState, this,&lightcontroll::slotIsCheckingLightState);
    connect(m_work,&lightControllWorker::signalUpdateProgress, this,&lightcontroll::slotUpdateProgress);
    connect(m_work,&lightControllWorker::signalUpdateLightStateJson, this,&lightcontroll::slotUpdateLightStateJson);
    connect(this,&lightcontroll::signalCheckPathTrackingState, m_work,&lightControllWorker::slotCheckPathTrackingState);
}

lightcontroll::~lightcontroll()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void lightcontroll::start()
{
    m_workerThread.start();
    signalInitWorker();
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

bool lightcontroll::getCheckLightState(QString& progress)
{
    progress = m_progress;
    return m_checkLightState;
}

QJsonObject lightcontroll::getLightState()
{
    //m_lightStateJson = new QJsonObject;
    if(m_lightStateJson) return *m_lightStateJson;
    return QJsonObject();
}

QJsonObject lightcontroll::getPathTrackingState()
{
    return m_pathTrackingStateJson;
}

void lightcontroll::slotReceiveTcpData(QByteArray msg){
    emit showMsg(msg);
    return;
}

void lightcontroll::slotIsCheckingLightState(bool b)
{
    m_checkLightState = b;
    if(!m_checkLightState){
        m_progress = "0/0";
    }
}

void lightcontroll::slotUpdateProgress(QString progress)
{
    m_progress = progress;
}

void lightcontroll::slotUpdateLightStateJson(QStringList checkIdList, QStringList checkResultListTmp)
{
    if(m_lightStateJson) delete(m_lightStateJson);
    m_lightStateJson = new QJsonObject;

    for(int i=0; i<checkIdList.size(); i++){
        m_lightStateJson->insert(checkIdList.at(i), checkResultListTmp.at(i));
    }

    //qDebug() << "m_lightStateJson : " << *m_lightStateJson;


}

void lightcontroll::slotUpdatePathTrackingStateJson(int mode, int time)
{
    m_pathTrackingStateJson.find("状态").value() = mode;
    m_pathTrackingStateJson.find("延时").value() = time;
}
