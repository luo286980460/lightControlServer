#ifndef LIGHTCONTROLL_H
#define LIGHTCONTROLL_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QJsonObject>

class lightControllWorker;

class lightcontroll : public QObject
{
    Q_OBJECT
public:
    explicit lightcontroll(QString connectType, QString topic, QString ip, int port, int sendingInterval,
                           int sendingCount, QString version, QObject *parent = nullptr);
    ~lightcontroll();

    void start();
    void stop();
    QString getControllIp();
    int getControllPort();
    bool getCheckLightState(QString& progress);
    QJsonObject getLightState();
    QJsonObject getPathTrackingState();

signals:
    void signalInitWorker();
    void showMsg(QString);
    void sigSendDatagram(QStringList sendDataList, QString DeviceId, QString ContentStr, int version, int fontColor, int Luminance, QString FlickerList, int TermIdSize);
    void siglSetIntervalAndCount(int m_sendingInterval = 500, int m_sendingCount = 10);
    void sigConnectToControl();
    void write2Kafka(QString topic, QString strJson, QString strKey);
    void signalLightPowerOn(bool on);
    void signalOpenPathTracking(int mode);
    void signalCheckLightState(QStringList idlist);
    void signalCheckPathTrackingState();

public slots:
    void slotReceiveTcpData(QByteArray);
    void slotIsCheckingLightState(bool b);
    void slotUpdateProgress(QString progress);
    void slotUpdateLightStateJson(QStringList checkIdList, QStringList checkResultListTmp);
    void slotUpdatePathTrackingStateJson(int mode, int time);

private:
    QString m_controllIp;   // 控制器 ip
    int m_controllPort;     // 控制器 port
    int m_sendingInterval;  // 单位 ms
    int m_sendingCount;     // 发送数量
    QThread m_workerThread; // 雾灯 工作线程
    lightControllWorker *m_work = nullptr;    //雾灯 工作类
    QString m_topic;
    QString m_version;      // 雾灯版本 1 老版本 2 新版本
    int m_checkLightState = false;        // 正在查询雾灯状态
    QString m_progress;     // 雾灯状态查询进度
    QJsonObject* m_lightStateJson = nullptr;
    QJsonObject m_pathTrackingStateJson;

};

#endif // LIGHTCONTROLL_H
