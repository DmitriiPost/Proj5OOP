#include "application.h"

TApplication::TApplication(int argc, char *argv[])
    : QApplication(argc, argv)
{
    TCommParams pars = {
        QHostAddress("127.0.0.1"), 10001,
        QHostAddress("127.0.0.1"), 10000};
    comm = new TCommunicator(pars, this);

    interface = new TInterface();
    interface->show();

    connect(comm,SIGNAL(recieved(QByteArray)),this,
            SLOT(fromCommunicator(QByteArray)));
    connect(interface,SIGNAL(request(QString)),
            this,SLOT(toCommunicator(QString)));
}

void TApplication::fromCommunicator(QByteArray msg_arr) {
    interface->answer(QString(msg_arr));
}

void TApplication::toCommunicator(QString msg) {
    QByteArray msg_arr = msg.toLocal8Bit();
    comm->send(msg_arr);
}
