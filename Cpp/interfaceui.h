#ifndef INTERFACEUI_H
#define INTERFACEUI_H

#include <QObject>
#include <mongomanager.h>
#include "listmodel.h"
class InterfaceUI : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceUI(MongoManager* mongo,ListModel * listmodel,QObject *parent = nullptr);

public slots:
Q_INVOKABLE void get_data(const QString &fname,const QString &lname,
                            const QString &phone,const QString &email
                              );

    Q_INVOKABLE void search(const QString &txt);
    Q_INVOKABLE void clearSearch();
Q_INVOKABLE void update(int id,const QString &fname,
                        const QString &lname,
                        const QString &phone,
                        const QString &email);
    Q_INVOKABLE void remove(int id);
    Q_INVOKABLE void removeAll();

signals:

private:
    MongoManager* m_mongo;
    ListModel * m_listmodel;
    int m_id {0};

    QList <Item> convertMaptoItem(QList<QVariantMap> &list);
};

#endif // INTERFACEUI_H
