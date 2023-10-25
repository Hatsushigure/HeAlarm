import QtQuick
import QtQuick.Layouts

Item {
	ColumnLayout {
		anchors.fill: parent

		Text {
			Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
			id: timeNum
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
			font.pointSize: 36
		}
	}

	Timer {
		interval: 500
		running: true
		repeat: true
		onTriggered: timeNum.text = Qt.formatTime(Date(), "HH:mm:ss")
	}
}
