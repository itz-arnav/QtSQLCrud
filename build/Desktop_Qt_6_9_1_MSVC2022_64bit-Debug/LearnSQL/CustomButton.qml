import QtQuick
import QtQuick.Controls.Basic

Button {
    id: control

    hoverEnabled: true

    contentItem: Label {
        text: control.text
        font {
            pointSize: 14
            weight: Font.DemiBold
        }

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        color: "#fafafa"
    }

    background: Rectangle {
        anchors.fill: parent
        radius: 8

        color: control.hovered ? Qt.darker("#25a244", 1.1) : "#25a244"
    }
}
