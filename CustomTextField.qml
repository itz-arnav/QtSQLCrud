import QtQuick
import QtQuick.Controls.Basic

TextField {
    id: control

    placeholderTextColor: "#555"
    color: "#000"

    font.pointSize: 14

    background: Rectangle {
        anchors.fill: parent
        color: "#f0fff1"
        radius: 8

        border {
            width: 1
            color: "#b3e9c7"
        }
    }
}
