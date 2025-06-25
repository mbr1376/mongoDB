import backmongo as bm

if __name__ == "__main__":
    print("test mongo")
    mongo= bm.BackMongo('localhost',27017)
    if (mongo.connction()):
        mongo.remove_all()
        print("is connected")
        dic = {"id":0,"name":"ali"}
        mongo.add_to_database(dic)
    
    print(mongo.display_data())
    print(mongo.search("ali"))