import pymongo as  mng

class BackMongo:
    def __init__(self,host,port):
        self._hsot = host
        self._port = port
    def connction (self):
        self._client = mng.MongoClient(self._hsot,self._port)
        if (len(self._client.list_database_names()) > 0 ):
                self._db = self._client["phoneDatabse"]
                self._collectoiton  = self._db["phoneCollction"]
                return True
        return False
    def add_to_database(self,dic):
         self._collectoiton.insert_one(dic)
    def delete_to_databasea(self,id):
        self._collectoiton.delete_one({"id":id})
    
    
    def search(self,name):
       dictionry =[]
       for doc in self._collectoiton.find({"FirstName":name}):
           dictionry.append(doc)
       return dictionry

    def display_data(self):
        dictionty =[]
        for doc in self._collectoiton.find():
            dictionty.append(doc)
        return dictionty
    
    def remove_all(self):
        self._collectoiton.delete_many({})
    
    def remove(self,name):
        self._collectoiton.delete_one({"id":name})