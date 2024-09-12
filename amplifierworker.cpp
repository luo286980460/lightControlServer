#include <QJsonObject>
#include <QJsonDocument>
#include "amplifierworker.h"

amplifierWorker::amplifierWorker(QObject *parent)
    : QObject{parent}
{

}

void amplifierWorker::forTest()
{
    emit showMsg("forTest");
    slotTTS("192.168.1.144", "安全驾驶，文明行车", "安全驾驶", "sbbg", 100, 1, 1, "sbbh", 20);
}

void amplifierWorker::slotTTS(QString TermIp, QString Content, QString Name, QString sbbh, int Volume, int Times, int Gap
                              , QString m_deviceId, int vol)
{
    QJsonObject json;
    QJsonObject json1;
    QString code;

    //showMsg(QString("m_amplifierCount: %1").arg(m_amplifierCount));
    for(int i=0; i<m_amplifierCount; i++){
        if(m_ipList.at(i) == TermIp){
            code = m_codeList.at(i);

            json.insert("device_codes", code);
            json.insert("text", Content);
            json.insert("vcn", "xiaoyan");
            json.insert("speed", 50);
            json.insert("volume", Volume);
            json.insert("rdn", "0");
            json.insert("rcn", "0");
            json.insert("reg", 0);
            json.insert("sync", false);
            json.insert("queue", false);

            json1.insert("times", Times);
            json1.insert("gap", Gap);
            json.insert("loop", json1);

            QJsonDocument document;
            document.setObject(json);
            QByteArray dataArray = document.toJson(QJsonDocument::Compact);

            // 构造请求
            QNetworkRequest request;
            request.setUrl(QUrl(QString("http://%1/v1/speech").arg(TermIp)));

            // kafka
            QJsonObject kafka;
            kafka.insert("stateId", m_deviceId);
            kafka.insert("deviceId", m_deviceId);
            kafka.insert("deviceState", "1");

            kafka.insert("checkDate", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
            kafka.insert("handleState", "1");

            if(Name.isEmpty()) Name = "关闭";
            kafka.insert("value", Name);
            kafka.insert("source", "1");
            kafka.insert("vol", vol);
            emit write2Kafka("deviceState", QJsonDocument(kafka).toJson(), "150wSast");
            //emit showMsg(QJsonDocument(kafka).toJson());

            // 发送请求
            if(Name == "关闭"){
                manager->deleteResource(request);
            }else{
                manager->post(request, dataArray);
            }
            emit showMsg(QString(dataArray));

            break;
        }
    }
}

void amplifierWorker::init()
{
    manager = new QNetworkAccessManager(this);

}

void amplifierWorker::slotUpdateTermList(QStringList ipList, QStringList codeList)
{
    m_ipList = ipList;
    m_codeList = codeList;
    m_amplifierCount = m_ipList.size();
}
