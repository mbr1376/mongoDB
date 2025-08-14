#include "listmodel.h"

ListModel::ListModel(QObject *parent)
    : QAbstractListModel{parent}
{}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return m_items.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    const Item &item = m_items[index.row()];
    if (role == Qt::DisplayRole) return item.FirstName;
    if (role == Qt::UserRole +1) return item.LastName;
    if (role == Qt::UserRole +2) return item.PhoneNumber;
    if (role == Qt::UserRole +3) return item.email;
    if (role == Qt::UserRole +4) return item.id;

    return {};

}

QHash<int, QByteArray> ListModel::roleNames() const
{
    return {{FirstName,"FirstName"},
            {LastName,"LastName"},
            {PhoneNumber,"PhoneNumber"},
            {email,"email"},
            {id,"id"}};
}
