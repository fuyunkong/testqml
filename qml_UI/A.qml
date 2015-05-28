import QtQuick 2.0

Rectangle{
    id:_a
    width:100
    height:100
    color:"red"
    function showB(){
     var component = Qt.createComponent("B.qml");
     var subView = component.createObject(_a,{"_text":"I am B!"});
    }
     MouseArea{
      anchors.fill:parent
      onClicked:{
       showB();
     }
     }
}
