#ifndef CONTROLLERMANAGER_H
#define CONTROLLERMANAGER_H

#include <QObject>

class Controller;

class ControllerManager : public QObject
{
    Q_OBJECT

public:
    ControllerManager(QObject *parent = nullptr);
    void addController(QString ControllerIpPort, QStringList LightIds,     // 添加控制器
                       QString ConnectType);
    void delController(QString ControllerIpPort);                          // 删除控制器

    /*
     *  功能：控制器是否存在
     *      存在    返回下标
     *      不存在  返回-1)
     */
    int hasController(QString ControllerIpPort);

private:
    QVector<Controller*> m_controllers;
};

#endif // CONTROLLERMANAGER_H
