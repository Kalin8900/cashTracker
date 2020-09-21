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
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    if(stackView.currentItem.title === "test") //BAD
                        drawer.close()
                    else {
                        if(stackView.depth > 1)
                            stackView.pop()

                        stackView.push("Page1Form.ui.qml")
                        drawer.close()
                    }
                }
            }

            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    if(stackView.currentItem.title === "test2") //BAD
                        drawer.close()
                    else {
                        if(stackView.depth > 1)
                            stackView.pop()

                        stackView.push("Page2Form.ui.qml")
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
