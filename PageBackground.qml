import QtQuick 2.0
import QtQuick.Controls 2.5


Rectangle {
    width: 980
    height: 800
    clip: true
    color: "#2e2e37"
    anchors.fill: parent

    Rectangle {
        x: 386
        y: 647
        width: 843
        height: 438
        color: "#803e4252"
        radius: 304.5
        border.color: "#878fb8"
        border.width: 0
        rotation: 0

        Label {
            id: label
            x: 135
            y: 36
            width: 465
            height: 85
            color: "#dee5f7"
            text: stackView.currentItem.title
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 50
        }
    }

    Rectangle {
        id: rectangle
        x: -477
        y: -377
        width: 505
        height: 308
        color: "#3e4252"
        radius: 50
        border.width: 0
        scale: 2
        rotation: 45
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
