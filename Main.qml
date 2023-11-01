import QtQuick
import QtQuick.Layouts
import Qt.labs.platform as Platform
import QtQuick.Controls.Material as Controls

Window {
	width: 640; height: 724
	visible: true
	title: qsTr("HeAlarm 0.1.0")
	color: "#f1f1f1"
	minimumWidth: swpView.currentItem.implicitWidth; minimumHeight: 600

	ColumnLayout {
		anchors.fill: parent

		ColumnLayout {
			Layout.margins: 24

			spacing: 18

			Controls.SwipeView {
				Layout.fillWidth: true; Layout.fillHeight: true

				id: swpView
				currentIndex: nvgBar.currentIndex
				onCurrentIndexChanged: nvgBar.currentIndex = currentIndex

				ClockPage {

				}

				AlarmPage {
					editPage: editPge
				}
			}

			NavigationBar {
				Layout.fillWidth: true

				id: nvgBar
			}
		}
	}

	AlarmEditPage {
		id: editPge
		anchors.fill: parent
		visible: false
		onCancled: visible = false
	}

	Platform.SystemTrayIcon {
		objectName: "sysTrayIcon"
		icon.source: "qrc:///res/Logo.png"
		tooltip: "HeAlarm 0.1.0"
		visible: true
	}
}
