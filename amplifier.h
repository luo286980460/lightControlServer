#ifndef AMPLIFIER_H
#define AMPLIFIER_H

#include <QObject>
#include <QThread>

class amplifierWorker;

class amplifier : public QObject
{
    Q_OBJECT
public:
    explicit amplifier(QObject *parent = nullptr);
    ~amplifier();

    void start();
    void stop();

signals:
    void forTest();
    void showMsg(QString msg);
    void signalTTS(QString TermIp, QString Content, QString Name, QString sbbh, int Volume, int Times, int Gap
                   , QString m_deviceId, int vol);
    void signalInitWorker();
    void signalUpdateTermList(QStringList ipList, QStringList codeList);
    void write2Kafka(QString topic, QString strJson, QString strKey);

private:
    QThread m_workerThread; // 雾灯 工作线程
    amplifierWorker *m_work = nullptr;    //雾灯 工作类
};

#endif // AMPLIFIER_H
