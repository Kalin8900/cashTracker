import QtQuick 2.0
import QtQuick.Controls 2.5


Rectangle {
    width: 980
    height: 800
    clip: true
    color: "#22203c"
    anchors.fill: parent

    Rectangle {
        x: 386
        y: 647
        width: 843
        height: 438
        color: "#3a3b48"
        radius: 304.5
        border.width: 0


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
        color: "#3a3b48"
        radius: 50
        border.width: 0
        scale: 2
        rotation: 45
    }

    Label {
        x: 7
        y: 6
        width: 89
        height: 50
        text: qsTr("18:46")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: -235
        font.pointSize: 12
        anchors.verticalCenterOffset: 342
        anchors.centerIn: parent
    }

    Rectangle {
        id: rectangle2
        x: 203
        y: 722
        width: 1
        height: 40
        color: "#ffffff"
    }

    Label {
        x: 3
        y: 5
        width: 135
        height: 50
        text: qsTr("15-10-2020")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenterOffset: -360
        font.pointSize: 12
        anchors.verticalCenterOffset: 342
        anchors.centerIn: parent
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
