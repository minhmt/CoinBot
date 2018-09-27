#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coinbot.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_btnUpdateSetting_pressed()
{
    qDebug() << "API KEY" + ui->txtApiKey->text();

    QString apiKey(ui->txtApiKey->text());
    QString secretKey(ui->txtSecretKey->text());

    QCoinBot CoinBot;

    QByteArray encodeApiKey  =  CoinBot.getEncryptedText(apiKey);
    QByteArray encodeSecretKey  =  CoinBot.getEncryptedText(secretKey);

    CoinBot.setBinanceApiKey(encodeApiKey);
    CoinBot.setBinanceSecretKey(encodeSecretKey);

    qDebug() << "encoded api key: " + CoinBot.getBinanceApiKey();
    qDebug() << "encoded secret key: " + CoinBot.getBinanceSecretKey();


}

void MainWindow::on_tabApp_currentChanged(int index)
{
    qDebug() << "Tab Opened";
}
