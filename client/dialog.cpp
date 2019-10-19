#include "dialog.h"
#include "ui_dialog.h"
#include<QHostInfo>
#include<QNetworkInterface>
#include<QMessageBox>
#include<QHostAddress>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    getHostInfo();
    connect(ui->hostInfo,SIGNAL(clicked()),this,SLOT(slotDetail()));
    //udp
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(closeBtnClicked()));
    port1=2016;
    port2=2019;
    udpSocket=new QUdpSocket(this);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    bool result=udpSocket->bind(port1);//绑定到指定端口
    if(!result)
    {
        QMessageBox::information(this,tr("error!!!"),tr("udp socket create error!!!"));
        return;
    }
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(startBtnClicked()));
}

void Dialog::getHostInfo()
{
    QString localHostName=QHostInfo::localHostName();
    ui->hostName->setText(localHostName);
    QHostInfo hostInfo=QHostInfo::fromName(localHostName);  //获取主机IP列表
    QList<QHostAddress> listAddress=hostInfo.addresses();
    if(!listAddress.isEmpty())
        ui->ipAddr->setText(listAddress.first().toString());
}

void Dialog::slotDetail()
{
    QString detail="";
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();
    for(int i=0;i<list.count();i++)
    {
        QNetworkInterface interface=list.at(i);
        detail=detail+tr("设备：")+interface.name()+"\n";  //网络接口名称
        detail=detail+tr("硬件地址:")+interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList=interface.addressEntries();
        for(int j=0;j<entryList.count();j++)
        {
            QNetworkAddressEntry entry=entryList.at(j);
            detail=detail+"\t"+tr("ip地址:")+entry.ip().toString()+"\n";
            detail=detail+"\t"+tr("子网掩码：")+entry.netmask().toString()+"\n";
            detail=detail+"\t"+tr("广播地址：")+entry.broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,tr("Detail"),detail);
}

void Dialog::closeBtnClicked()
{
    close();
}

void Dialog::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())//有数据报可读
    {
        QByteArray datagram;
        QString userName="服务端";
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ui->textEdit->insertPlainText(userName+": "+tr(msg.toStdString().c_str())+"\n");
    }
}

void Dialog::startBtnClicked()
{
   int length=0;
   QString userName="我";
   QString msg=ui->lineEdit->text();
   if(length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port2)!=msg.length())
       return;
   ui->textEdit->insertPlainText(userName+": "+ui->lineEdit->text()+"\n");
   ui->lineEdit->clear();
}

Dialog::~Dialog()
{
    delete ui;
}

