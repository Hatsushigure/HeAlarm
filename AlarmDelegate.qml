import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls

Item {
	property string timeString: "10:10:00"
	property bool enabled: true
	property string title: "闹铃"

	implicitWidth: card.implicitWidth; implicitHeight: card.implicitHeight

	Rectangle { color: "#f2f2f2";anchors.fill: parent;}

	Card {
		id: card
		implicitWidth: layout.implicitWidth; implicitHeight: layout.implicitHeight

		GridLayout {
			id: layout
			anchors.fill: parent

			GridLayout {
				Layout.margins: 16

				rows: 2; columns: 3
				columnSpacing: 16
				Text {Layout.rowSpan: 2; text: timeString; font.bold: true; font.pointSize: 18}
				Text {Layout.row: 0; Layout.column: 1; Layout.alignment: Qt.AlignCenter; text: title}
				RowLayout {
					Layout.row: 1; Layout.column: 1
					Layout.alignment: Qt.AlignCenter

					WeekIndicator {text: "一"; litColor: "lightgreen"; lit: true}
					WeekIndicator {text: "二"; litColor: "lightgreen"; lit: true}
					WeekIndicator {text: "三"; litColor: "lightgreen"; lit: true}
					WeekIndicator {text: "四"; litColor: "lightgreen"; lit: true}
					WeekIndicator {text: "五"; litColor: "lightgreen"; lit: true}
					WeekIndicator {text: "六"; litColor: "lightgreen"; lit: true}
					WeekIndicator {text: "日"; litColor: "lightgreen"; lit: true}
				}
				Controls.Switch {Layout.row: 0; Layout.column: 2; Layout.rowSpan: 2; checked: enabled}
			}
		}
	}
}
