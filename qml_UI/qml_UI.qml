import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

ApplicationWindow {
    title: qsTr("UI编辑器")
    width: 800
    height: 480

    menuBar: MenuBar {
        Menu {
            title: qsTr("文件")
            MenuItem {
                text: qsTr("打开")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("退出")
                onTriggered: Qt.quit();
            }
        }
    }

    Button {
        text: qsTr("按钮")
        anchors.verticalCenterOffset: -161
        anchors.horizontalCenterOffset: -309
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onClicked: {
            rectangle1.x += 10
            rectangle1.y += 2
        }




    }



    Rectangle{
        id: rectangle1
           x:61
           y:162
           width: 80
           height: 25
           color: "#aea76d"
           Image{
               x: 0
               y: 0
               width: 80
               height: 25
               anchors.verticalCenterOffset: 0
               anchors.horizontalCenterOffset: 0
               clip: false
               anchors.horizontalCenter: parent.horizontalCenter
               anchors.verticalCenter: parent.verticalCenter
               scale: 1
               transformOrigin: Item.Center
               fillMode: Image.Stretch

           }

           Text {
                     id: btn_show
                     anchors.centerIn: parent
                     text: "重置总数"
                     MouseArea{
                         anchors.fill: parent
                         onClicked: {
                             console.log("click");
                             txt_reset.text = "点击事件"
                             txt_reset.color = "#aea76d"

                             rectangle1.x = 100
                             rectangle1.y = 100
                         }
                     }
                 }

       }

    Text {
           id: txt_reset
           x: 255
           y: 82
           text: "重置总数"
           verticalAlignment: Text.AlignVCenter
           horizontalAlignment: Text.AlignHCenter
           width: 80
           height: 25
           color: "#12ff12"
           MouseArea {
               anchors.fill: parent
               onClicked: {
                   if (parent.color == "#12ff12") {
                   parent.color = "#aea76d";
                   } else {
                       parent.color = "#12ff12";
                   }
               }
           }

    }

    Rectangle {
        id: rectangle2
        x: 436
        y: 180
        width: 200
        height: 200
        color: "#ffffff"
        MouseArea {
            anchors.fill: parent
            onPressed: parent.color = "green"
            onReleased: parent.color = "black"
        }
    }

    Rectangle {
        id: rectangle3
        x: 113
        y: 250
        width: 80
        height: 40
        color: "#12ff12"
        MouseArea {
            anchors.fill: parent
            // See Qt::MouseButtons for a list of available buttons
            acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: {
                if (mouse.button == Qt.RightButton)
                  parent.color = 'blue';
                else
                  parent.color = 'red';
                }
                drag.target: parent
                drag.axis: "XAxis"
                drag.minimumX: 0
                drag.maximumX: opacitytest.width-parent.width

                drag.minimumY: 0
                drag.maximumY: opacitytest.height-parent.height
        }


    }

    Rectangle {
        id: rectangle4
        x: 514
        y: 67
        width: 80
        height: 40
        color: "#ffffff"
        MouseArea {
                   anchors.fill: parent
                   drag.target: parent; drag.axis: Drag.XAxis; drag.minimumX: 1; drag.maximumX: 78
                   onClicked: toggle()
                   onReleased: releaseSwitch()
               }
    }
    Content1{
          scale:0.8

          anchors.fill: parent

    }


}
