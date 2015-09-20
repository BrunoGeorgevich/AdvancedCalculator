#include "parentesis.h"

Parentesis::Parentesis(){}

void Parentesis::add(Math_Property *ex, QString op)
{
    if(!expressions.isEmpty())
        conectors.append(op);

    expressions.append(ex);
}

void Parentesis::print()
{
    qDebug() << "###############################";
    foreach (Math_Property *m, expressions) {
        Parentesis *p = (Parentesis *)m;
        qDebug() << p->value();
    }
    qDebug() << "###############################";
}

void Parentesis::clear()
{
    expressions.clear();
    conectors.clear();
}

QString Parentesis::dump()
{
    QString output = "";
    output.append("( ");

    for(int i = 0; i < expressions.length(); i++) {

        output.append(expressions.at(i)->dump() + " ");

        if(conectors.length() > i) {
            output.append(conectors.at(i));
            output.append(" ");
        }
    }

    output.append(")");

    return output;

}

double Parentesis::value()
{
    QString num = "";
    QString op = "";

    double value = 0;

    for( int i = 0; i < expressions.length(); i++ ) {

        if(i == 0)
            value =  expressions.at(i)->value();
        else
            op = conectors.at(i - 1);

        qDebug() << op;

        if(op == "+")
            value += expressions.at(i)->value();
        else if(op == "-")
            value -= expressions.at(i)->value();
        else if(op == "/")
            value /= expressions.at(i)->value();
        else if(op == "*")
            value *= expressions.at(i)->value();
        else if(op == "^")
            value = pow(value,expressions.at(i)->value());
        else if(op == "R")
            value = pow(value,1/expressions.at(i)->value());
    }

    return value;
}

Parentesis *Parentesis::evaluate(QString ex)
{
    ex.replace("+", ";+;");
    ex.replace("/", ";/;");
    ex.replace("*", ";*;");
    ex.replace("-", ";-;");
    ex.replace("^", ";^;");
    ex.replace("R", ";R;");

    QStringList snippets = ex
            .replace(" ","")
            .split(QRegExp("[;]"),
                   QString::SkipEmptyParts);

    Parentesis *mainParentesis = new Parentesis();
    QString op = "N";

    QRegExp isNum("^\\d{1,}\.{0,1}\\d{0,}$");
    QRegExp isOp("^[-,+,*,/,^,R]$");

    QStack<Parentesis *> stack;
    QStack<QString> parentesiOps;

    stack.append(mainParentesis);

    foreach (QString snippet, snippets) {
        if(snippet.contains("(")) {
            parentesiOps.push(op);
            for(int i = 0; i < snippet.count("("); i++) {
                stack.append(new Parentesis());
            }
        }

        QString aux = snippet;
        aux.remove(QRegExp("[(,)]"));


        if(isNum.exactMatch(aux)){
            stack.top()->add(new Expression(aux),op);
        } else if(isOp.exactMatch(aux)) {
            op = aux;
        }

        if(snippet.contains(")")) {
            for(int i = 0; i < snippet.count(")"); i++) {
                if(stack.top() != mainParentesis) {
                    Parentesis *ref = stack.top();
                    stack.pop();
                    stack.top()->add(ref,parentesiOps.top());
                }
            }
        }
    }

    return mainParentesis;
}

