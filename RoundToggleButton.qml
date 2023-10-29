import QtQuick

Item {
	signal clicked()
	property bool toggled: false

	id: root
	onWidthChanged: height = width
	onHeightChanged: width = height

	MouseArea {
		id: msArea
		anchors.fill: parent
		hoverEnabled: true
		onEntered: hoverIndicator.visible = true
		onExited: hoverIndicator.visible = false
		onClicked: {
			toggled ^= 1
			root.clicked()
		}
	}

	Rectangle {
		id: background
		antialiasing: true
		border.color: "#33808080"
		anchors.fill: parent
		radius: width / 2
		color: toggled ? "lightgreen" : "transparent"
	}

	Rectangle {
		id: hoverIndicator
		anchors.fill: parent
		radius: width / 2
		color: "#33808080"
		visible: false
	}
}
