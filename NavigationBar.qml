import QtQuick
import QtQuick.Layouts

Item {
	property int currentIndex: 0

	id: root
	implicitWidth: layout.implicitWidth; implicitHeight: layout.implicitHeight

	RowLayout {
		id: layout
		anchors.fill: parent
		spacing: 24

		Item {Layout.fillWidth: true}

		Repeater {
			id: rpt
			model: ListModel {
				ListElement {source: "qrc:///res/Icons/Material/Rounded/Clock.png"}
				ListElement {source: "qrc:///res/Icons/Material/Rounded/Alarm.png"}
			}

			delegate: Rectangle {
				readonly property bool isCurrent: root.currentIndex === model.index ? true : false

				Layout.alignment: Qt.AlignCenter

				id: clk
				width: 96; height: 54
				radius: height / 2
				color: isCurrent ? "lightgreen" : "transparent"

				MouseArea {anchors.fill: parent; onClicked: root.currentIndex = model.index}

				Image {
					anchors.centerIn: parent
					height: parent.height - 8; width: height
					source: model.source
				}
			}
		}

		Item {Layout.fillWidth: true}
	}
}
