#include <QCoreApplication>
#include <QFileInfo>
#include <QSettings>
#include <QDebug>

#include "producerworker.h"

#define INIFILE_KAFKA "/kafka.ini"

std::string errstr;
int32_t partition = RdKafka::Topic::PARTITION_UA;


producerWorker::producerWorker(std::string ip, std::string topic_str, QObject *parent):
    QObject(parent)
  , m_ip(ip)
  , m_topic_str(topic_str)
{
    //init();
}

producerWorker::~producerWorker()
{
    m_run = true;
    // 退出前处理完输出队列中的消息
    while (m_run && producer->outq_len() > 0) {
        //qDebug()<< "Waiting for " << producer->outq_len();
        producer->poll(1000);
    }
    RdKafka::wait_destroyed(1000);

    delete conf;
    delete tconf;
    delete topic;
    delete producer;

}



void producerWorker::produceMessage(std::string message, std::string key)
{
    RdKafka::ErrorCode resp =
            producer->produce(topic, partition,
                              RdKafka::Producer::RK_MSG_COPY /* Copy payload */,
                              const_cast<char *>(message.c_str()), message.size(),
                              const_cast<char *>(key.c_str()), key.size(),
                              NULL);

    if (resp != RdKafka::ERR_NO_ERROR);
        //qDebug()<< "% Produce failed: " <<QString::fromStdString(RdKafka::err2str(resp));
    else;
        //qDebug()<< "% Produced message (" << message.size() << " bytes)";
    qDebug() << QString::fromStdString(message) << QString::fromStdString(key);
    producer->poll(0);
}

void producerWorker::slotProduceMessvoidJson(QString strJson, QString strKey)
{
    std::string message = strJson.toStdString();
    std::string key = strKey.toStdString();
    RdKafka::ErrorCode resp;

    if(producer){
        resp = producer->produce(topic, partition,
                      RdKafka::Producer::RK_MSG_COPY /* Copy payload */,
                      const_cast<char *>(message.c_str()), message.size(),
                      const_cast<char *>(key.c_str()), key.size(),
                      NULL);

        if (resp != RdKafka::ERR_NO_ERROR)
            qDebug()<< "% Produce failed: " << QString::fromStdString(RdKafka::err2str(resp));
        else
            qDebug()<< "% Produced message (" << message.size() << " bytes)";

            producer->poll(0);
    }
}

void producerWorker::init()
{
    /*QString iniPath = QCoreApplication::applicationDirPath() + INIFILE_KAFKA;
    if(!QFileInfo::exists(iniPath)){
        emit showMsg("******kafka配置文件读取失败");
        return;
    }
    QSettings settings(iniPath, QSettings::IniFormat);
    QString strTopic = settings.value("kafka/topic", "test_ls").toString();*/
    //m_topic_str = strTopic.toStdString();

    std::string brokers = m_ip;
    //qDebug() << QString::fromStdString(m_ip);
    conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

    conf->set("bootstrap.servers", brokers, errstr);

    conf->set("event_cb", &ex_event_cb, errstr);

//    signal(SIGINT, sigterm);
//    signal(SIGTERM, sigterm);


    conf->set("dr_cb", &ex_dr_cb, errstr);

    producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        exit(1);
    }
    std::cout << "% Created producer " << producer->name() << std::endl;
    //emit showMsg("kafka创造已开启");

    topic = RdKafka::Topic::create(producer, m_topic_str,
                                                   tconf, errstr);
    if (!topic) {
        std::cerr << "Failed to create topic: " << errstr << std::endl;
        exit(1);
    }
}
