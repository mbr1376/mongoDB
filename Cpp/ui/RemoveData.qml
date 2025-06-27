import QtQuick
import QtQuick.Controls.Basic 
import QtQuick.Layouts 
Rectangle{
   property int _id
   property string name: ""
   color:"#44252525"
   radius :5
   TextField{
         id:_name
         text: name
         anchors.verticalCenter: parent.verticalCenter
         anchors.left:parent.left
         anchors.leftMargin:5
         placeholderText: qsTr("Name")
         enabled:false
         background: Rectangle {
         implicitWidth: 100
         implicitHeight: 30
         radius:5
         color:  "transparent" 
         border.color:  "#f76206" 
         }
       
     }
     RoundButton {
            
             id:_btndelete
             text:"Delete"
             font.pixelSize :8
             anchors.left:_name.right
             anchors.leftMargin: 5
             anchors.verticalCenter: parent.verticalCenter
             hoverEnabled : true
            display:hovered ? AbstractButton.TextUnderIcon	: AbstractButton.IconOnly	
            icon.source: "./icon/delete.png"
            icon.width:hovered ? 16:24
            icon.height:hovered ? 16:24
            icon.color : "#5753c9"
             onClicked: {
                _interface.remove(_id)
             }

            background: Rectangle {
                 implicitWidth: 70
                 implicitHeight: 40
                 opacity: enabled ? 1 : 0.3
                 color: _btndelete.hovered ? "#17a81a" :"#f76206"
                 border.color: _btndelete.hovered? "#17a81a" : "#f76206"
                 border.width: 1
                 radius: 20
            }
        }
        RoundButton {
            
             id:_btndeleteall
             text: "Delete All"
             font.pixelSize:8
             anchors.left:_btndelete.right
             anchors.leftMargin: 5
             anchors.verticalCenter: parent.verticalCenter
            display:hovered ? AbstractButton.TextUnderIcon	: AbstractButton.IconOnly	
            hoverEnabled : true
            icon.source: "./icon/delete-all.png"
            icon.width:hovered ? 16:24
            icon.height:hovered ? 16:24
            icon.color : "#5753c9"
             onClicked: {
                _interface.removeAll()
             }

            background: Rectangle {
                 implicitWidth: 70
                 implicitHeight:  40
                 opacity: enabled ? 1 : 0.3
                 color: _btndeleteall.hovered ? "#17a81a" :"#f76206"
                 border.color: _btndeleteall.hovered? "#17a81a" : "#f76206"
                 border.width: 1
                 radius:  20
            }
        }
        
}
    