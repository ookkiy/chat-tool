#include "dialog.h"
#include "ui_dialog.h"
#include<QHostAddress>
#include<QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //udp
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(closeBtn()));
    port1=2016;
    port2=2019;
    isStart=false;
    udpSocket=new QUdpSocket(this);

    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    bool result=udpSocket->bind(port2);//绑定到指定端口
    if(!result)
    {
        QMessageBox::information(this,tr("error!!!"),tr("udp socket create error!!!"));
        return;
    }
}

void Dialog::startBtnClicked()
{
   int length=0;
   QString userName="我";
   QString msg=ui->lineEdit->text();
   if(length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port1)!=msg.length())
       return;
   ui->textEdit->insertPlainText(userName+": "+ui->lineEdit->text()+"\n");
   ui->lineEdit->clear();
}

void Dialog::closeBtn()
{
    close();
}

void Dialog::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())//有数据报可读
    {
        QByteArray datagram;
        QString str="客户端";
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ui->textEdit->insertPlainText(str+": "+tr(msg.toStdString().c_str())+"\n");
    }
}

Dialog::~Dialog()
{
    delete ui;
}

