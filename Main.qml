import QtQuick

Window {
	width: 640; height: 480
	visible: true
	title: qsTr("HeAlarm 0.1.0")

	ClockPage {
		anchors.fill: parent
	}
}
