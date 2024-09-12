#include "amplifier.h"
#include "amplifierworker.h"

amplifier::amplifier(QObject *parent)
    : QObject{parent}
{
    m_work = new amplifierWorker();
    m_work->moveToThread(&m_workerThread);
    connect(&m_workerThread, &QThread::finished, m_work, &QObject::deleteLater);

    connect(m_work, &amplifierWorker::showMsg, this,&amplifier::showMsg);
    connect(this, &amplifier::signalTTS, m_work,&amplifierWorker::slotTTS);
    connect(this, &amplifier::signalInitWorker, m_work,&amplifierWorker::init);
    connect(this, &amplifier::signalUpdateTermList, m_work, &amplifierWorker::slotUpdateTermList);
    connect(this, &amplifier::forTest, m_work, &amplifierWorker::forTest);
    connect(m_work, &amplifierWorker::write2Kafka, this,&amplifier::write2Kafka);

}

amplifier::~amplifier()
{
    m_workerThread.quit();
    m_workerThread.wait();
}

void amplifier::start()
{
    m_workerThread.start();
    emit signalInitWorker();
}

void amplifier::stop()
{
    m_workerThread.quit();
    m_workerThread.wait();
}
