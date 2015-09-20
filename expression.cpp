#include "expression.h"

Expression::Expression(QString ex)
{
    qDebug() << ex;
    setMathExpression(ex);
}

QString Expression::dump()
{
    return mathExpression;
}

double Expression::value()
{
    QRegExp regExp("^\\d{1,}\.{0,1}\\d{0,}\\s{0,}[-,+,*,/,^,R]\\s{0,}\\d{0,}\.{0,1}\\d{0,}$");
    double value = 0;

    if(regExp.exactMatch(mathExpression)) {

        if(mathExpression.contains("+")) {
            QStringList aux = mathExpression.split("+");
            value += aux.at(0).toDouble() + aux.at(1).toDouble();
        }
        else if(mathExpression.contains("-")) {
            QStringList aux = mathExpression.split("-");
            value += aux.at(0).toDouble() - aux.at(1).toDouble();
        }
        else if(mathExpression.contains("*")) {
            QStringList aux = mathExpression.split("*");
            value += aux.at(0).toDouble() * aux.at(1).toDouble();
        }
        else if(mathExpression.contains("/")) {
            QStringList aux = mathExpression.split("/");
            value += aux.at(0).toDouble() / aux.at(1).toDouble();
        }
        else if(mathExpression.contains("^")) {
            QStringList aux = mathExpression.split("^");
            value += pow(aux.at(0).toDouble(), aux.at(1).toDouble());
        }
        else if(mathExpression.contains("R")) {
            QStringList aux = mathExpression.split("R");
            value += pow(aux.at(0).toDouble(), 1/aux.at(1).toDouble());
        }
    } else {
        value = mathExpression.toDouble();
    }

    return value;
}

QString Expression::getMathExpression() const
{
    return mathExpression;
}

void Expression::setMathExpression(const QString &value)
{
    QRegExp regExp("^\\d{1,}\.{0,1}\\d{0,}\\s{0,}[-,+,*,/,^,R]?\\s{0,}\\d{0,}\.{0,1}\\d{0,}$");

    if(regExp.exactMatch(value)) {
        mathExpression = value;
    } else {
        mathExpression = "";
        qDebug() << "Please, use a valid math expression!";
    }
}



