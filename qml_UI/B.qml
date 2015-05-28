import QtQuick 2.0

Rectangle{
    id:_b
    width:100
    height:100
    color:"blue"
    property alias _text:_bText.text
     Text{
     id:_bText
     }
     MouseArea{
         anchors.fill:parent
          onClicked:{
          _b.destroy();
         }
     }
}
