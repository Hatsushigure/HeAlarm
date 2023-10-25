import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import QtQuick.Effects
import HeAlarm

Item {
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
				ListElement {timeString: "11:45"; title: ""; isActive: true; activeDays: HeAlarm.Monday}
				ListElement {timeString: "11:45"; title: ""; isActive: false; activeDays: HeAlarm.Tuesday}
				ListElement {timeString: "11:45"; title: ""; isActive: true; activeDays: HeAlarm.Wednesday}
				ListElement {timeString: "11:45"; title: ""; isActive: false; activeDays: HeAlarm.Thursday}
				ListElement {timeString: "11:45"; title: ""; isActive: true; activeDays: HeAlarm.Friday}
				ListElement {timeString: "11:45"; title: ""; isActive: false; activeDays: HeAlarm.Saturday}
				ListElement {timeString: "11:45"; title: ""; isActive: true; activeDays: HeAlarm.Sunday}
				ListElement {timeString: "11:45"; title: ""; isActive: false; activeDays: HeAlarm.Weekday}
				ListElement {timeString: "11:45"; title: ""; isActive: true; activeDays: HeAlarm.Weekend}
			}

			spacing: 16
			clip: true
			delegate: MouseArea {
				width: lstView.width; height: dl.height
				onClicked: editBtn.visible = false

				AlarmDelegate {
					id: dl
					anchors.centerIn: parent

					timeString: model.timeString
					title: model.title + model.index
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

				id: editBtn
				implicitWidth: 72; implicitHeight: 72
				visible: false
				contentItem: Image {
					source: "qrc:///res/Icons/Material/Rounded/Edit.png"
					mipmap: true
				}
				background: Rectangle {
					color: "lightgreen"
					radius: width / 2
					border.color: "#33808080"
				}
				onClicked: console.log(lstView.currentIndex);
			}


			Controls.RoundButton {
				Layout.alignment: Qt.AlignCenter

				implicitWidth: 72; implicitHeight: 72
				contentItem: Image {
					source: "qrc:///res/Icons/Material/Rounded/Plus.png"
					mipmap: true
				}
				background: Rectangle {
					color: "lightgreen"
					radius: width / 2
					border.color: "#33808080"
				}
				onClicked: console.log("Add btn Clicked");
			}
		}
	}
}
