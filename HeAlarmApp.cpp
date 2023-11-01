#include "HeAlarmApp.h"
#include "AlarmFileManager.h"
#include "AlarmModel.h"
#include "CoreNotifier.h"
#include "HeAlarm.h"
#include "TrayNotificationSender.h"
#include <QQmlApplicationEngine>

HeAlarmApp::HeAlarmApp(int argc, char** argv) :
	QGuiApplication {argc, argv}
{
	init();
}

void HeAlarmApp::init()
{
		HeAlarm::s_app = this;
		HeAlarm::s_qmlEngine = new QQmlApplicationEngine;
		HeAlarm::s_alarmModel = new AlarmModel;
		HeAlarm::s_alarmFileManager = new AlarmFileManager(HeAlarm::alarmModel());
		HeAlarm::s_notifier = new CoreNotifier(HeAlarm::alarmModel());
		QObject::connect(HeAlarm::qmlEngine(), &QQmlApplicationEngine::objectCreationFailed,
						 HeAlarm::app(), []() { QCoreApplication::exit(-1); },
		Qt::QueuedConnection);
		HeAlarm::qmlEngine()->loadFromModule("HeAlarm", "Main");
		HeAlarm::s_trayIcon = HeAlarm::qmlEngine()->rootObjects().at(0)->findChild<QObject*>("sysTrayIcon");
		HeAlarm::s_notificationSender = new TrayNotificationSender(HeAlarm::s_trayIcon);
		connect(HeAlarm::notifier(), &CoreNotifier::alarmTriggered, HeAlarm::s_notificationSender, &TrayNotificationSender::sendNotification);
}
