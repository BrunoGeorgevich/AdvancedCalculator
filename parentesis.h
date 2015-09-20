#ifndef PARENTESIS_H
#define PARENTESIS_H

//Core
#include <QString>
#include <QObject>
#include <QDebug>
#include <QStack>

//C++ Core
#include <iostream>

//Custom
#include "expression.h"

using namespace std;

class Parentesis : public QObject, public Math_Property
{
    Q_OBJECT

public:

    Parentesis();

    //Inherit by Math_Property
    QString dump();
    double value();

    void add(Math_Property *ex, QString op);
    void print();
    void clear();

    static Parentesis *evaluate(QString ex);

private:

    QList<Math_Property *> expressions;
    QList<QString> conectors;
};

#endif // PARENTESIS_H
