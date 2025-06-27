import QtQuick
import QtQuick.Controls.Basic 
import QtQuick.Layouts 

Rectangle {
    id: box
    signal itemClicked(id:int,name:string,family:string,phone:string,email:string)
    onItemClicked:function(id,firstname,lastname,phone,email){
                _update.set_date(id,firstname,lastname,phone,email)
                //console.log(id,firstname,lastname,phone,email)
                _remove._id = id
                _remove.name = firstname
            }
    width: parent.width /2 -5
    color: "#55ffffff"
    anchors.left: parent.left
    anchors.bottom: parent.bottom
    anchors.top :parent .top
    anchors.margins:5 
    
    radius: 5
    border.color: "#f76206"
    border.width: 2
    ColumnLayout{
        anchors.fill :parent
        anchors.margins:5
    
    SearchData{
        height :70   
        width :box.width -10
    }
     InsertData{
        height :120   
        width : box.width -10
     }
     UpdateData{
        id: _update
        height :120   
        width : box.width -10
     }
     RemoveData{
        id:_remove
         height :70   
        width :box.width -10
     }
    }
}