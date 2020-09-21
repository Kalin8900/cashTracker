import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: window
    visible: true
    width: 980
    height: 800
    title: qsTr("Cash Tracker")

    Drawer {
        id: drawer
        width: window.width * 0.33
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                width: parent.width
                height: home.height * 1.25

                Rectangle {
                    color: "#3e4252"
                    anchors.fill: parent

                    Label {
                        anchors.fill: parent
                        text: qsTr("Cash Tracker")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 20
                        font.bold: true
                    }
                }
            }

            ItemDelegate {
                id: home
                text: qsTr("Home")
                width: parent.width
                onClicked: {
                    if(stackView.currentItem.title === "Home") //BAD
                        drawer.close()
                    else {
                        if(stackView.depth > 1)
                            stackView.pop()

                        stackView.push("HomeForm.ui.qml")
                        drawer.close()
                    }
                }
            }

            ItemDelegate {
                text: qsTr("Income")
                width: parent.width
                onClicked: {
                    if(stackView.currentItem.title === "Income") //BAD
                        drawer.close()
                    else {
                        if(stackView.depth > 1)
                            stackView.pop()

                        stackView.push("Income.ui.qml")
                        drawer.close()
                    }
                }
            }

            ItemDelegate {
                text: qsTr("Outgoings")
                width: parent.width
                onClicked: {
                    if(stackView.currentItem.title === "Outgoings") //BAD
                        drawer.close()
                    else {
                        if(stackView.depth > 1)
                            stackView.pop()

                        stackView.push("Outgoings.ui.qml")
                        drawer.close()
                    }
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }

    ToolButton {
        id: toolButton
        x: 56
        y: 56
        width: 29
        height: 29
        text: "\u2630"
        scale: 4
        display: AbstractButton.TextBesideIcon
        font.pixelSize: Qt.application.font.pixelSize * 1.6
        onClicked: {
            drawer.open()
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
