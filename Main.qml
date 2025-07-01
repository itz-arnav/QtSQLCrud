import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import LearnSQL

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Sql Example")
    color: "#333"

    function updateItemList() {
        const receivedData = BackendHelper.fetchItemsFromDatabase()
        itemDBModel.clear()
        for(let i = 0; i < receivedData.length; i++) {
            itemDBModel.append(receivedData[i])
        }
    }

    RowLayout {
        anchors {
            fill: parent
            margins: 50
        }

        spacing: 30

        Rectangle {
            id: leftLayout
            Layout.preferredWidth: parent.width/2 - 15
            Layout.fillHeight: true

            color: "transparent"
            radius: 8
            border {
                width: 2
                color: "#4ad66d"
            }

            ColumnLayout {
                anchors {
                    fill: parent
                    margins: 25
                    topMargin: 50
                }

                spacing: 20

                CustomTextField {
                    id: idInputTextField

                    placeholderText: qsTr("Please enter ID")

                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                }

                CustomTextField {
                    id: nameInputTextField

                    placeholderText: qsTr("Please enter Name")
                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                }

                CustomTextField {
                    id: ageInputTextField

                    placeholderText: qsTr("Please enter Age")
                    Layout.fillWidth: true
                    Layout.preferredHeight: 40
                }

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 40

                    CustomButton {
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 120

                        text: qsTr("Save Item")

                        onClicked: {
                            const id = idInputTextField.text
                            const name = nameInputTextField.text
                            const age = ageInputTextField.text

                            if(id === "" || age === "" || name === "") {
                                return
                            }

                            BackendHelper.saveItemToDatabase(id, name, age)
                            updateItemList()
                        }
                    }

                    CustomButton {
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 120

                        text: qsTr("Update Item")

                        onClicked: {
                            const id = idInputTextField.text
                            const name = nameInputTextField.text
                            const age = ageInputTextField.text

                            if(id === "" || age === "" || name === "") {
                                return
                            }

                            BackendHelper.updateItemInDatabase(id, name, age)
                            updateItemList()
                        }
                    }
                }

                CustomButton {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150

                    text: qsTr("Delete All Items")

                    onClicked: {
                        BackendHelper.deleteItemInDatabase()
                        updateItemList()
                    }
                }

                Item {
                    Layout.fillHeight: true
                }
            }
        }

        Rectangle {
            id: rightLayout

            Layout.preferredWidth: parent.width/2 - 15
            Layout.fillHeight: true

            color: "transparent"
            radius: 8
            border {
                width: 2
                color: "#4ad66d"
            }

            ColumnLayout {
                anchors {
                    fill: parent
                    margins: 25
                    topMargin: 50
                }

                spacing: 20

                CustomButton {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150

                    text: qsTr("Fetch All Items")

                    onClicked: {
                        updateItemList()
                    }
                }

                ListModel {
                    id: itemDBModel
                }

                ListView {
                    id: itemListView

                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    spacing: 10
                    clip: true
                    boundsBehavior: Flickable.StopAtBounds

                    model: itemDBModel
                    delegate: itemListDelegate

                    Component.onCompleted: {
                        updateItemList()
                    }
                }

                Component {
                    id: itemListDelegate
                    Rectangle {

                        required property int index
                        required property int _id
                        required property string name
                        required property int age

                        width: itemListView.width
                        height: 40

                        color: "#b3e9c7"
                        opacity: 0.6

                        radius: 8

                        border {
                            width: 1
                            color: "#25a244"
                        }

                        RowLayout {
                            anchors {
                                fill: parent
                                leftMargin: 10
                                rightMargin: 10
                            }

                            spacing: 0

                            Text {
                                Layout.preferredWidth: parent.width / 4
                                text: _id
                                color: "#fafafa"
                                font.pointSize: 14
                            }

                            Text {
                                Layout.preferredWidth: parent.width / 4
                                text: name
                                color: "#fafafa"
                                font.pointSize: 14
                            }

                            Text {
                                Layout.preferredWidth: parent.width / 4

                                text: age
                                color: "#fafafa"
                                font.pointSize: 14
                            }

                            Button {
                                Layout.fillWidth: true
                                text: "DEL"
                                onClicked: {
                                    BackendHelper.deleteItemInDatabase(_id)
                                    updateItemList()
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
