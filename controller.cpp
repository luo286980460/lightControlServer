#include "controller.h"
#include "controllerworker.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    m_work = new ControllerWorker;
    m_work->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);
    connect(this, &Controller::signalInitWorker, m_work, &ControllerWorker::slotInitWorker);


    connect(this, &Controller::signalInitTcp, m_work, &ControllerWorker::slotInitTcp);
    connect(this, &Controller::signalInitUdp, m_work, &ControllerWorker::slotInitUdp);

    // connect(m_work, &producerWorker::showMsg, this, &producer::showMsg);
    // connect(this, &producer::sigleProduceMessvoidJson, m_work, &producerWorker::slotProduceMessvoidJson);
    // connect(this, &producer::sigleInitWork, m_work, &producerWorker::init);

}

void Controller::start()
{
    m_workerThread.start();
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
        light.insert("LightId", m_lights.at(i).LightId);
        light.insert("Content", m_lights.at(i).Content);
        light.insert("FontColor", m_lights.at(i).FontColor);
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
            s_light light;
            light.LightId = lightId;
            m_lights << light;
        }else{
            continue;
        }
    }
}

int Controller::hasLight(int lightId)
{
    for(int i=0; i<m_lights.size(); i++){
        if(lightId == m_lights.at(i).LightId){
            return i;
        }
    }
    return -1;
}

void Controller::connectController(QString ConnectType)
{
    if(ConnectType == "TCP"){
        emit signalInitTcp();
    }else if(ConnectType == "UDP"){
        emit signalInitUdp();
    }else{
        emit signalInitUdp();
    }
}
