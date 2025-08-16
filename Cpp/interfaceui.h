#ifndef INTERFACEUI_H
#define INTERFACEUI_H

#include <QObject>
#include <mongomanager.h>

class InterfaceUI : public QObject
{
    Q_OBJECT
public:
    explicit InterfaceUI(QObject *parent = nullptr);

public slots:
Q_INVOKABLE void get_data(const QString &fname,const QString &lname,
                            const QString &phone,const QString &email
                              );

signals:

private:
    MongoManager * monogo;
    int m_id {0};
};

#endif // INTERFACEUI_H
