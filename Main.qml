import QtQuick

Window {
	width: 640; height: 480
	visible: true
	title: qsTr("HeAlarm 0.1.0")

	Card {
		anchors.fill: parent
		Text {text: "卡片内容"; font.pointSize: 12; anchors.centerIn: parent}
	}
}
