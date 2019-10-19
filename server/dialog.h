#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QUdpSocket>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    //udp
    void startBtnClicked();
    void dataReceived();
    void closeBtn();

private:
    Ui::Dialog *ui;
    //udp
    int port1,port2;
    bool isStart;
    QUdpSocket *udpSocket;

};
#endif // DIALOG_H
