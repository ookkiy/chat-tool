#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

    void getHostInfo();

    ~Dialog();

private:
    Ui::Dialog *ui;
    //udp
    int port1,port2;
    QUdpSocket * udpSocket;
private slots:
    void slotDetail();
    //udp
    void closeBtnClicked();
    void dataReceived();
    void startBtnClicked();
};
#endif // DIALOG_H
