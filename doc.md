# Document mongoDB
## MonogDB
1. like json file
2. save Document
3. openSource
4. big Data 
### Data Struct
```json
{
    "id":1
    "first name": "ali"
    "last name " : "sarabi"

}
```
## Install 
###  Windows
***[link download](http://www.mongodb.com/try/download)***
### linux (ubuntu 24.04)
```bash
$  sudo apt-get install gnupg curl
$ curl -fsSL https://www.mongodb.org/static/pgp/server-8.0.asc | \
   sudo gpg -o /usr/share/keyrings/mongodb-server-8.0.gpg \
   --dearmor
$  echo "deb [ arch=amd64,arm64 signed-by=/usr/share/keyrings/mongodb-server-8.0.gpg ] https://repo.mongodb.org/apt/ubuntu noble/mongodb-org/8.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-8.0.list
$ sudo apt-get update
$ sudo apt-get install -y mongodb-org
```
*** start mongo***
```bash
$ sudo systemctl start mongod
#! note:  if Error (Failed to start mongod.service: Unit mongod.service not found.)
$ sudo systemctl daemon-reload
```
### Mac
***use brew***
```bash
$ brew tap mongodb/brew
$ brew update
$ brew install mongodb-community

```

## IDE
***Studio 3T***
[link Download](https://www.studio3t.com/download)

## Command Line
***Creat and Delete***
```bash
$ mongo
# show list Database
> show dbs
# Creat Database and  enter Database
# !note add data to DataBase (show list Database) 
> use <namedatabae>
# delete Database
> use <namedatabae>
> db.dropDatabase()
```
***insert Data***
```bash
$ mongo
#  save Date in Collection(table) multi json  Document(record) feild(column)
> use <name>
# Create Collection
> db.createCollection("name")
# show Collection
> show collections 
#  insert in Collection
> db.<namecollection>.insert({"feild":"value", .......})
# remove all Documents
> db.<name>.remove({})  

# insert multi Document (tools) 
$ mognoimport --db nameDatabse --collection namecollection --file file.json
# show Document
$ monog
> use nameDatabase
> db.nameCollection.find().pretty()
# update Document
> db.nameCollectio.update({"feildUpdate":"value"},{$set:{"feildUpdate":"newValue"}})
# use save for update (!note insert)
> db.nameCollection.save({"_id":Objectid("kfhf.."),"feildName": "newValue"})
# remove one Document
> db.nameCollection.remove({"feildname":"value"})
# remove collection
> db.nameCollection.drop()
```
***display sort filter***
```bash
# display one document
> db.name.findOne()
# display all documet
# !note it more document
> db.name.find()
# display field
#!note first {} for  condition {} secend {} for field
#!note 1:true 0:false
> db.name.find({},{"f1":1,"f2":1,"f2":0})
# condition 
#!note limit for show count
> db.name.find({"f1":"condition"}).limit(5)
> db.name.find({"f1":"condition"}).skip(5).limit(5)
# lt: < 
# lte: <= 
# gt: > 
# gte: >= 
# lt: < 
> db.name.find({"f1":{$lt:200}})
# sort 1 or -1
> db.name.find().sort("f1":1)
```
***Aggregation***
search for Document 
```bash
# match and group
 > db.name.aggregate([{$match:{"f1":"value"}}])
 > db.name.aggregate([{$match:{"f1":"value"}},{$group:{_id:"$field"}}])
 > db.name.aggregate([{$match:{}},{$group:{_id:"$field"}}])
 # min ,max ,sum
 > db.name.aggregate([{$match:{}},{$group:{_id:null,"result":{$min:"$field"}}}])
# list value
 > db.name.distinct("field")
```
***Search in Text ***
```bash
# for search in text  create index
#! searh just for String
$ db.name.createIndex({"field":"text",.... })
$ db.name.find({$text:{$search:"str"}})
```
## Sharding
process save Data in  multi server 
#### save Data
1.Vertical : all Date one node (server) sampel: (mysql)
2.Horizontal : all Data multi node 

#### replication
copy Data and  save multi server
****Replica set = count(1,2, .....)****
  
## backup and Restore
***using binery mongodump and mongorestore***
```bash
$ mongodump --db nameDatabase
#restore
$ mongorestore -db newdabse path
```

# use in  python
## install 
 ```bash
 $ pip install pymongo
 ```
 ***use***
 ```python
 # connection
    import pymongo as  mongo
    # localhost , 27017
    client = mongo.MongoClient('localhost',27017)
    #client = mongo.MongoClient()
    #client = mongo.MongoClient('monogodb://localhost:27017')
    db = client["nameDatabse"]
    # list Database
    print(client.list_database_names())
 ```
Creat Databse
```python
    import pymongo as  mongo
    # localhost , 27017
    client = mongo.MongoClient('localhost',27017)
    db = client["newDatabase"] # create Database
    col = db["newCollection"] # create collection
    print (client.list_database_name())
``` 
insert Dcoument in Database
```python

    import pymongo as  mongo
    import json
    # localhost , 27017
    client = mongo.MongoClient('localhost',27017)
    db = client["Database"] # 
    col = db["Collection"] # 
    # for insert create dictionry
    dic = {"firstName": "jone","lastName":"jori"}
    col.insert_one(dic)
     # create multi Document
    lsitdic =[ {"firstName": "jone","lastName":"jori"}, {"firstName": "jone","lastName":"jori"} {"firstName": "jone","lastName":"jori"}]
    col.insert_many(listdic)

    # read Document in file
    whit open("path")as  file:
        data = [json_load(line) for line in file]
    col.insert_many(data)

    ## show Document
    result = col.find_one() # one  Document
    print (result)
    for Doc in col.find(): # all Document
        print(Doc)
```
Mange DataBase 
```python

    import pymongo as  mongo
    import json
    # localhost , 27017
    client = mongo.MongoClient('localhost',27017)
    db = client["Database"] # 
    col = db["Collection"] # 
    
    dic = col.find().sort("fieldname") # sort
    
    col.delete_one({"feildnae":"value"}) # remove
    col.delete_many({}}) # remove all

    # remove collection
    col.drop()

    # update
     col .update_one({"feildname":"value"},{"$set":{"feildname":"newvalue"}})
     col .update_many({},{"$set":{"feildname":"newvalue"}})

     result = col.find().limit(2)
```

# use in Cpp
## instal
***linux***
```bash
$ sudo apt install libmongoc-1.0-0 libmongoc-dev libbson-dev
# or manual install
$ git clone https://github.com/mongodb/mongo-cxx-driver.git --branch releases/stable

$ cd  mongo-cxx-driver/build 
$ cmake ..                                  \
    -DCMAKE_BUILD_TYPE=Release            \
    -DCMAKE_INSTALL_PREFIX=/usr/local     \
    -DBUILD_SHARED_LIBS=ON
$ sudo make -j4 install
```
***mac***
```bash
$ brew install mongo-c-driver
$ brew install mongo-cxx-driver
```
***Use***
add library to  cmake
```cmake
find_package(mongocxx REQUIRED)
```
```cpp
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
// connect to  mongo
    static mongocxx::instance instance{}; // Required once in your app

    mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};
    auto db = client["mydb"];
    auto collection = db["mycollection"];
    // List databases
    auto dbs = client.list_databases();
    for (const auto& db : dbs) {
        qDebug() << "Database:" << QString::fromStdString(db["name"].get_utf8().value.to_string());
    }
```
insert Dcoument in Database
```cpp
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
// connect to  mongo
    static mongocxx::instance instance{}; // Required once in your app

    mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};
    auto db = client["mydb"];
    auto collection = db["mycollection"];
    bsoncxx::builder::stream::document document{};
    document << "name" << "MacUser" << "language" << "C++";
    collection.insert_one(document.view());
```