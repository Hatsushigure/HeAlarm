import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls

Item {
	signal cancled()
	signal accepted()

	id: root

	Rectangle {
		anchors.fill: parent
		color: "#661a1a1a"

		MouseArea {anchors.fill: parent; onClicked: root.cancled(); onWheel: {}}

		Card {
			anchors.centerIn: parent
			width: 400; height: 500

			MouseArea {anchors.fill: parent; onWheel: {}}

			ColumnLayout {
				anchors.fill: parent

				ColumnLayout {
					Layout.margins: 12

					RowLayout {
						Layout.fillWidth: true

						spacing: 12

						Item {Layout.fillWidth: true}

						Image {
							Layout.preferredHeight: 32; Layout.preferredWidth: 32

							source: "qrc:/res/Icons/Material/Rounded/X.png"

							MouseArea {anchors.fill: parent; onClicked: root.cancled()}
						}

						Image {
							Layout.preferredHeight: 32; Layout.preferredWidth: 32

							source: "qrc:/res/Icons/Material/Rounded/Tick.png"

							MouseArea {anchors.fill: parent; onClicked: root.accepted()}
						}
					}

					Controls.Tumbler {
						model: 24
						delegate: Text {
							text: model.index + 1
						}
					}

					Item {Layout.fillHeight: true}
				}
			}
		}
	}
}
