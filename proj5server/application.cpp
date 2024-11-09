#include "application.h"
#include <QString>
#include "polynom.h"
TApplication::TApplication(int argc, char *argv[])
    : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                        QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm, SIGNAL(recieved(QByteArray)), this, SLOT(receive(QByteArray)));
}

void TApplication::receive(QByteArray msg_arr) {
    QString msg = QString(msg_arr);
    QString answer;
    int sizeArr, btn;
    QStringList strList = msg.split(";");
    sizeArr = strList[0].toInt();
    QString senCoeff = strList[1];
    double senCoeff_re = strList[1].split(" ")[0].toDouble();
    double senCoeff_im = strList[1].split(" ")[1].toDouble();
    number seniorCoeff(senCoeff_re, senCoeff_im);

    QString dot = strList[2];
    double x_re = strList[2].split(" ")[0].toDouble();
    double x_im = strList[2].split(" ")[1].toDouble();
    number x(x_re, x_im);

    QString arr_str = strList[3];
    number* arr = readArr(arr_str, sizeArr);
    TPolynom p(seniorCoeff, arr, sizeArr);

    btn = strList[4].toInt();
    answer += QString().setNum(btn);
    answer += ";";
    switch (btn) {
    case (1):
        answer += p.polynomCanonToQString();
        break;
    case (2):
        answer += p.polynomClassicToQString();
        break;
    case (3):
        answer << p.calcPolynom(x);
        break;
    default:
        answer += "Error: no such button...";
        break;
    }
    comm->send(answer);
}

number* TApplication::readArr(QString s, int sizeArr) {
    number* arr = new number[sizeArr];
    QStringList strList = s.split(" ");
    int rootsLen = strList.length();
    if (rootsLen > sizeArr * 2)
    {
        rootsLen = sizeArr * 2;
    }
    for (int i = 0; i < rootsLen; i+=2) {
        if (i + 1 >= rootsLen)
        {
            break;
        }
        double elem_re, elem_im;
        elem_re = strList[i].toDouble();
        elem_im = strList[i + 1].toDouble();
        number elem(elem_re, elem_im);
        arr[int(i / 2)] = elem;
    }
    if (sizeArr * 2 > rootsLen)
    {
        for (int i = rootsLen; i < sizeArr; i+= 2)
        {
            arr[int(i / 2)] = 0;
        }
    }
    return arr;
}
