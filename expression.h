#ifndef EXPRESSION_H
#define EXPRESSION_H

//Core
#include <QString>
#include <QObject>
#include <QDebug>

//C++ Core
#include <iostream>
#include <math.h>

//Custom
#include "math_property.h"

using namespace std;

class Expression : public QObject, public Math_Property
{
    Q_OBJECT

public:

    Expression(QString ex);

    //Inherit by Math_Property
    QString dump();
    double value();

    QString getMathExpression() const;
    void setMathExpression(const QString &value);

private:

    QString mathExpression;

};

#endif // EXPRESSION_H
