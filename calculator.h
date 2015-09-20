#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

#include "parentesis.h"

class Calculator : public QObject
{
    Q_OBJECT
public:

    Calculator();

    Q_INVOKABLE void clear();
    Q_INVOKABLE double calculate(QString fullExp);

signals:

public slots:

private:

    Parentesis *mainParentesis;
};

#endif // CALCULATOR_H
