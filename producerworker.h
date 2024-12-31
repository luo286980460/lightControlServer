#ifndef PRODUCERWORKER_H
#define PRODUCERWORKER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
//#include <csignal>
#include "rdkafkacpp.h"
#include <QObject>


static bool m_run = true;

static void sigterm (int sig) {
    m_run = false;
}

class ExampleEventCb : public RdKafka::EventCb {
public:
    void event_cb (RdKafka::Event &event) {
        switch (event.type())
        {
        case RdKafka::Event::EVENT_ERROR:
            std::cerr << "ERROR (" << RdKafka::err2str(event.err()) << "): " <<
                         event.str() << std::endl;
            if (event.err() == RdKafka::ERR__ALL_BROKERS_DOWN)
                m_run = false;
            break;

        case RdKafka::Event::EVENT_STATS:
            std::cerr << "\"STATS\": " << event.str() << std::endl;
            break;

        case RdKafka::Event::EVENT_LOG:
            fprintf(stderr, "LOG-%i-%s: %s\n",
                    event.severity(), event.fac().c_str(), event.str().c_str());
            break;

        default:
            std::cerr << "EVENT " << event.type() <<
                         " (" << RdKafka::err2str(event.err()) << "): " <<
                         event.str() << std::endl;
            break;
        }
    }
};


class ExampleDeliveryReportCb : public RdKafka::DeliveryReportCb {
public:
    void dr_cb (RdKafka::Message &message) {
        std::cout << "Message delivery for (" << message.len() << " bytes): " <<
                     message.errstr() << std::endl;
//        if (message.key())
//            std::cout << "Key: " << *(message.key()) << ";" << std::endl;
    }
};


class producerWorker : public QObject
{
    Q_OBJECT
public:
    explicit producerWorker(std::string ip, std::string topic_str, QObject *parent=nullptr);
    ~producerWorker();

signals:
    void showMsg(QString);

public slots:
    void slotProduceMessvoidJson(QString strJson, QString strKey);
    void init();

private:
    RdKafka::Conf *conf;
    RdKafka::Conf *tconf;
    RdKafka::Producer *producer
        = nullptr;
    RdKafka::Topic *topic;
    ExampleDeliveryReportCb ex_dr_cb;
    ExampleEventCb ex_event_cb;
    std::string m_ip;
    std::string m_topic_str;


public:
    void produceMessage(std::string message, std::string key = "");

};

#endif // PRODUCERWORKER_H
