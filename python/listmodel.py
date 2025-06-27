from PySide6.QtCore import QAbstractListModel, QModelIndex, Qt

class ListModel(QAbstractListModel):
    def __init__(self, data, parent = None):
        super().__init__(parent)
        self._data = data
    def rowCount(self, parent=QModelIndex()):
        return len(self._data)

    def data(self, index, role=Qt.DisplayRole):
        if not index.isValid() or index.row() >= len(self._data):
            return None 

        item = self._data[index.row()]
        if role == Qt.DisplayRole:
            return item.get("FirstName") 
        elif role == Qt.UserRole + 1:
            return item.get("LastName") 
        elif role == Qt.UserRole + 2:
            return item.get("PhoneNumber")  
        elif role == Qt.UserRole + 3:
            return item.get("email")  
        elif role == Qt.UserRole + 4:
            return item.get("id")  
        return None

    def roleNames(self):
        roles = {
            Qt.DisplayRole: b"FirstName",
            Qt.UserRole + 1: b"LastName",
            Qt.UserRole + 2: b"PhoneNumber",
            Qt.UserRole + 3: b"email",
            Qt.UserRole + 4: b"id",
        }
        return roles
    
    def setDataList(self, new_data):
        """Replace current data and notify view."""
        self.beginResetModel()
        self._data = new_data
        self.endResetModel()

    def refreshFromMongo(self, mongo_data):
        self.setDataList(mongo_data) 