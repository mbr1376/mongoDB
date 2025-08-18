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
    QList<Item> listItem = convertMaptoItem(listmap);

    m_listmodel->refreshFromMongo(listItem);
    //qDebug() << fname << lname << phone << email;
}

void InterfaceUI::search(const QString &txt)
{
    QList <QVariantMap> list =  m_mongo->search(txt);
    QList<Item> listItem = convertMaptoItem(list);
    m_listmodel->refreshFromMongo(QList<Item>());
    m_listmodel->refreshFromMongo(listItem);
}

void InterfaceUI::clearSearch()
{
   QList<QVariantMap> list= m_mongo->data();
    QList<Item> Items =convertMaptoItem(list);
   m_listmodel->refreshFromMongo(Items);
}

void InterfaceUI::update( int id,const QString &fname, const QString &lname, const QString &phone, const QString &email)
{
    m_mongo->updateItem(id,fname,lname,phone,email);
    clearSearch();
}

void InterfaceUI::remove(int id)
{
    m_mongo->deleteItem(id);
    clearSearch();
}

void InterfaceUI::removeAll()
{
    m_mongo->deleteall();
    clearSearch();
}

QList<Item> InterfaceUI::convertMaptoItem(QList<QVariantMap> &list)
{

    QList<Item> listItem;

    foreach (QVariantMap var, list) {
        Item item;
        item.FirstName = var["FirstName"].toString();
        item.LastName = var["LastName"].toString();
        item.email = var["email"].toString();
        item.PhoneNumber = var["PhoneNumber"].toString();
        item.id = var["id"].toInt();
        listItem.append(item);
    }
    return listItem;
}
