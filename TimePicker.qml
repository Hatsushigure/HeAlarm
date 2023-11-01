import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import "HeAlarmJs.js" as HeAlarmJs

Item {
	property alias hour: hourPicker.currentIndex
	property alias minute: minutePicker.currentIndex

	implicitHeight: 168; implicitWidth: layout.implicitWidth

	RowLayout {
		id: layout
		anchors.fill: parent
		spacing: 24

		Controls.Tumbler {
			id: hourPicker
			Layout.fillHeight: true
			Layout.alignment: Qt.AlignRight

			model: 24
			delegate: delegateComponent
		}

		Text {
			Layout.alignment: Qt.AlignCenter

			color: "gray"
			text: ":"
			font.family: "Microsoft YaHei UI Light"
			verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter
			font.pointSize: 48
		}

		Controls.Tumbler {
			id: minutePicker
			Layout.fillHeight: true
			Layout.alignment: Qt.AlignLeft

			model: 60
			delegate: delegateComponent
		}
	}

	Component {
		id: delegateComponent

		Text {
			text: HeAlarmJs.timeTxt(model.index)
			verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter
			font.pointSize: 24 - 6 * Math.sqrt(Math.abs(Controls.Tumbler.displacement))
			opacity: Math.abs(Controls.Tumbler.displacement) <= 0.5 ? 1 : 0.3
		}
	}
}

