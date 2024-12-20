#ifndef CONTROLLERWORKER_H
#define CONTROLLERWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QJsonObject>
#include <QJsonArray>

typedef struct{         // 灯 属性
    int LightId;        // 灯 拨码
    QString Content;    // 灯 显示的内容（空串时，为不显示）
    int FontColor;      // 文字 颜色
}s_light1;

class ControllerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ControllerWorker(QObject *parent = nullptr);
    void boadCast(QStringList cmdList);                 // 广播命令
    void boadCastNot(QStringList cmdList);              // 非广播命令

private:

signals:
    void showMsg(QString msg);

public slots:
    void slotInitWorker();
    void slotInitTcp();
    void slotInitUdp();
    void slotReadyReadTcp();
    void slotReadyReadUdp();


private:
    QTcpSocket *m_tcpSocket       //TCP socket
        = nullptr;
    QUdpSocket *m_udpSocket       //UDP sockets
        = nullptr;
    QString m_ConnectType;        // 控制器 连接方式 TCP/UDP
    int m_sendingCount = 5;       // 每一次发送的命令数量
};

#endif // CONTROLLERWORKER_H
