#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QThread>

class producerWorker;

class producer : public QObject
{
    Q_OBJECT
public:
    explicit producer(QObject *parent = nullptr);
    ~producer();
    void init();
    void start();
    void stop();

    void setTopic(QString topic);
    void setkafkaIp(QString kafkaIp);

signals:
    void showMsg(QString);
    void sigleInitWork();
    void sigleProduceMessvoidJson(QString strJson, QString strKey);

public slots:
    void slotProduceMessvoidJson(QString topic, QString strJson, QString strKey);

private:
    QThread m_workerThread; //kafka 工作线程
    producerWorker *m_work = nullptr;    //kafka 工作类
    QString m_ip;   //kafka ip
    QString m_topic;    //主题

};

#endif // PRODUCER_H
