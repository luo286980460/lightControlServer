#ifndef LIGHTCONTROLL_H
#define LIGHTCONTROLL_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QTimer>
#include <QSerialPort>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include "control.h"

class lightControll:public QThread
{
    Q_OBJECT

public:
    lightControll(QString controllIp, int controllPort, QThread *parent = nullptr);
    virtual ~lightControll();
    void run() override ;

    bool connectControll();         //连接
    void disconnectControll();      //断连
    void sendDataTcp(QStringList sendDataList);    //发送数据
    void sendDataUART(QSerialPort* m_serialPort, QStringList sendDataList);
signals:
    void showMsg(QString msg);

public slots:
    void ReadData();    //读取数据
    void ReadError(QAbstractSocket::SocketError error);

public:
    QTcpSocket* m_tcpClient;    //tcp 连接
    QString m_controllIp;       //控制器 ip
    int m_controllPort;         //控制器 port
    QTimer m_timer;             //控制补发信息
    QStringList m_sendDataList; //最后一次发送的信息
    int m_sendingInterval;      //单位 ms
    int m_sendingCount;         //发送数量
    bool m_runFlag;             //线程执行flag
    bool m_sendFlag;            //发送数据flag
};

#endif // LIGHTCONTROLL_H
