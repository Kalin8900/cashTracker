import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.11

Page {
    width: 980
    height: 800
    visible: true
    id: root
    title: qsTr("Income")

    PageBackground {
        visible: true
        id: page
        anchors.fill: parent
        Label {
            text: qsTr("Here you can see your income")
            font.pointSize: 20
            anchors.verticalCenterOffset: -308
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
        }

        RowLayout {
            y: 158
            width: listView.width
            height: 30
            anchors.horizontalCenterOffset: 11
            spacing: 0
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                text: qsTr("Cost")
                Layout.minimumHeight: 30
                Layout.minimumWidth: listView.width / 3
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 13
                Rectangle {
                    color: "#56567f"
                    width: parent.width
                    height: parent.height
                    z: -1
                }

                Rectangle {
                    x: -93
                    y: 8
                    width: parent.width
                    height: parent.height
                    color: "#2e2e37"
                    rotation: 125
                    z: -1
                }
            }

            Label {
                text: qsTr("Date")
                Layout.minimumHeight: 30
                Layout.minimumWidth: listView.width / 3
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 13
                Rectangle {
                    color: "#56567f"
                    width: parent.width
                    height: parent.height
                    z: -1
                }
            }
            Label {
                text: qsTr("Category")
                font.pointSize: 13
                Layout.minimumHeight: 30
                Layout.minimumWidth: listView.width / 3
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                Rectangle {
                    color: "#56567f"
                    width: parent.width
                    height: parent.height
                    z: -1
                }

                Rectangle {
                    x: 97
                    y: 10
                    width: parent.width
                    height: parent.height
                    color: "#2e2e37"
                    rotation: 45
                    z: -1
                }
            }
        }

        Frame {
            x: 248
            y: 194
            width: 506
            height: 393
            id: frame

            ListView {
                id: listView
                clip: true
                anchors.fill: parent

                model: ListModel {
                    id: model

                    ListElement {
                        cost: 200
                        date: "22-09-2020"
                        category: "RTV"
                    }
                    ListElement {
                        cost: 150
                        date: "21-09-2020"
                        category: "Gym"
                    }
                }

                delegate: RowLayout {
                    width: listView.width
                    height: 30
                    enabled: true

                    Label {
                        text: model.cost
                        horizontalAlignment: Text.AlignHCenter
                        Layout.minimumHeight: 30
                        Layout.minimumWidth: listView.width / 3
                    }

                    Label {
                        text: model.date
                        horizontalAlignment: Text.AlignHCenter
                        Layout.minimumHeight: 30
                        Layout.minimumWidth: listView.width / 3
                    }

                    Label {
                        text: model.category
                        horizontalAlignment: Text.AlignHCenter
                        Layout.minimumHeight: 30
                        Layout.minimumWidth: listView.width / 3
                    }
                }
            }
        }

        RowLayout {
            y: 621
            width: listView.width / 3
            height: 30
            TextEdit {
                id: incomeCost
                text: qsTr("Cost")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "#56567f"
                    z: -1
                }
                Layout.minimumWidth: listView.width / 4
                Layout.minimumHeight: 30
                font.pointSize: 13
            }

            TextEdit {
                id: incomeDate
                text: qsTr("Date")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "#56567f"
                    z: -1
                }
                Layout.minimumWidth: listView.width / 4
                Layout.minimumHeight: 30
                font.pointSize: 13
            }

            TextEdit {
                id: incomeCategory
                text: qsTr("Category")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "#56567f"
                    z: -1
                }
                Layout.minimumWidth: listView.width / 4
                Layout.minimumHeight: 30
                font.pointSize: 13
            }
            anchors.horizontalCenterOffset: -353
            spacing: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: addBtn
            x: 147
            y: 676
            width: 177
            height: 32
            text: qsTr("Add Item")

            onClicked: {
            }
        }

        Button {
            id: rmBtn
            x: 147
            y: 676 + rmBtn.height + 5
            width: 177
            height: 32
            text: qsTr("Remove last Item")

            onClicked: model.remove(model.count - 1)
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.6600000262260437}
}
##^##*/

