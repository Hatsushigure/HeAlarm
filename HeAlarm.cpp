#include "HeAlarm.h"
#include "AlarmFileManager.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>

HeAlarmApp* HeAlarm::s_app = nullptr;
QQmlApplicationEngine* HeAlarm::s_qmlEngine = nullptr;
AlarmFileManager* HeAlarm::s_alarmFileManager = nullptr;
AlarmModel* HeAlarm::s_alarmModel = nullptr;
CoreNotifier* HeAlarm::s_notifier = nullptr;
TrayNotificationSender* HeAlarm::s_notificationSender = nullptr;

HeAlarm::HeAlarm(QObject* parent)
	: QObject {parent} {}

HeAlarmApp* HeAlarm::app()
{
	return s_app;
}

QQmlApplicationEngine* HeAlarm::qmlEngine()
{
	return s_qmlEngine;
}

AlarmFileManager* HeAlarm::alarmFileManager()
{
	return s_alarmFileManager;
}

AlarmModel* HeAlarm::alarmModel()
{
	return s_alarmModel;
}

CoreNotifier* HeAlarm::notifier()
{
	return s_notifier;
}

TrayNotificationSender* HeAlarm::notificationSender()
{
	return s_notificationSender;
}

HeAlarm::DayOfWeek HeAlarm::fromQtDayOfWeek(Qt::DayOfWeek original)
{
	auto val = 1 << (original - 1);
	return static_cast<HeAlarm::DayOfWeek>(val);
}
