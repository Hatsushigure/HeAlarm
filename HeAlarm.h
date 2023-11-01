#pragma once
#include <QGuiApplication>
#include <QQmlEngine>

class AlarmFileManager;
class CoreNotifier;
class TrayNotificationSender;
class QQmlApplicationEngine;

class HeAlarm : public QGuiApplication
{
	Q_OBJECT
	QML_ELEMENT
public:
	enum DayOfWeek {Monday = 0x1, Tuesday = 0x2, Wednesday = 0x4, Thursday = 0x8, Friday = 0x10, Saturday = 0x20, Sunday = 0x40, Weekday = 0x1F, Weekend = 0x60, All = 0x7F};
	Q_ENUM(DayOfWeek)
private:
	static HeAlarm* s_app;
	static QQmlApplicationEngine* s_qmlEngine;
	static AlarmFileManager* s_alarmFileManager;
	static TrayNotificationSender* s_notificationSender;
public:
	static constexpr auto alarmFileVersion = 1;
public:
	explicit HeAlarm(int argc, char** argv);
public:
	static AlarmFileManager* alarmFileManager();
	static TrayNotificationSender* notificationSender();
	static void setNotificationSender(TrayNotificationSender* notificationSender);
private:
	void init();
public:
	static HeAlarm::DayOfWeek fromQtDayOfWeek(Qt::DayOfWeek original);
};

