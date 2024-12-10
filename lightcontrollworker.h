﻿#ifndef LIGHTCONTROLLWORKER_H
#define LIGHTCONTROLLWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTimer>

class lightControllWorker : public QObject
{
    Q_OBJECT
public:
    explicit lightControllWorker(QString connectType, QString topic, QString ip, int port, int sendingInterval,
                                    int sendingCount, QString version, QObject *parent = nullptr);
    ~lightControllWorker();

    bool connectControll();             //连接
    //void disconnectControll();        //断连

    void SendDatagram1(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList, int TermIdSize);
    void SendDatagram2(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList, int TermIdSize);
    void SendDatagram1Udp(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList, int TermIdSize);
    void SendDatagram2Udp(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList, int TermIdSize);

    QJsonObject getTopic2Json(QStringList sendDataList, QString DeviceId, int TermIdSize);
    QString hex2QStr(QString hex);

private:
    void initTcpSocket();
    void initUcpSocket();

signals:
    void showMsg(QString);
    void sigReceiveData(QByteArray);
    void write2Kafka(QString topic, QString strJson, QString strKey);
    void signalFinishUpdateLightState();
    void signalIsCheckingLightState(bool b);
    void signalUpdateProgress(QString progress);
    void signalTest(QByteArray ba);
    void signalUpdateLightStateJson(QStringList checkIdList, QStringList checkResultListTmp);   // 更新雾灯状态的信号

public slots:
    void slotInit();
    void slotSendDatagram(QStringList sendDataList, QString DeviceId, QString ContentStr, int version, int fontColor, int Luminance, QString FlickerList, int TermIdSize);    //发送数据
    void slotReadyReadTcp();
    void slotReadyReadUdp();
    void slotSetIntervalAndCount(int sendingInterval, int sendingCount);
    void slotConnectToControl();
    void slotLightPowerOn(bool on);
    void slotOpenPathTracking(int mode);    // 轨迹跟踪 0 - 关闭; 1 - 模式1; 2 - 模式2
    void slotCheckLightState(QString ip, int port, QStringList idlist);
    void slotTest(QByteArray ba);

public:
    QTcpSocket *m_tcpSocket = nullptr;  //TCP socket
    QUdpSocket *m_udpSocket = nullptr;  //UDP sockets
    int m_sendingInterval;  // 单位 ms
    int m_sendingCount;     // 发送数量
    QString m_controllIp;   // 控制器 ip
    int m_controllPort;     // 控制器 port
    QTimer m_timer;         // 保存最后一次发送信息，循环发送
    QStringList m_lastList; // 最后一次发送
    QString m_topic;        // 主题
    QString m_topic2;       // 主题 weatherWarning
    QString m_deviceId;
    QString m_contentStr;
    QString m_currentColor; // 当前设备文字颜色
    QString m_flicker;      // 当前设备闪烁值
    int m_luminance;        // 当前设备亮度值
    QString m_version;      // 雾灯版本 1 老版本 2 新版本
    QString m_connectType;  // 连接方式 TCP/UDP
    bool m_lightPowerOn = false;
    QStringList m_checkResultList;  // 查询灯状态返回的结果列表
    QString m_checkResultListTmp;   // 查询灯状态返回的结果 临时储存
    QStringList m_checkIdList;      // 查询灯状态的ID列表
    QTimer* m_checkTimer;           // 查询灯状态的定时器
    QStringList m_checkRCmdList;    // 查询灯状态命令列表
    int m_checkIndex=0;             // 查询灯状态命令下标
    void initChenkTimer();
};

#endif // LIGHTCONTROLLWORKER_H
