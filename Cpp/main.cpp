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
    MongoManager * monogo = new MongoManager ("mongodb://localhost", "27017");
    ListModel * listmodel;
    if(monogo->connction()){
        qDebug()<< "connected";
        QList <QVariantMap> list = monogo->data();
        QList <Item> listItem;
        foreach (QVariantMap var, list) {
            Item item;
            item.FirstName = var["FirstName"].toString();
            item.LastName = var["LastName"].toString();
            item.email = var["email"].toString();
            item.PhoneNumber = var["PhoneNumber"].toString();
            item.id = var["id"].toInt();
            listItem.append(item);

        }
        listmodel = new ListModel(listItem);
        engine.rootContext()->setContextProperty("mymodel",listmodel);

    }else
        qDebug()<< "no connected";
    InterfaceUI *interface = new InterfaceUI(monogo,listmodel);
    engine.rootContext()->setContextProperty("_interface",interface);
    engine.loadFromModule("Cpp", "Main");

    return app.exec();
}
