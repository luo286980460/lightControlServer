#include "controller.h"
#include "controllerworker.h"
#include "lightCmdList.h"

#include <QJsonDocument>

Controller::Controller(QString ip, int port, QString topic, int sendingInterval, int sendingCount, QString ConnectType, QObject *parent)
    : QObject{parent}
    , m_ControllerIp(ip)
    , m_ControllerPort(port)
    , m_topic(topic)
{
    m_work = new ControllerWorker(ip, port, sendingInterval, sendingCount, ConnectType);
    m_work->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);
    connect(this, &Controller::signalInitWorker, m_work, &ControllerWorker::slotInitWorker);
    connect(m_work, &ControllerWorker::showMsg, this, &Controller::showMsg);


    connect(this, &Controller::signalInitTcp, m_work, &ControllerWorker::slotInitTcp);
    connect(this, &Controller::signalInitUdp, m_work, &ControllerWorker::slotInitUdp);


    connect(this, &Controller::signalFlushAutoCheckCmd, m_work, &ControllerWorker::slotFlushAutoCheckCmd);
    connect(this, &Controller::signalSendControlCmd, m_work, &ControllerWorker::slotSendControlCmd);
    connect(this, &Controller::signalSendCheckCmd, m_work, &ControllerWorker::slotSendCheckCmd);

    connect(m_work, &ControllerWorker::signalWrite2Kafka, this, &Controller::slotWrite2Kafka);
    connect(m_work, &ControllerWorker::signalLightIsOff, this, &Controller::slotLightIsOff);

    // connect(m_work, &producerWorker::showMsg, this, &producer::showMsg);
    // connect(this, &producer::sigleProduceMessvoidJson, m_work, &producerWorker::slotProduceMessvoidJson);
    // connect(this, &producer::sigleInitWork, m_work, &producerWorker::init);

    m_ControllerIpPort = "";         // 控制器 ip:port
    m_Content = "";                  // 控制器 全部显示内容
    m_DeviceId = "";                 // 控制器 设备编号
    m_Luminance = -1;                // 控制器 亮度
    m_PathTracking = 0;              // 控制器 轨迹模式（0-关闭 1-模式1 2-模式2）
    m_PathTrackingTime = 1;          // 控制器 轨迹延时（1-20s）
    m_Version = -1;                  // 控制器 灯版本

}

void Controller::start()
{
    m_workerThread.start();
    emit signalInitWorker();
}

void Controller::stop()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

