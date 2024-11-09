#include "interface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(500, 300);
    setWindowTitle("Polynom");

    polynom_degree = new QLabel("Polynom degree:", this);
    polynom_degree->setGeometry(20, 20, 90, 25);
    size = new QSpinBox(this);
    size->setGeometry(120, 20, 40, 25);

    a_n = new QLabel("Senior coeff =", this);
    a_n->setGeometry(20, 50, 100, 25);

    sen_coeff_re = new QLineEdit("1", this);
    sen_coeff_re->setGeometry(100, 50, 20, 25);

    sen_coeff_im = new QLineEdit("0", this);
    sen_coeff_im->setGeometry(130, 50, 20, 25);

    polynom_roots = new QLabel("Polynom roots:", this);
    polynom_roots->setGeometry(20, 80, 100, 25);

    elems = new QLineEdit("1 0", this);
    elems->setGeometry(20, 110, 200, 25);

    x_Label = new QLabel("x =", this);
    x_Label->setGeometry(20, 140, 20, 25);

    x_re = new QLineEdit("1", this);
    x_re->setGeometry(50, 140, 20, 25);

    x_im = new QLineEdit("0", this);
    x_im->setGeometry(80, 140, 20, 25);

    canon_polynom_btn = new QPushButton("Canon", this);
    canon_polynom_btn->setGeometry(400, 50, 90, 30);

    clas_polynom_btn = new QPushButton("Classic", this);
    clas_polynom_btn->setGeometry(400, 85, 90, 30);

    calc_polynom_btn = new QPushButton("Calc polynom", this);
    calc_polynom_btn->setGeometry(400, 120, 90, 30);

    output = new QLabel(this);
    output->setGeometry(20, 230, 470, 70);

    //connect(canon_polynom_btn, SIGNAL(pressed()), this, SLOT(printCanon()));
    //connect(clas_polynom_btn, SIGNAL(pressed()), this, SLOT(printClassic()));
    //connect(calc_polynom_btn, SIGNAL(pressed()), this, SLOT(calcPolynom()));
    connect(canon_polynom_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(clas_polynom_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(calc_polynom_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface() {
    delete polynom_degree;
    delete polynom_roots;
    delete a_n;
    delete sen_coeff_re;
    delete sen_coeff_im;
    delete size;
    delete elems;
    delete x_Label;
    delete x_re;
    delete x_im;
    delete output;
    delete canon_polynom_btn;
    delete clas_polynom_btn;
    delete calc_polynom_btn;
}

/*number* TInterface::readArr(){
    QString s = elems->text();
    int sizeArr = size->text().toInt();
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
}*/

/*void TInterface::printCanon() {
    QString s;
    s += "Polynom: ";
    double seniorCoeff_re, seniorCoeff_im;
    seniorCoeff_re = sen_coeff_re->text().toDouble();
    seniorCoeff_im = sen_coeff_im->text().toDouble();
    number seniorCoeff(seniorCoeff_re, seniorCoeff_im);
    int sizeArr = size->text().toInt();
    number* arr = readArr();
    TPolynom p(seniorCoeff, arr, sizeArr);
    s += p.polynomCanonToQString();
    output->setText(s);
} */

/*void TInterface::printClassic() {
    QString s;
    s += "Polynom: ";
    double seniorCoeff_re, seniorCoeff_im;
    seniorCoeff_re = sen_coeff_re->text().toDouble();
    seniorCoeff_im = sen_coeff_im->text().toDouble();
    number seniorCoeff(seniorCoeff_re, seniorCoeff_im);
    int sizeArr = size->text().toInt();
    number* arr = readArr();
    TPolynom p(seniorCoeff, arr, sizeArr);
    s += p.polynomClassicToQString();
    output->setText(s);
} */

/*void TInterface::calcPolynom() {
    QString s;
    s += "Polynom at x: ";
    double seniorCoeff_re, seniorCoeff_im;
    seniorCoeff_re = sen_coeff_re->text().toDouble();
    seniorCoeff_im = sen_coeff_im->text().toDouble();
    number seniorCoeff(seniorCoeff_re, seniorCoeff_im);

    double dot_re, dot_im;
    dot_re = x_re->text().toDouble();
    dot_im = x_im->text().toDouble();
    number dot(dot_re, dot_im);

    int sizeArr = size->text().toInt();
    number* arr = readArr();
    TPolynom p(seniorCoeff, arr, sizeArr);
    s << p.calcPolynom(dot);
    output->setText(s);
} */
// sizeArr;sen_coef_re sen_coef_im;x_re x_im;arr;btn_num
void TInterface::formRequest() {
    QString msg;
    QString sizeArr = size->text();
    msg += sizeArr;
    msg += ";";
    QString seniorCoeff_re, seniorCoeff_im;
    seniorCoeff_re = sen_coeff_re->text();
    seniorCoeff_im = sen_coeff_im->text();
    msg += seniorCoeff_re;
    msg += " ";
    msg += seniorCoeff_im;
    msg += ";";

    QString dot_re, dot_im;
    dot_re = x_re->text();
    dot_im = x_im->text();
    msg += dot_re;
    msg += " ";
    msg += dot_im;
    msg += ";";

    QString arr = elems->text();
    msg += arr;
    msg += ";";

    QPushButton *btn = (QPushButton*)sender();
    if (btn == canon_polynom_btn)
    {
        msg += QString().setNum(1);
    }
    if (btn == clas_polynom_btn)
    {
        msg += QString().setNum(2);
    }
    if (btn == calc_polynom_btn)
    {
        msg += QString().setNum(3);
    }
    emit request(msg);
}

void TInterface::answer(QString msg) {
    QString text;
    int btn = msg.split(";")[0].toInt();
    switch (btn) {
    case (1):
        text += "Polynom: ";
        break;
    case (2):
        text += "Polynom: ";
        break;
    case (3):
        text += "Polynom at x: ";
        break;
    default:
        break;
    }
    text += msg.split(";")[1];
    output->setText(text);
}
