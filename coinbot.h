#ifndef COINBOT_H
#define COINBOT_H

#include <QObject>


class QCoinBot
{
public:
    QCoinBot();

    QByteArray getEncryptedText(QString text);
    QString getDecryptedText(QByteArray text);

    void setSettingValue(QString key,QVariant value);
    QVariant getSettingValue(QString key);

    void setBinanceApiKey(QByteArray apiKey);
    QString getBinanceApiKey();

    void setBinanceSecretKey(QByteArray apiKey);
    QString getBinanceSecretKey();

};

#endif // COINBOT_H