QJsonObject Controller::getKafkaJson()
{
    QJsonArray lights;
    //lights
    for(int i=0; i<m_lights.size(); i++){
        QJsonObject light;
        light.insert("LightId", m_lights.at(i)->LightId);
        light.insert("Content", m_lights.at(i)->Content);
        light.insert("FontColor", m_lights.at(i)->FontColor);
        lights << light;
    }

    m_kafkaJson.insert("ControllerIpPort", m_ControllerIpPort);
    m_kafkaJson.insert("DeviceId", m_DeviceId);
    m_kafkaJson.insert("UpdateTime", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    m_kafkaJson.insert("Luminance", m_Luminance);
    m_kafkaJson.insert("Flicker", m_Flicker);
    m_kafkaJson.insert("PathTracking", m_PathTracking);
    m_kafkaJson.insert("PathTrackingTime", m_PathTrackingTime);
    m_kafkaJson.insert("Version", m_Version);
    m_kafkaJson.insert("Content", m_Content);
    m_kafkaJson.insert("Lights", lights);

    return m_kafkaJson;
}

QString Controller::getControllerIpPort()
{
    return m_ControllerIpPort;
}

void Controller::setControllerIpPort(QString ControllerIpPort)
{
    m_ControllerIpPort = ControllerIpPort;
    if(ControllerIpPort.size() == 2){
        m_ControllerIp = ControllerIpPort.split(":").at(0);
        m_ControllerPort = ControllerIpPort.split(":").at(1).toInt();
    }
}
void Controller::addLights(QStringList lightIds)
{
    for(int i=0; i<lightIds.size(); i++){
        int lightId = lightIds.at(i).toInt();
        int index = hasLight(lightId);

        if(index == -1){
            s_light* light = new s_light;
            light->FontColor = -1;
            light->LightId = lightId;
            m_lights << light;
        }else{
            continue;
        }
    }
}

int Controller::hasLight(int lightId)
{
    for(int i=0; i<m_lights.size(); i++){
        if(lightId == m_lights.at(i)->LightId){
            return i;
        }
    }
    return -1;
}

void Controller::connectController(QString ConnectType)
{
    if(ConnectType == "TCP"){
        emit signalInitTcp(m_ControllerIp, m_ControllerPort);
    }else if(ConnectType == "UDP"){
        emit signalInitUdp();
    }else{
        emit signalInitUdp();
    }
}

QString Controller::getControllIp()
{
    return m_ControllerIp;
}

int Controller::getControllPort()
{
    return m_ControllerPort;
}

void Controller::sendControlCmd(QStringList& cmdList, QJsonObject& json)
{
    if(json.find("ControllerIpPort") != json.end()){
        m_ControllerIpPort = json.value("ControllerIpPort").toString();     // 控制器 ip:port
    }

    if(json.find("PathTracking") != json.end()){
        m_PathTracking = json.value("PathTracking").toInt();     // 控制器 ip:port
    }


    if(json.find("Content") != json.end()){
        m_Content = json.value("Content").toString();                       // 控制器 全部显示内容

        // 如果是广播，更新所有light里面的content
        if(json.find("Broadcast") != json.end() && json.value("Broadcast").toInt() == 1){
            for(int i=0; i<m_lights.size(); i++){
                m_lights.at(i)->Content = m_Content;
            }
        }else if(json.find("Broadcast") != json.end() && json.value("Broadcast").toInt() == 0){
            for(int i=0; i<m_lights.size(); i++){
                if(i < m_Content.size()){
                    m_lights.at(i)->Content = m_Content.at(i);
                }

            }
        }

        if(json.find("FontColor") != json.end()){
            for(int i=0; i<m_lights.size(); i++){
                m_lights.at(i)->FontColor = json.value("FontColor").toInt();
            }
        }
    }

    if(json.find("DeviceId") != json.end()){
        m_DeviceId = json.value("DeviceId").toString();                     // 控制器 设备编号
    }

    if(json.find("Luminance") != json.end()){
        m_Luminance = json.value("Luminance").toInt();                      // 控制器 亮度
    }

    if(json.find("Flicker") != json.end()){
        m_Flicker =  json.value("Flicker").toArray();                       // 控制器 闪烁（size == 0时，为不闪烁
    }

    if(json.find("PathTracking") != json.end()){
        m_PathTracking = json.value("PathTracking").toInt();                // 控制器 轨迹模式（0-关闭 1-模式1 2-模式2）
    }

    if(json.find("pathTrackingTime") != json.end()){
        m_PathTrackingTime = json.value("pathTrackingTime").toInt();         // 控制器 轨迹延时（1-20s）
    }

    if(json.find("Version") != json.end()){
        m_Version = json.value("Version").toInt();                          // 控制器 灯版本
    }

    emit signalSendControlCmd(cmdList);
    slotWrite2Kafka();
}

void Controller::sendCheckCmd(int& checkMode, QStringList& idList)
{
    QStringList cmdList0;
    QStringList cmdList1;
    QStringList cmdList2;
    QStringList cmdList3;

    //qDebug() << m_ControllerIp << " *** checkMode: " << checkMode << " *** idList: " << idList;
    if(idList.isEmpty()){
        foreach (s_light* light, m_lights) {
            idList << QString::number(light->LightId);
        }
    }
    //qDebug() << m_ControllerIp << " *** checkMode: " << checkMode << " *** idList: " << idList;

    for (int i = 0; i < idList.size(); ++i) {
        int lightId = idList.at(i).toInt();
        cmdList1 <<  QString(CMD_STATUS_QUERY_1).arg(lightId, 2, 16, QLatin1Char('0'));
        cmdList2 <<  QString(CMD_STATUS_QUERY_5).arg(lightId, 2, 16, QLatin1Char('0'));
        cmdList3 <<  QString(CMD_STATUS_QUERY_3).arg(lightId, 2, 16, QLatin1Char('0'));
    }

    cmdList0 << cmdList1 << cmdList2 << cmdList3;

    switch(checkMode){
    case 1:
        emit signalSendCheckCmd(cmdList1);
        break;
    case 2:
        emit signalSendCheckCmd(cmdList2);
        break;
    case 3:
        emit signalSendCheckCmd(cmdList3);
        break;
    case 0:
        emit signalSendCheckCmd(cmdList0);
        break;
    }
}

s_light *Controller::getLightFromLightId(int lightId)
{
    foreach (s_light* light, m_lights) {
        if(light->LightId == lightId){
            return light;
        }
    }
    return nullptr;
}

void Controller::sendData2Kafka()
{
    getKafkaJson();
}

void Controller::slotLightIsOff(int lightId)
{

    //qDebug() << "****   m_Content: " << m_Content;

    s_light* light = getLightFromLightId(lightId);
    light->Content.clear();
    m_Content.clear();

    foreach (s_light* light1, m_lights) {
        if(light1->Content.isEmpty()){
            m_Content.append("-");
        }
        m_Content.append(light1->Content);
    }


    //qDebug() << "****   m_Content: " << m_Content;
}

void Controller::slotWrite2Kafka()
{
    emit signalWrite2Kafka(m_topic, QJsonDocument(getKafkaJson()).toJson(), m_kafkaKey);
}

