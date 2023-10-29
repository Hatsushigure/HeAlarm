import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import HeAlarm
import "HeAlarmJs.js" as HeAlarmJs

Item {
	property int hour: 10
	property int minute: 10
	property bool isActive: activeSwitch.checked
	property string title: "闹铃"
	property int activeDays: HeAlarm.All
	signal clicked()
	signal cancled()

	id: root
	implicitWidth: card.implicitWidth; implicitHeight: card.implicitHeight

	MouseArea {
		anchors.fill: parent
		onClicked: root.cancled
		Card {
			id: card
			implicitWidth: layout.implicitWidth; implicitHeight: layout.implicitHeight
			anchors.centerIn: parent

			MouseArea {
				anchors.fill: parent
				onClicked: root.clicked()
			}

			GridLayout {
				id: layout
				anchors.fill: parent

				GridLayout {
					Layout.margins: 12

					rows: 2; columns: 3
					columnSpacing: 16
					Text {Layout.rowSpan: 2; text: HeAlarmJs.timeTxt(hour) + ":" + HeAlarmJs.timeTxt(minute); font.bold: true; font.pointSize: 18}
					Text {Layout.row: 0; Layout.column: 1; Layout.alignment: Qt.AlignCenter; text: title}
					RowLayout {
						Layout.row: 1; Layout.column: 1
						Layout.alignment: Qt.AlignCenter

						WeekIndicator {text: "一"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Monday}
						WeekIndicator {text: "二"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Tuesday}
						WeekIndicator {text: "三"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Wednesday}
						WeekIndicator {text: "四"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Thursday}
						WeekIndicator {text: "五"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Friday}
						WeekIndicator {text: "六"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Saturday}
						WeekIndicator {text: "日"; activeColor: "lightgreen"; isActive: activeDays & HeAlarm.Sunday}
					}
					Controls.Switch {
						Layout.row: 0; Layout.column: 2
						Layout.rowSpan: 2
						Controls.Material.accent: "lightgreen"

						id: activeSwitch
						onCheckedChanged: root.isActive = checked
					}
				}
			}
		}
	}
}
