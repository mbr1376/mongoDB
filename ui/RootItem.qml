import QtQuick 
import QtQuick.Controls 
import QtQuick.Layouts 

Item {
    anchors.fill:parent
    //width: 640
    //height: 480
    ListModel{
        id:listmodel
        ListElement{
            firstName:"mohamd"
            lastName:"roodsarabi"
            phone:"09398831591"
            email:"mbr@gmail.com"

        }
    }

    Rectangle {
        id: backgrand

        color: "#ffffff"
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#000000"
            }

            GradientStop {
                position: 0.48
                color: "#5753c9"
            }

            GradientStop {
                position: 1
                color: "#6e7ff3"
            }
            orientation: Gradient.Vertical
        }
        InputItem{

        }
        
        ListItem{
            width: parent.width/2 -5
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.rightMargin: 5
            _listmodel:listmodel
            anchors.topMargin: 5
        }
        

    }


}
