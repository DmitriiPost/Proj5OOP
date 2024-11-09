#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "..\proj5common\communicator.h"
#include "polynom.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TCommunicator *comm;

public:
    TApplication(int, char**);
    number* readArr(QString, int);

signals:

public slots:
    void receive(QByteArray);
};

#endif // APPLICATION_H
