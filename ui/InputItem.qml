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
    Rectangle{
        height :120
        anchors.left: parent.left
        anchors.right:parent.right
        anchors.top:parent.top
        anchors.margins:5
        color:"#44252525"
        radius :5
        GridLayout{
            columns:2
            rows:2
            anchors.left: parent.left
            anchors.right:parent.right
            anchors.top:parent.top
            anchors.margins:5
            anchors.bottom:_btn.top

            TextField{
                id:_name
                Layout.row :0
                Layout.column:0
                placeholderText: qsTr("Enter FirstName")
                background: Rectangle {
                implicitWidth: 130
                implicitHeight: 30
                radius:5
                color: _name.enabled ? "transparent" : "#353637"
                border.color: _name.enabled ? "#f76206": "#21be2b" 
                }   
            }
            TextField{
                id:_family
                Layout.row :0
                Layout.column:1
                placeholderText: qsTr("Enter LastName")
                background: Rectangle {
                implicitWidth: 130
                implicitHeight: 30
                radius:5
                color: _family.enabled ? "transparent" : "#353637"
                border.color: _family.enabled ? "#f76206": "#21be2b" 
                }   
            }
            TextField{
                id:_phone
                Layout.row :1
                Layout.column:0
                placeholderText: qsTr("Enter NumebrPhone")
                background: Rectangle {
                implicitWidth: 130
                implicitHeight: 30
                radius:5
                color: _phone.enabled ? "transparent" : "#353637"
                border.color: _phone.enabled ? "#f76206": "#21be2b" 
                }   
            }
            TextField{
                id:_email
                Layout.row :1
                Layout.column:1
                placeholderText: qsTr("Enter Email")
                background: Rectangle {
                implicitWidth: 130
                implicitHeight: 30
                radius:5
                color: _email.enabled ? "transparent" : "#353637"
                border.color: _email.enabled ? "#f76206": "#21be2b" 
                }   
            }
        }
        RoundButton {
            
             id:_btn
             text: "\u2713" // Unicode Character 'CHECK MARK'
             anchors.bottom:parent.bottom
             anchors.bottomMargin: 5
             anchors.horizontalCenter : parent.horizontalCenter
             hoverEnabled : true
             onClicked: {
                
                 _interface.get_data(_name.text,_family.text,_phone.text,_email.text)
             }
            contentItem: Text {
                 text: _btn.text
                 font: _btn.font
                 opacity: enabled ? 1.0 : 0.3
                 color: "#ccc"
                 horizontalAlignment: Text.AlignHCenter
                 verticalAlignment: Text.AlignVCenter
                 elide: Text.ElideRight
            }

            background: Rectangle {
                 implicitWidth: _btn.down ? 40:32
                 implicitHeight: _btn.down ? 40:32
                 opacity: enabled ? 1 : 0.3
                 color: _btn.hovered ? "#17a81a" :"#f76206"
                 border.color: _btn.hovered? "#17a81a" : "#f76206"
                 border.width: 1
                 radius: _btn.down ? 20 : 16
            }
        }
    }    

}