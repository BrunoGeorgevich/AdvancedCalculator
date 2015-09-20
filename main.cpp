#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>

#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();

    Calculator *calc = new Calculator();

    ctx->setContextProperty("_calc", calc);
    engine.load(QUrl("qrc:/main.qml"));
    return a.exec();
}
