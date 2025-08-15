#ifndef MONGOMANAGER_H
#define MONGOMANAGER_H

#include <QObject>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
class MongoManager :public QObject
{
   Q_OBJECT
    explicit MongoManager(QString host,QString port,QObject *parent= nullptr);
   bool connction();
   void addToDatabase (bsoncxx::builder::stream::document document);
   void deleteItem (int id);
   void updateItem (int id, QString name,QString lName,QString phone ,QString email);
   QList<QVariantMap> search(const QString &name);
   QList <QVariantMap> data();
   void deleteall();



private:
    mongocxx::client m_client;
    mongocxx::database m_db;
    mongocxx::collection m_collection;
    QString m_host{""};
    QString m_port{""};

};

#endif // MONGOMANAGER_H
