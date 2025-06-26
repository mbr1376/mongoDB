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
            return item.get("id") 
        elif role == Qt.UserRole + 1:
            return item.get("FirstName") 
        elif role == Qt.UserRole + 2:
            return item.get("LastName")  
        elif role == Qt.UserRole + 3:
            return item.get("PhoneNumber")  
        elif role == Qt.UserRole + 4:
            return item.get("email")  
        return None

    def roleNames(self):
        roles = {
            Qt.DisplayRole: b"id",
            Qt.UserRole + 1: b"FirstName",
            Qt.UserRole + 2: b"LastName",
            Qt.UserRole + 3: b"PhoneNumber",
            Qt.UserRole + 4: b"email",
        }
        return roles
    
    def setDataList(self, new_data):
        """Replace current data and notify view."""
        self.beginResetModel()
        self._data = new_data
        self.endResetModel()
        
    def refreshFromMongo(self, mongo_data):
        self.setDataList(mongo_data) 