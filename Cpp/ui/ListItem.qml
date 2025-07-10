import QtQuick 
import QtQuick.Controls 
import QtQuick.Layouts 

Rectangle {
            signal itemClicked(id:int,name:string,family:string,phone:string,email:string)
            id: boxperson
            radius: 5
            border.color: "#f76206"
            border.width: 2
            color: "#55ffffff"
           
            ListView {
                id: listView
                anchors.fill: parent
                anchors.margins: 10
                clip: true
                spacing: 10
                model:mymodel
                delegate: Rectangle {
                    height: 100
                    color: "#f76206"
                    radius: 5
                  property int _id : id
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    anchors.leftMargin: 5

                    GridLayout {
                         id: row1
                         rows:2
                         columns:4
                        rowSpacing :2
                        columnSpacing:2
                        anchors.fill :parent
                        MouseArea{
                           anchors.fill: parent
                           onClicked:{
                              itemClicked(_id,_firstname.text,_lastname.text,_phone.text,_email.text)
                              ///console.log(_id,_firstname.text,_lastname.text,_phone.text,_email.text)
                           }
                        }                         
                         Image{
                            Layout.maximumWidth:24
                            Layout.maximumHeight:24
                            fillMode: Image.PreserveAspectFit
                            source:"./icon/contact.png"
                            Layout.row :0
                            Layout.column:0
                            
                         }
                         Text{
                           id:_firstname
                            Layout.row :0
                            Layout.column:1
                            text:FirstName
                            color:"#FFFFFF"
                         }
                         Image{
                            Layout.maximumWidth:24
                            Layout.maximumHeight:24
                            fillMode: Image.PreserveAspectFit
                            source:"./icon/contact.png"
                            Layout.row :0
                            Layout.column:2
                            
                         }
                         Text{
                           id:_lastname
                            Layout.row :0
                            Layout.column:3
                            text:LastName
                            color:"#FFFFFF"
                         }
                        Image{
                            Layout.maximumWidth:24
                            Layout.maximumHeight:24
                            fillMode: Image.PreserveAspectFit
                            source:"./icon/phone.png"
                            Layout.row :1
                            Layout.column:0
                            
                        }
                        Text{
                           id:_phone
                            Layout.row :1
                            Layout.column:1
                            text:PhoneNumber
                            color:"#FFFFFF"
                         }
                        Image{
                            Layout.maximumWidth:24
                            Layout.maximumHeight:24
                            fillMode: Image.PreserveAspectFit   
                            source:"./icon/email.png"
                            Layout.row :1
                            Layout.column:2
                            
                         }
                        Text{
                           id:_email
                            Layout.row :1
                            Layout.column:3
                            text: email
                            color:"#FFFFFF"
                         }

                    }
                }
            }
        }
