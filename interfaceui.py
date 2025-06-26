from PySide6.QtCore  import QObject ,Slot,Signal,Property
from PySide6.QtQml import QQmlApplicationEngine, qmlRegisterType

class InterFaceUi(QObject):
    dataSignal = Signal(dict)
    def __init__(self,parent=None):
        super().__init__(parent)
        self._id = 0
        self._data = {}
    @Slot(str,str,str,str,)
    def get_data(self,fname,lname,phone,email):
        self._id +=1
        dic = {"id":self._id,
               "FirstName":fname,
               "LastName":lname,
               "PhoneNumber":phone,
               "email":email}  
        self.dataSignal.emit(dic)
    
