#include "mongomanager.h"
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
#include <QVariantMap>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

MongoManager::MongoManager(QString host, QString port, QObject *parent)
    :QObject{ parent},m_host{host},m_port{port}
{
    static mongocxx::instance instance{};
}

bool MongoManager::connction()
{
    std::string uri_str = (m_host + ":" + m_port).toStdString();
    m_client= mongocxx::client{mongocxx::uri{uri_str}};
    if (m_client.list_database_names().size() > 0){
        m_db = m_client["phoneDatabse"];
        m_collection = m_db["phoneCollction"];

        return true;
    }
    return false;
}

void MongoManager::addToDatabase(const bsoncxx::v_noabi::builder::stream::document &document)
{
    m_collection.insert_one(document.view());
}

void MongoManager::deleteItem(int id)
{
    m_collection.delete_one(make_document(kvp("id",id)));
}

void MongoManager::updateItem(int id, QString name, QString lName, QString phone, QString email)
{
    auto filter = make_document(kvp("id", id));

    auto update = make_document(
        kvp("$set", make_document(
                        kvp("FirstName", name.toStdString()),
                        kvp("LastName", lName.toStdString()),
                        kvp("PhoneNumber", phone.toStdString()),
                        kvp("email", email.toStdString())
                        ))
        );
    m_collection.update_one(filter.view(),update.view());
}


QList <QVariantMap>  MongoManager::search(const QString &name)
{
    QList <QVariantMap> results;
    auto filter = make_document(kvp("FirstName", name.toStdString()));

    mongocxx::cursor cursor = m_collection.find(filter.view());

    for (auto &&doc : cursor) {
        QVariantMap item;
        for (auto &&el : doc) {
            // Convert BSON to QVariant
            std::string key(el.key().data(), el.key().size());

            auto value = el.get_value();
            if (value.type() == bsoncxx::type::k_string) {
                std::string str(value.get_string().value);       // ensure it's std::string
                item[QString::fromStdString(key)] = QString::fromStdString(str);
            }
            else if (value.type() == bsoncxx::type::k_int32) {
                item[QString::fromStdString(key)] = value.get_int32().value;
            } else if (value.type() == bsoncxx::type::k_int64) {
                item[QString::fromStdString(key)] = static_cast<qlonglong>(value.get_int64());
            }
            // You can add more BSON → QVariant conversions here
        }
        results.append(item);
    }

    return results;
}

QList<QVariantMap> MongoManager::data()
{
    QList <QVariantMap> results;

    mongocxx::cursor cursor = m_collection.find({});
    for (auto &&doc : cursor) {
        QVariantMap item;
        for (auto &&el : doc) {
            // Convert BSON to QVariant
            std::string key(el.key().data(), el.key().size());

            auto value = el.get_value();
            if (value.type() == bsoncxx::type::k_string) {
                std::string str(value.get_string().value);       // ensure it's std::string
                item[QString::fromStdString(key)] = QString::fromStdString(str);
            }
            else if (value.type() == bsoncxx::type::k_int32) {
                item[QString::fromStdString(key)] = value.get_int32().value;
            } else if (value.type() == bsoncxx::type::k_int64) {
                item[QString::fromStdString(key)] = static_cast<qlonglong>(value.get_int64());
            }
            // You can add more BSON → QVariant conversions here
        }
        results.append(item);
    }

    return results;
}

void MongoManager::deleteall()
{
    m_collection.delete_many({});
}
