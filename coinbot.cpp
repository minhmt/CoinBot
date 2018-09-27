#include "coinbot.h"
#include "qaesencryption.h"
#include <QCryptographicHash>
#include <QSettings>


QCoinBot::QCoinBot()
{

}

QByteArray QCoinBot::getEncryptedText(QString encryptText)
{
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB, QAESEncryption::Padding::ISO);

    QString key("minhmt-8810");

    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);

    QByteArray encodeText = encryption.encode(encryptText.toLocal8Bit(), hashKey);

    return encodeText;

}

QString QCoinBot::getDecryptedText(QByteArray encodedText)
{

    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB, QAESEncryption::Padding::ISO);

    QString key("minhmt-8810");

    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    QByteArray decodedText = encryption.removePadding(encryption.decode(encodedText, hashKey));

    return decodedText;


}

QVariant QCoinBot::getSettingValue(QString key)
{
    QSettings settings("JMSoft", "QCoinBot");
    return settings.value(key);
}

void QCoinBot::setBinanceApiKey(QByteArray apiKey)
{
     setSettingValue("BinanceAPIKey",apiKey);
}

QString QCoinBot::getBinanceApiKey()
{
    QByteArray encodedData =   getSettingValue("BinanceAPIKey").toByteArray();

    return getDecryptedText(encodedData);
}

void QCoinBot::setBinanceSecretKey(QByteArray apiKey)
{
    setSettingValue("BinanceSecretKey",apiKey);

}

QString QCoinBot::getBinanceSecretKey()
{
    QByteArray encodedData =   getSettingValue("BinanceSecretKey").toByteArray();

    return getDecryptedText(encodedData);
}

void QCoinBot::setSettingValue(QString key,QVariant value)
{

    QSettings settings("JMSoft", "QCoinBot");
    settings.setValue(key,value);

}
