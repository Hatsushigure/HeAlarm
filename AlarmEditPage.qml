import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material as Controls
import HeAlarm

Item {
	signal cancled()
	signal accepted()
	property alias hour: timePicker.hour
	property alias minute: timePicker.minute
	property alias title: titleBox.text
	property alias activeDays: dayPicker.activeDays

	id: root

	Rectangle {
		anchors.fill: parent
		color: "#661a1a1a"

		MouseArea {anchors.fill: parent; onClicked: root.cancled(); onWheel: {}}

		Card {
			anchors.centerIn: parent
			width: 400; height: 540

			MouseArea {anchors.fill: parent; onWheel: {}}

			ColumnLayout {
				anchors.fill: parent

				ColumnLayout {
					Layout.margins: 12
					Layout.fillWidth: true; Layout.fillHeight: true

					spacing: 12

					RowLayout {
						Layout.fillWidth: true

						spacing: 12

						//BorderIndicator {}
						Item {Layout.fillWidth: true}

						Image {
							Layout.preferredHeight: 32; Layout.preferredWidth: 32

							source: "qrc:/res/Icons/Material/Rounded/X.png"

							MouseArea {anchors.fill: parent; onClicked: root.cancled()}
							//BorderIndicator {}
						}

						Image {
							Layout.preferredHeight: 32; Layout.preferredWidth: 32

							source: "qrc:/res/Icons/Material/Rounded/Tick.png"

							MouseArea {anchors.fill: parent; onClicked: root.accepted()}
							//BorderIndicator {}
						}
					}

					ColumnLayout {
						Layout.alignment: Qt.AlignHCenter

						spacing: 12

						TimePicker { id: timePicker; Layout.alignment: Qt.AlignHCenter}

						DayPicker {
							Layout.leftMargin: 12; Layout.rightMargin: 12
							Layout.fillWidth: true

							id: dayPicker
						}

						RowLayout {
							Layout.leftMargin: 12; Layout.rightMargin: 12

							spacing: 12

							Text {
								text: "备注"
								font.bold: true
								verticalAlignment: Text.AlignVCenter
								font.pointSize: 16
								//BorderIndicator {}
							}

							Controls.TextField {
								id: titleBox
								Layout.fillWidth: true
							}
						}
						//BorderIndicator {}
					}

					Item {Layout.fillHeight: true}
					//BorderIndicator {}
				}
			}
			//BorderIndicator {}
		}
	}

	function autoSetComboBox() {dayPicker.autoSetComboBox()}
}
