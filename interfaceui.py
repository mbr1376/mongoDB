from PySide6.QtCore  import QObject ,Slot,Signal,Property
from PySide6.QtQml import QQmlApplicationEngine, qmlRegisterType

class InterFaceUi(QObject):
    dataSignal = Signal(dict)
    updateSignal = Signal(int,dict)
    searchSignal = Signal(str)
    clearSearchSignal = Signal()
    removeAllSignal = Signal()
    removeSignal = Signal(int)
    def __init__(self,parent=None):
        super().__init__(parent)
        self._id = 0
        self._data = {}
    @Slot(str,str,str,str)
    def get_data(self,fname,lname,phone,email):
        self._id +=1
        dic = {"id":self._id,
               "FirstName":fname,
               "LastName":lname,
               "PhoneNumber":phone,
               "email":email}  
        self.dataSignal.emit(dic) 
    @Slot(int,str,str,str,str)
    def update(self,id,fname,lname,phone,email):
        
        dic = {"FirstName":fname,
               "LastName":lname,
               "PhoneNumber":phone,
               "email":email}  
        self.updateSignal.emit(id,dic)
    @Slot(str)
    def search(self ,name):
        self.searchSignal.emit(name)
    @Slot()
    def clearSearch(self ):
        self.clearSearchSignal.emit()
    @Slot()
    def removeAll(self ):
        self.removeAllSignal.emit()
    @Slot(int)
    def remove(self,id ):
        self.removeSignal.emit(id)