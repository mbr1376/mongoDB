#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
struct Item
{
    QString FirstName;
    QString LastName;
    QString PhoneNumber;
    QString email;
    int  id;
};
class ListModel : public QAbstractListModel
{
    Q_OBJECT


public:
    enum Roles{
        FirstName,
        LastName = Qt::UserRole +1,
        PhoneNumber = Qt::UserRole +2,
        email = Qt::UserRole +3,
        id = Qt::UserRole +4
    };
    explicit ListModel(const QList <Item> &items, QObject *parent = nullptr);
    void refreshFromMongo(const QList<Item> &item);
protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;


signals:


private:
    QList<Item> m_items;
    void setDataList(const QList<Item> &items);
};

#endif // LISTMODEL_H
