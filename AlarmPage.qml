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
			model: globalProp.alarmModel

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
				onIsActiveChanged: globalProp.alarmModel.setIsActive(index, isActive)
				Connections {
					target: globalProp.alarmModel
					function onDataChanged(topLeft, bottomRight) {
						if (index < topLeft.row || bottomRight.row < index)
							return
						isActive = globalProp.alarmModel.data(globalProp.alarmModel.index(index, 0), AlarmModel.IsActiveRole)
					}
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
					privateFunc.fillEditPage()
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
				onClicked: {
					globalProp.alarmModel.append(new Date().getHours(), new Date().getMinutes())
					lstView.currentIndex = lstView.count - 1
					editBtn.visible = true
					editBtn.clicked()
				}
			}
		}
	}

	Connections {
		target: editPage
		function onAccepted() {
			editPage.visible = false
			globalProp.alarmModel.setData(lstView.currentIndex, editPage.hour, editPage.minute, lstView.currentItem.isActive, editPage.activeDays, editPage.title)
		}
		function onDeleteRequested() {
			editPage.visible = false
			editBtn.visible = false
			globalProp.alarmModel.remove(lstView.currentIndex)
		}
	}

	HeAlarm {id: globalProp}

	QtObject {
		id: privateFunc
		function fillEditPage() {
			editPage.hour = lstView.currentItem.hour
			editPage.minute = lstView.currentItem.minute
			editPage.title = lstView.currentItem.title
			editPage.activeDays = lstView.currentItem.activeDays
			editPage.autoSetComboBox()
		}
	}
}
