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
     bsoncxx::builder::stream::document doc{};
     doc << "id" << m_id
         << "FirstName" << fname.toStdString()
         << "LastName" << lname.toStdString()
         << "PhoneNumber" << phone.toStdString()
     << "email" << email.toStdString();

    m_mongo->addToDatabase(doc);
     QList<QVariantMap> listmap = m_mongo->data();
    QList<Item> listItem;
    foreach (QVariantMap var, listmap) {
         Item item;
         item.FirstName = var["FirstName"].toString();
         item.LastName = var["LastName"].toString();
         item.email = var["email"].toString();
         item.PhoneNumber = var["PhoneNumber"].toString();
         item.id = var["id"].toInt();
         listItem.append(item);
    }
    m_listmodel->refreshFromMongo(listItem);
    //qDebug() << fname << lname << phone << email;
}
