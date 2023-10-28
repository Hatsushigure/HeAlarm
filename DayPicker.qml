import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import "HeAlarmJs.js" as HeAlarmJs
import HeAlarm

Item {
	readonly property var dayNameLst: ["一", "二", "三", "四", "五", "六", "日"]
	property int activeDays: 0
	property int initialState: 0

	implicitWidth: dayPickers.implicitWidth; implicitHeight: layout.implicitHeight

	GridLayout {
		id: layout
		anchors.fill: parent
		rows: 2; columns: 2
		columnSpacing: 12

		Text {
			text: "重复"
			font.bold: true
			verticalAlignment: Text.AlignVCenter
			font.pointSize: 16
		}

		Controls.ComboBox {
			id: repeatComboBox
			Layout.fillWidth: true
			model: ["仅一次", "每天", "工作日", "周末", "自定义"]
			onCurrentIndexChanged: {
				switch (currentIndex) {
				case 0:
					activeDays = 0;
					break;
				case 1:
					//					activeDays = 0x7F;
					activeDays = HeAlarm.All;
					break;
				case 2:
					//					activeDays = 0x1F;
					activeDays = HeAlarm.Weekday;
					break;
				case 3:
					//					activeDays = 0x60;
					activeDays = HeAlarm.Weekend;
					break;
				default:
					break;
				}
			}
		}

		GridLayout {
			Layout.alignment: Qt.AlignHCenter
			Layout.columnSpan: 2

			id: dayPickers
			visible: repeatComboBox.currentIndex === 4
			rows: 2; columns: 5
			rowSpacing: 12; columnSpacing: 12

			Repeater {
				model: 7
				delegate: RoundToggleButton {
					width: 50
					toggled: HeAlarmJs.getBit(activeDays, model.index)
					onClicked: {
						activeDays = HeAlarmJs.setBit(activeDays, model.index, toggled ? 1 : 0)
						toggled = Qt.binding(function() {return HeAlarmJs.getBit(activeDays, model.index)})
					}

					Text {
						anchors.centerIn: parent
						text: dayNameLst[model.index]
						font.pointSize: 14
					}
				}
			}
		}
	}

	function autoSetComboBox() {
		switch (activeDays) {
		case 0:
			repeatComboBox.currentIndex = 0;
			break;
		case HeAlarm.All:
			repeatComboBox.currentIndex = 1;
			break;
		case HeAlarm.Weekday:
			repeatComboBox.currentIndex = 2;
			break;
		case HeAlarm.Weekend:
			repeatComboBox.currentIndex = 3;
			break;
		default:
			repeatComboBox.currentIndex = 4;
			break;
		}
	}
}
