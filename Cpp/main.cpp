#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "listmodel.h"
#include "interfaceui.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    InterfaceUI *interface = new InterfaceUI;
    engine.rootContext()->setContextProperty("_interface",interface);
    engine.loadFromModule("Cpp", "Main");

    return app.exec();
}
