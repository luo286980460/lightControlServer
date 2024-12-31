#include "controllermanager.h"
#include "controller.h"


ControllerManager::ControllerManager(QObject *parent)
    : QObject{parent}
{

}

void ControllerManager::addController(QString ControllerIpPort, QStringList LightIds, QString ConnectType)
{
    // int index = hasController(ControllerIpPort);
    // if(index > -1) return;

    // Controller* controller = new Controller(ControllerIpPort.split(":").at(0), ControllerIpPort.split(":").at(1).toInt());
    // controller->setControllerIpPort(ControllerIpPort);
    // controller->addLights(LightIds);
    // controller->connectController(ConnectType);

    // m_controllers << controller;

}
void ControllerManager::delController(QString ControllerIpPort)
{
    int index = hasController(ControllerIpPort);
    if(index == -1) return;

    m_controllers.at(index)->deleteLater();
    m_controllers.removeAt(index);
}

int ControllerManager::hasController(QString ControllerIpPort)
{    for(int i=0; i<m_controllers.size(); i++){
        if(m_controllers.at(i)->getControllerIpPort() == ControllerIpPort){
            return i;
        }
    }
    return -1;
}
