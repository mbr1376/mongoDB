#include "interfaceui.h"
#include <QDebug>
#include <mongomanager.h>
#include <listmodel.h>
InterfaceUI::InterfaceUI(MongoManager* mongo,ListModel * listmodel,QObject *parent)
    : QObject{parent},m_mongo{mongo},
    m_listmodel{listmodel}
{


}

void InterfaceUI::get_data(const QString &fname, const QString &lname, const QString &phone, const QString &email)
{
    // bsoncxx::builder::stream::document doc{};
    // doc << "id" << m_id
    //     << "FirstName" << fname
    //     << "LastName" << lname
    //     << "PhoneNumber" << phone
    // << "email" << email;

    //monogo->addToDatabase(doc);
    //qDebug() << fname << lname << phone << email;
}
