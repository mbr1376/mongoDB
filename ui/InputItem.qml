import QtQuick
import QtQuick.Controls.Basic 
import QtQuick.Layouts 

Rectangle {
    id: box

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
        height :120   
        width : box.width -10
     }
     RemoveData{
         height :70   
        width :box.width -10
     }
    }
}