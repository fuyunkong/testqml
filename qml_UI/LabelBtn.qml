import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

Rectangle {
    id:labelbtn
    property string picSrc: ""
    property string text:""

    width:50
    height:50
    Image
    {
        id: image
        source:labelbtn.picSrc
    }
    Text
    {
        id: label
        color: "#000000"
        font.pointSize: 9
        font.family: "微软雅黑"
        anchors.horizontalCenter: image.horizontalCenter
        anchors.top: image.bottom
        anchors.topMargin: 3
        text:labelbtn.text
    }
}
