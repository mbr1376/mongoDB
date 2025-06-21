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
### linux (Debian)
```bash
$  apt update
$ wget -q0  - https://www.mongodb.org/static/pgp/

```
### Mac
```bash

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
# 
>
#
>
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