import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 980
    height: 800
    visible: true

    title: qsTr("Income")

    PageBackground {
        visible: true
        Label {
            text: qsTr("You are on Page 1.")
            anchors.centerIn: parent
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

