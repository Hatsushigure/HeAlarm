import QtQuick

Item {
	property string text
	property bool isActive: false
	property color activeColor: "lightblue"

	id: root
	implicitWidth: background.width; implicitHeight: background.height

	Rectangle {
		id: background
		width: 20; height: 20
		radius: 6
		border.color: "#33808080"; border.width: 1
		antialiasing: true
		color: isActive ? activeColor : "transparent"

		Text {anchors.centerIn: parent; text: root.text; font.pointSize: 8}
	}
}
