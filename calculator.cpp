#include "calculator.h"

Calculator::Calculator(){}

void Calculator::clear()
{
    mainParentesis->clear();
}

double Calculator::calculate(QString fullExp)
{
    mainParentesis = mainParentesis->evaluate(fullExp);

    return mainParentesis->value();
}

