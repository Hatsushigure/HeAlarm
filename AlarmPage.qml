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
			model: ListModel {
				ListElement {hour: 1; minute: 2; title: "111"; isActive: true; activeDays: HeAlarm.Monday}
				ListElement {hour: 3; minute: 4; title: "222"; isActive: false; activeDays: HeAlarm.Tuesday}
				ListElement {hour: 5; minute: 6; title: "333"; isActive: true; activeDays: HeAlarm.Wednesday}
				ListElement {hour: 7; minute: 8; title: "444"; isActive: false; activeDays: HeAlarm.Thursday}
				ListElement {hour: 9; minute: 10; title: "555"; isActive: true; activeDays: HeAlarm.Friday}
				ListElement {hour: 11; minute: 12; title: "666"; isActive: false; activeDays: HeAlarm.Saturday}
				ListElement {hour: 13; minute: 14; title: "777"; isActive: true; activeDays: HeAlarm.Sunday}
				ListElement {hour: 15; minute: 16; title: "888"; isActive: false; activeDays: HeAlarm.Weekday}
				ListElement {hour: 17; minute: 18; title: "999"; isActive: true; activeDays: HeAlarm.Weekend}
			}

			spacing: 16
			clip: true
			delegate: MouseArea {
				width: lstView.width; height: dl.height
				onClicked: editBtn.visible = false

				AlarmDelegate {
					id: dl
					anchors.centerIn: parent

					hour: model.hour
					minute: model.minute
					title: model.title
					isActive: model.isActive
					activeDays: model.activeDays
					onClicked: {
						lstView.currentIndex = model.index
						editBtn.visible = true
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
					editPage.hour = lstView.currentItem.children[0].hour
					editPage.minute = lstView.currentItem.children[0].minute
					editPage.title = lstView.currentItem.children[0].title
					editPage.activeDays = lstView.currentItem.children[0].activeDays
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
				onClicked: console.log("Add btn Clicked");
			}
		}
	}
}
