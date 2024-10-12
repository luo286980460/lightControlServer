#ifndef LIGHTCONTROLLWORKER_H
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

    void SendDatagram1(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList);
    void SendDatagram2(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList);
    void SendDatagram1Udp(QStringList sendDataList, QString DeviceId, QString ContentStr, int Luminance, QString FlickerList);
    void SendDatagram2Udp(QStringList sendDataList, QString DeviceId, QString ContentStr, int fontColor, int Luminance, QString FlickerList);

    QJsonObject getTopic2Json(QStringList sendDataList, QString DeviceId);
    QString hex2QStr(QString hex);

private:
    void initTcpSocket();
    void initUcpSocket();

signals:
    void showMsg(QString);
    void sigReceiveData(QByteArray);
    void write2Kafka(QString topic, QString strJson, QString strKey);

public slots:
    void slotSendDatagram(QStringList sendDataList, QString DeviceId, QString ContentStr, int version, int fontColor, int Luminance, QString FlickerList);    //发送数据
    void slotReadyRead();
    void slotSetIntervalAndCount(int sendingInterval, int sendingCount);
    void slotConnectToControl();

public:
    QTcpSocket *m_tcpSocket = nullptr;  //TCP socket
    QUdpSocket *m_udpSocket = nullptr;  //UDP socket
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
};

#endif // LIGHTCONTROLLWORKER_H
