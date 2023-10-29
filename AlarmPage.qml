import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import HeAlarm

Item {
	required property AlarmEditPage editPage

	id: root
	implicitWidth: 500; implicitHeight: 700

	MouseArea {anchors.fill: parent; onClicked: editBtn.visible = false}

	GridLayout {
		anchors.fill: parent
		rows: 2; columns: 1

		ListView {
			Layout.fillWidth: true; Layout.fillHeight: true

			id: lstView
			model: AlarmModel {
				id: almModel
			}

			spacing: 16
			clip: true
			delegate: AlarmDelegate {
				required property int index
				required hour
				required minute
				required title
				required isActive
				required activeDays

				id: dl
				width: lstView.width
				onClicked: {
					lstView.currentIndex = index
					editBtn.visible = true
				}
			}
		}

		GridLayout {
			Layout.alignment: Qt.AlignCenter

			Controls.RoundButton {
				Layout.alignment: Qt.AlignCenter
				Controls.Material.background: "lightgreen"

				id: editBtn
				implicitWidth: 72; implicitHeight: 72
				visible: false
				contentItem: Image {
					source: "qrc:///res/Icons/Material/Rounded/Edit.png"
					mipmap: true
				}
				onClicked: {
					editPage.visible = true
					editPage.hour = lstView.currentItem.hour
					editPage.minute = lstView.currentItem.minute
					editPage.title = lstView.currentItem.title
					editPage.activeDays = lstView.currentItem.activeDays
					editPage.autoSetComboBox()
				}
			}


			Controls.RoundButton {
				Layout.alignment: Qt.AlignCenter
				Controls.Material.background: "lightgreen"

				implicitWidth: 72; implicitHeight: 72
				contentItem: Image {
					source: "qrc:///res/Icons/Material/Rounded/Plus.png"
					mipmap: true
				}
				onClicked: almModel.append(1, 2, false, HeAlarm.All, "Test Test Test")
			}
		}
	}

	Connections {
		target: editPage
		function onAccepted() {
			editPage.visible = false
			almModel.setData(lstView.currentIndex, editPage.hour, editPage.minute, true, editPage.activeDays, editPage.title)
		}
	}
}
