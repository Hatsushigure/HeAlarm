import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import HeAlarm
import "HeAlarmJs.js" as HeAlarmJs

Item {
	property int hour: 10
	property int minute: 10
	property bool isActive: true
	property string title: "闹铃"
	property int activeDays: HeAlarm.All
	signal clicked()
	signal cancled()

	id: root
	implicitWidth: card.implicitWidth; implicitHeight: card.implicitHeight
	onIsActiveChanged: activeSwitch.checked = isActive

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

						Repeater {
							model: 7
							delegate: WeekIndicator {
								text: HeAlarmJs.dayNames[model.index]
								activeColor: "lightgreen"
								isActive: activeDays & HeAlarmJs.setBit(0, model.index, 1)
							}
						}
					}
					Controls.Switch {
						Layout.row: 0; Layout.column: 2
						Layout.rowSpan: 2
						Controls.Material.accent: "lightgreen"

						id: activeSwitch
						checked: isActive
						onCheckedChanged: root.isActive = checked
					}
				}
			}
		}
	}
}
