#include "interfaceui.h"
#include <QDebug>
#include <mongomanager.h>
InterfaceUI::InterfaceUI(QObject *parent)
    : QObject{parent}
{
    monogo  = new MongoManager ("mongodb://localhost", "27017");
    if(monogo->connction())
        qDebug()<< "connected";
    else
        qDebug()<< "no connected";
}

void InterfaceUI::get_data(const QString &fname, const QString &lname, const QString &phone, const QString &email)
{
    qDebug() << fname << lname << phone << email;
}
