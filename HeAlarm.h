#pragma once
#include <QObject>
#include <QQmlEngine>

class AlarmFileManager;
class CoreNotifier;
class TrayNotificationSender;
class QQmlApplicationEngine;
class AlarmModel;
class HeAlarmApp;

class HeAlarm : public QObject
{
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(AlarmModel* alarmModel READ alarmModel CONSTANT)
	friend class HeAlarmApp;
public:
	enum DayOfWeek {Monday = 0x1, Tuesday = 0x2, Wednesday = 0x4, Thursday = 0x8, Friday = 0x10, Saturday = 0x20, Sunday = 0x40, Weekday = 0x1F, Weekend = 0x60, All = 0x7F};
	Q_ENUM(DayOfWeek)
private:
	const static auto s_versionMajor = 0;
	const static auto s_versionMinor = 1;
	const static auto s_versionPatch = 1;
	private:
	static HeAlarmApp* s_app;
	static QQmlApplicationEngine* s_qmlEngine;
	static AlarmFileManager* s_alarmFileManager;
	static AlarmModel* s_alarmModel;
	static CoreNotifier* s_notifier;
	static TrayNotificationSender* s_notificationSender;
public:
	static constexpr auto alarmFileVersion = 1;
public:
	explicit HeAlarm(QObject* parent = nullptr);
public:
	static QString versionString();
	static HeAlarmApp* app();
	static QQmlApplicationEngine* qmlEngine();
	static AlarmFileManager* alarmFileManager();
	static AlarmModel* alarmModel();
	static CoreNotifier* notifier();
	static TrayNotificationSender* notificationSender();
public:
	static HeAlarm::DayOfWeek fromQtDayOfWeek(Qt::DayOfWeek original);
};

