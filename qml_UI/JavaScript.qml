import QtQuick 2.0

Item {
    width: 500
    height: 500

    Rectangle {
        id: rect
        width: 100
        color: "red"
    }

    Component.onCompleted: {
        rect.height = Qt.binding(function() { return this.width * 2 })
        console.log("rect.height = " + rect.height) // prints 200, not 1000
    }
}
