import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 980
    height: 800

    title: qsTr("Home")

    PageBackground {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        Label {
            width: 350
            height: 50
            text: qsTr("Aktualny Balans:")
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: -136
            anchors.horizontalCenterOffset: 1
            anchors.centerIn: parent
        }

        Label {
            id: balanceValueText
            x: -3
            y: 4
            width: 350
            height: 50
            property string bal: Math.round((balance.balance) * 100) / 100
            text: bal + qsTr(" zł")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 1
            font.pointSize: 20
            anchors.verticalCenterOffset: -80
            anchors.centerIn: parent
        }

        Label {
            x: 1
            y: 2
            width: 227
            height: 50
            text: qsTr("Ostatnia operacja:")
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: -214
            font.pointSize: 12
            anchors.verticalCenterOffset: 0
            anchors.centerIn: parent
        }

        Label {
            x: 7
            y: 0
            width: 89
            height: 50
            property string value: Math.round(balance.getValueFromOperation(
                                       balance.getLastOperationIdx(),
                                       balance.getLastOperationPlace()) * 100) / 100;
            text: qsTr(value + " zł")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenterOffset: -50
            font.pointSize: 12
            anchors.verticalCenterOffset: 0
            anchors.centerIn: parent
        }



        Label {
            x: 3
            y: 2
            width: 89
            height: 50
            property string cat: balance.getCategoryFromOperation(
                                     balance.getLastOperationIdx(),
                                     balance.getLastOperationPlace())
            text: cat
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 52
            font.pointSize: 12
            anchors.verticalCenterOffset: 0
            anchors.centerIn: parent
        }

        Rectangle {
            id: rectangle
            x: 490
            y: 380
            width: 1
            height: 40
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle1
            x: 592
            y: 380
            width: 1
            height: 40
            color: "#ffffff"
        }

        Label {
            x: -1
            y: 1
            width: 135
            height: 50
            property string date: balance.getDateFromOperation(
                                      balance.getLastOperationIdx(),
                                      balance.getLastOperationPlace())
            text: date
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenterOffset: 177
            font.pointSize: 12
            anchors.verticalCenterOffset: 0
            anchors.centerIn: parent
        }
    }
}
