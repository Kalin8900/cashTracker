import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 980
    height: 800

    title: qsTr("Home")

    PageBackground {
        Label {
            text: qsTr("You are on the home page.")
            anchors.centerIn: parent
        }
    }

}
