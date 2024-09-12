#ifndef AMPLIFIERWORKER_H
#define AMPLIFIERWORKER_H

#include <QObject>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkAccessManager>

class amplifierWorker : public QObject
{
    Q_OBJECT
public:
    explicit amplifierWorker(QObject *parent = nullptr);

signals:
    void showMsg(QString msg);
    void write2Kafka(QString topic, QString strJson, QString strKey);

public slots:
    void forTest();
    void slotTTS(QString TermIp, QString Content, QString Name, QString sbbh, int Volume, int Times, int Gap
                 , QString m_deviceId, int vol);
    void init();
    void slotUpdateTermList(QStringList ipList, QStringList codeList);

private:
    QNetworkAccessManager* manager;
    QStringList m_ipList;
    QStringList m_codeList;
    int m_amplifierCount;
};

#endif // AMPLIFIERWORKER_H
