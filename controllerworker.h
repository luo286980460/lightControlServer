#ifndef CONTROLLERWORKER_H
#define CONTROLLERWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

typedef struct{         // 灯 属性
    int LightId;        // 灯 拨码
    QString Content;    // 灯 显示的内容（空串时，为不显示）
    int FontColor;      // 文字 颜色
}s_light1;

class ControllerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ControllerWorker(QString ip, int port, int sendingInterval, int sendingCount, QString ConnectType, QObject *parent = nullptr);
    void boadCast(QStringList cmdList);                 // 广播命令
    void boadCastNot(QStringList cmdList);              // 非广播命令

    int m_sendingInterval = 500;    // 重复发送命令的间隔
    int m_sendingCount = 5;       // 每一次发送的命令数量
    QStringList m_cmdList;          // 普通控灯命令列表
    //QStringList m_cmdCheckList;          // 查询命令列表
    int workMode = 2;               // 工作模式 1-控灯模式 2-查询模式
    QStringList m_cmdCheckState;                    // 查询 控制板状态 命令列表
    QStringList m_cmdCheckPowerState;               // 查询 控制板电源状态 命令列表
    QStringList m_cmdCheckPathTrackingDelay;        // 查询 轨迹跟踪延时 命令列表
    QStringList m_cmdCheckPathTrackingMode;         // 查询 轨迹跟踪模式 命令列表
    int waitForData = 0;            // 等待灯回复
    int currentCheckLightId = -1;   // 当前查询的灯ID
    int m_checkstate = 5;             // 0 不查询 1查1 2查2  3查3  5查全部
    QTimer* m_checkTimer;           // 查询计时器

    int getLightIdFromCmd(QString cmd);     // 从命令里面获取灯ID
    // int getCmdTypeFromCmd(QString cmd);     // 从命令里面获取命令类型
    void initCheckTimer();
    void sendCmd2Controller();              // 发送普通控灯命令


private:

signals:
    void showMsg(QString msg);
    void signalLightIsOff(int lightId);
    void signalWrite2Kafka();

public slots:
    void slotInitWorker();
    void slotInitTcp(QString ip, int port);
    void slotInitUdp();
    void slotReadyReadTcp();
    void slotReadyReadUdp();
    void slotCmd2Controller(QStringList cmdList);
    void slotFlushAutoCheckCmd(QStringList cmdCheckState, QStringList cmdCheckPowerState, QStringList cmdCheckPathTrackingDelay);
    void slotSendControlCmd(QStringList cmdList);     // 发送控制命令
    void slotSendCheckCmd(QStringList cmdList);       // 发送查询命令


private:
    QTcpSocket *m_tcpSocket       //TCP socket
        = nullptr;
    QUdpSocket *m_udpSocket       //UDP sockets
        = nullptr;
    QString m_ConnectType;        // 控制器 连接方式 TCP/UDP
    QString m_ControllerIp;                 // 控制器 ip
    int m_ControllerPort;                   // 控制器 port

};

#endif // CONTROLLERWORKER_H
