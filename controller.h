#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>

class ControllerWorker;

typedef struct{         // 灯 属性
    int LightId;        // 灯 拨码
    QString Content;    // 灯 显示的内容（空串时，为不显示）
    int FontColor;      // 文字 颜色

    QString cmdCheck1;  // 查询命令1
    QString cmdCheck2;  // 查询命令2
    QString cmdCheck3;  // 查询命令3

}s_light;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QString ip, int port, QString topic, int sendingInterval, int sendingCount, QString ConnectType, QObject *parent = nullptr);

    void start();
    void stop();

    QJsonObject getKafkaJson();                         // 获取上传kafka的json数据
    QString getControllerIpPort();                      // 获取控制器 Ip:Port
    void setControllerIpPort(QString ControllerIpPort); // 设置控制器 Ip:Port
    void addLights(QStringList lightIds);               // 添加灯
    int hasLight(int lightId);                          // 对应灯是否存在
    void connectController(QString ConnectType);        // 连接控制器
    QString getControllIp();
    int getControllPort();
    void sendControlCmd(QStringList& cmdList, QJsonObject& json);           // 发送控制命令
    void sendCheckCmd(int& checkMode, QStringList& idList);           // 发送查询命令
    s_light* getLightFromLightId(int lightId);

private:
    void sendData2Kafka();

signals:
    void showMsg(QString msg);
    void signalInitWorker();
    void signalInitTcp(QString ip, int port);
    void signalInitUdp();
    void signalFlushAutoCheckCmd(QStringList cmdCheck1, QStringList cmdCheck2, QStringList cmdCheck3);
    void signalSendControlCmd(QStringList cmdList);     // 发送控制命令
    void signalSendCheckCmd(QStringList cmdList);       // 发送查询命令
    void signalLightPowerOn(bool on);
    void signalWrite2Kafka(QString topic, QString strJson, QString strKey);

public slots:
    void slotLightIsOff(int lightId);
    void slotWrite2Kafka();

private:
    QThread m_workerThread;                 // 控制器 工作线程
    ControllerWorker *m_work = nullptr;     // 控制器 工作类
    QString m_ControllerIpPort;             // 控制器 ip:port
    QString m_ControllerIp;                 // 控制器 ip
    int m_ControllerPort;                   // 控制器 port
    QString m_DeviceId;                     // 控制器 设备编号
    int m_Luminance;                        // 控制器 亮度
    QJsonArray m_Flicker;                   // 控制器 闪烁（size == 0时，为不闪烁）
    int m_PathTracking;                     // 控制器 轨迹模式（0-关闭 1-模式1 2-模式2）
    int m_PathTrackingTime;                 // 控制器 轨迹延时（1-20s）
    int m_Version;                          // 控制器 灯版本
    QString m_Content;                      // 控制器 全部显示内容
    QVector<s_light*> m_lights;             // 灯实例列表
    QJsonObject m_kafkaJson;                // 上传kafka的json
    QString m_topic;                        // 需要上传的kafka的主题
    QString m_kafkaKey = "light";           // 需要上传的kafka的主题
};

#endif // CONTROLLER_H
