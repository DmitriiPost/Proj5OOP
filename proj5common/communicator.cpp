#include "communicator.h"

TCommunicator::TCommunicator(TCommParams& pars, QObject *parent) : QUdpSocket(parent)
{
    params = pars;
    ready = bind(params.rHost, params.rPort,
                 QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    if (ready) connect(this,SIGNAL(readyRead()),this,SLOT(recieve()));
}

bool TCommunicator::isReady()
{
    return ready;
}

void TCommunicator::send(QString msg)
{
    if (ready)
    {
        QByteArray msg_arr = msg.toLocal8Bit();
        writeDatagram(msg_arr, params.sHost, params.sPort);
        //qDebug()<<"sended"<<msg;
    }
}

void TCommunicator::recieve()
{
    if (hasPendingDatagrams())
    {
        quint64 size = pendingDatagramSize();
        QByteArray msg_arr(size, '\0');
        readDatagram(msg_arr.data(), size);
        //qDebug()<<"recieved"<<msg;
        emit recieved(msg_arr);
    }
}
