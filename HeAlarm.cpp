#include "HeAlarm.h"
#include "AlarmFileManager.h"
#include <QQmlApplicationEngine>

HeAlarm* HeAlarm::s_app = nullptr;
AlarmFileManager* HeAlarm::s_alarmFileManager = nullptr;
TrayNotificationSender* HeAlarm::s_notificationSender = nullptr;

HeAlarm::HeAlarm(int argc, char** argv)
	: QGuiApplication {argc, argv}
{
	init();
}

AlarmFileManager* HeAlarm::alarmFileManager()
{
	if (s_alarmFileManager == nullptr)
		s_alarmFileManager = new AlarmFileManager();
	return s_alarmFileManager;
}

TrayNotificationSender* HeAlarm::notificationSender()
{
	return s_notificationSender;
}

void HeAlarm::setNotificationSender(TrayNotificationSender* notificationSender)
{
	s_notificationSender = notificationSender;
}

void HeAlarm::init()
{
	QQmlApplicationEngine engine;
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
					 &app, []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	engine.loadFromModule("HeAlarm", "Main");
	auto trayIcon = engine.rootObjects().at(0)->findChild<QObject*>("sysTrayIcon");
	HeAlarm::setNotificationSender(new TrayNotificationSender(trayIcon));
}

HeAlarm::DayOfWeek HeAlarm::fromQtDayOfWeek(Qt::DayOfWeek original)
{
	auto val = 1 << (original - 1);
	return static_cast<HeAlarm::DayOfWeek>(val);
}
