#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class producer;
class lightcontroll;
class MyHttpServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void open();
    void initPostRequest();
    void initRoadState();
    void openHttpServer();  // 打开http服务，可控雾灯、右转屏、音响
    void openProducer();    // 打开kafka创造者
    void openControlls();   // 加载雾灯控制器
    void updateRoadStateSetting(QString state); // 更新车道状态配置文件

    void closeEvent(QCloseEvent* event);        // 重写关闭按钮事件
    void initSystemTray();                      // 初始化系统托盘
    QString utf8ToGb2312(char *strUtf8);        // utf8 转 gb2312
    QString gb2312ToUtf8(QString strGb2312);    // gb2312 转 utf8

private slots:
    void on_clearBtn_clicked();
    void on_OpenBtn_clicked();
    void showMsg(QString);
    void slotUpdateRoadState(QString);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);   // 托盘点击响应槽

    void soltUpdateTermListUi();
    void slotUpdateControllerUi(QString);
    void slotUpdateFF88(QString ff88);   // 更新用来同步雾灯闪烁的 命令内容

    void on_testBtn_clicked();

    // 处理超速照片模块
    void dealPicFiles(QString path);
    void requestFinished(QNetworkReply* reply);

signals:
    void write2Kafka(QString topic, QString strJson, QString strKey);
    //void write2Screen(QString upStr, QString downStr, QString upColor, QString downColor, QString ip, QString sfwf);
    /* 参数1：
     *  发送数据类型：
     *      0 关闭状态      1 开启状态      2 即将关闭      3 过车信息
     * 参数2：
     *  是否上次kafka：
     *      false 不传     true 上传
     * 参数3：
     *  车牌照：
    */
    void write2Screen(QString ip, int type, QString plate);
    void write2Light(QStringList sendDataList, QString sbbh, QString name, int version, int color, int light, QString pl, int TermIdSize);
    void setLightIntAndCount(int sendingInterval, int sendingCount);
    //void signalUpdateScreenData(QString sbbh);
    void signalUpDateScreenDefauleContent(QString state, QString defaultContent, QString TermIp);
    void signalUpDateScreenState(QString TermIp, QString state);

private:
    Ui::Widget *ui;
    MyHttpServer* m_httpServer; // http服务器用来接收雾灯控制信息
    QSettings* m_settings;      // 获取配置文件
    producer* m_producer;       // kafka 创造者
    bool m_isOpen;
    QTimer m_timer;             // 应急车道关闭缓冲计时器
    QString m_roadIsOpen;       // 应急车道是否开启
    QTimer m_mscTimer;          // 秒级定时器

    //雾灯 模块
    QList<lightcontroll*> m_lightControllList; // 控制器列表
    int m_controllCount;        // 控制器数量
    int m_ff88Flag;             // 闪烁同步标志
    QString m_ff88;             // 闪烁同步命令
    void sendFF88();            // 发送

    // kafka 模块
    QList<producer*> m_producerList; // kafka创造者列表

    // 超速摄像头 模块
    void openFileWatcher();                     // 打开文件监控
    QString getBackUpPath(QString filePath);    // 获取备份文件夹路径
    QFileSystemWatcher* m_fileWather;           // 文件监控
    QNetworkAccessManager* m_manager;
    QNetworkRequest* m_postRequest;
    QString m_path;
    QString m_screenIp;
    int m_screenPort;

    // 文件监控

private:    // 最小化到系统托盘
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    //窗口管理动作
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;



};
#endif // WIDGET_H
