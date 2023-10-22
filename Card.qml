import QtQuick
import QtQuick.Layouts

Item {
	property alias backgroundColor: background.color

	Rectangle {
		id: background
		anchors.fill: parent
		color: "white"
		radius: 16
		antialiasing: true
		border.color: "#33808080"; border.width: 1
	}
}
