#include <QSettings>
#include <QCoreApplication>
#include <QFileInfo>

#include "producer.h"
#include "producerworker.h"

producer::producer(QObject *parent)
    : QObject{parent}
{

}

producer::~producer()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void producer::init()
{
    m_work = new producerWorker(m_ip.toStdString(), m_topic.toStdString());
    m_work->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);

    connect(m_work, &producerWorker::showMsg, this, &producer::showMsg);
    connect(this, &producer::signalProduceMessvoidJson, m_work, &producerWorker::slotProduceMessvoidJson);
    connect(this, &producer::signalInitWork, m_work, &producerWorker::init);
}

void producer::start()
{
    m_workerThread.start();
}

void producer::stop()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void producer::setTopic(QString topic)
{
    m_topic = topic;
}

void producer::setkafkaIp(QString kafkaIp)
{
    m_ip = kafkaIp;
}

QString producer::getTopic()
{
    return m_topic;
}

void producer::slotProduceMessvoidJson(QString topic, QString strJson, QString strKey)
{
    if(m_topic == topic){
        emit signalProduceMessvoidJson(strJson, strKey);
    }
}
