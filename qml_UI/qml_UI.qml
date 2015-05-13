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
        anchors.verticalCenterOffset: -171
        anchors.horizontalCenterOffset: -296
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
