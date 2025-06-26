
import QtQuick
import QtQuick.Controls.Basic 
import QtQuick.Layouts 
Rectangle{
   //anchors.fill : parent
   color:"#44252525"
   radius :5
   Image{
    id:_img
    source : "./icon/search-property.png"
    width:32
    height: 32
    anchors.left:parent.left
    anchors.verticalCenter: parent.verticalCenter
   }
   TextField{
         id:_search
         anchors.verticalCenter: parent.verticalCenter
         anchors.left:_img.right
         anchors.leftMargin:5
         placeholderText: qsTr("Search name")
         
         background: Rectangle {
         implicitWidth: 250
         implicitHeight: 30
         radius:5
         color: _search.enabled ? "transparent" : "#353637"
         border.color: _search.enabled ? "#f76206": "#21be2b" 
         }
         onAccepted:{
            _interface.search(text)
         }   
         onTextChanged: {
                if (!text || text.trim() === "") {
                    _interface.clearSearch()
                }     
            }
     }
        
}
    