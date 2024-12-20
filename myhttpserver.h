#ifndef MYHTTPSERVER_H
#define MYHTTPSERVER_H

#include <QObject>
#include <QHttpServer>
#include <QJsonObject>
#include <QTimer>
#include <QSerialPort>
#include <windows.h>
#include "cts_sdk.h"

class lightcontroll;
class amplifier;


typedef enum{
    TCP,
    UART
}sendType;

enum devPlayState {	//播放状态
    closed,
    playing,
    pause
};

typedef struct
{
    int groupNum;               // 分组号
    int playTimes;              // 播放次数
    int curFileIndex;           // 当前播放语音的下标
    bool mp3IsOpen;             // MP3功能是否打开
    devPlayState playState;     // 播放状态 close play pause
    QStringList fileNameList;	// 文件名列表
    bool DevExist;              // 分组是否存在设备
    int volume;                 // 分组的音量
    QString sbbh;               // 设备编号
}GroupInfo;

typedef struct
{
    enSdkDevState eState;
    BYTE AlmInState;            // 报警输入通道状态指示码，每位对应一路报警: 0(无报警), 1(有报警)。
    BYTE AlmOutState;           // 报警输出通道状态指示码，每位对应一路报警: 0(无报警), 1(有报警)。
}TDevState;


class MyHttpServer : public QObject
{
    Q_OBJECT

public:
    MyHttpServer(QObject *parent = nullptr);
    virtual ~MyHttpServer();

    void create(QHostAddress address, int port);            // 创建并启动服务器
    bool ipAddrIsOK(const QString & ip);                    // 判断字符串是否为合法 ip 地址


    //雾灯模块
    lightcontroll* getControllerFromIp(QString ip);         // 从ip获取控制器对象
    lightcontroll* getControllerFromIpPort(QString ip,      // 从ip和Port获取控制器对象
                                           int Port);
    void updateLightControllList(QList<lightcontroll*>*);   // 更新控制器列表
    QList<lightcontroll*>* m_lightControllList = nullptr;   // 控制器列表
    //int m_controllCount;                                  // 控制器数量
    int m_sendingInterval;                                  // 单位 ms
    int m_sendingCount;                                     // 发送数量

    void initSerialPort();
    //QJsonObject parseLightJson(QJsonObject& json);        // 解析 雾灯 json数据z
    QJsonObject parseLightBroadcast(QJsonObject& json);     // 解析 雾灯 广播控灯（协议3.0）
    bool missingParameterBroadcast(QJsonObject& json,       // parseLightBroadcast 是否缺少必要参数
                                    QJsonObject& backJson);
    QJsonObject parseLightBroadcastNot(QJsonObject& json);  // 解析 雾灯 非广播控灯（协议3.0）
    bool missingParameterBroadcastNot(QJsonObject& json,    // parseLightBroadcast 是否缺少必要参数
                                   QJsonObject& backJson);

    QJsonObject parseLightJson(QJsonObject& json);          // 解析 雾灯 json数据 2.0 版本
    QJsonObject parseLightPathTracking(QJsonObject& json);  // 解析 雾灯 轨迹请求
    QJsonObject parseUpdateLightState(QJsonObject& json);   // 解析 雾灯 更新雾灯状态请求
    QJsonObject parseUpdatePathTrackingState                // 解析 雾灯 更新轨迹跟踪状态请求
        (QJsonObject& json);
    bool TermIpIsUseful(QString TermIp, QString& ip,        // TermIp是否合法 [192.168.1.1:8886]
                        int& port, QJsonObject &backJson);
    bool controllerIsUseful(lightcontroll* controller,      // 控制器是否存在，或者是否处在查询状态
                            QString TermIp,
                            QJsonObject &backJson);
    bool missingParameter(QJsonObject& json,                // 是否缺少必要参数
                          QJsonObject& backJson);
    QString qstr2Hex(QString instr);                        // 汉字 转 16进制
    void setSendingPara();                                  // 设置控制器发送间隔和命令数
    void writeSendingInterval();                            // 发送间隔写入配置
    void writeSendingCount();                               // 发次发送命令数量写入配置

    //辅助屏模块
    QJsonObject parseScreenJson(QJsonObject& json);

    //音响模块                                               // 此处用最大分组数 因为一个音响对应一个分组
    void initSast();                                        // 初始化音响
    TSdkEventTermRegister m_TermList[MAX_BROAD_GROUP];      // 设备列表
    TDevState m_TermState[MAX_BROAD_GROUP];                 // 在线状态列表
    GroupInfo m_GroupInfoList[MAX_BROAD_GROUP];             // 分组列表
    int m_nTermCnt;                                         // 设备数量

    static int CALLBACK OnTzlSdkCallback(enSdkCbType eCbType,
                                         LPVOID pParam,
                                         DWORD dwSize,
                                         int usr_data);
    void LoadTermList();                                    // 加载设备列表
    void UpdateTermListUI();                                // 更新ui界面
    void StoreTermList();                                   // 写入设备列表
    QJsonObject parseSastJson(QJsonObject& json);           // 解析 音响 json数据
    void setGroupInfo(QString TermIp,                       // 设置分组信息
                      QJsonArray& fileNameList,
                      int playTimes);
    void setTermVolume(QString TermIp, int Volume);         // 设置设备音量
    void groupBroadMp3(GroupInfo* groupInfo);				// 分组播放MP3
    bool StartBroadMp3(int groupNum);						// 分组打开播放MP3功能
    bool CloseBroadMp3(int groupNum);						// 分组关闭播放MP3功能
    bool BroadMp3File(int groupNum, QString fileNamePath);	// 分组播放MP3文件
    bool sastIsOnline(const QString & ip);                  // 判断该 ip 控制器是否在线
    bool mp3Exist(QString mp3);                             // 判断mp3是否存在
    bool updateTermVolume(QString TermIp);                  // 将设备音量更新到分组信息里面
    int getVolume(QString TermIp);                          // 获取分组音量
    bool setVolume(QString TermIp, int volume);             // 设置分组音量
    bool setSbbh(QString TermIp, QString sbbh);             // 设置分组设备编号

    // 150W 音响
    void initAmplifier();
    QJsonObject parse150WSastJson(QJsonObject& json);
    amplifier* m_amplifier;
    QStringList m_ipList;
    QStringList m_codeList;

signals:
    void showMsg(QString msg);
    void sigleUpdateTermListUi();
    void forTest();
    void sigleUpdateControllerUi(QString);
    //void changeSendingInterval();
    //void changeSendingCount();
    void sigalUpdateRoadState(QString);                     // 更新车道开启状态
    void sigalUpdateScreenState(QString TermIp,             // 更新辅助屏开启状态
                                QString state);
    // 更新屏幕默认文字内容
    void signalUpDateScreenDefauleContent(QString state,   QString upStr,      QString downStr,
                                          QString upColor, QString downColor,  QString TermIp);
    // 更新雾灯用来同步的闪烁命令值 内容
    void signalUpdateFF88(QString ff88);
    void signalWrite2Kafka(QString topic, QString strJson, QString strKey);

     // 150W 音响
    void signalUpdateTermList(QStringList ipList, QStringList codeList);
    void signalTTS(QString TermIp, QString Content, QString Name, QString sbbh, int Volume, int Times, int Gap
                   , QString m_deviceId, int vol);

public:
    QHttpServer* m_httpServer;          // http 服务
    QHostAddress m_address;             // http 监听 ip
    int m_port;                         // http 监听端口号
    sendType m_sendType;                // 当前发送模式 TCP/UART
};


#endif // MYHTTPSERVER_H
