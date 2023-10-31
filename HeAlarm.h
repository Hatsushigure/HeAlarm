#pragma once
#include <QObject>
#include <QQmlEngine>

class AlarmFileManager;
class CoreNotifier;

class HeAlarm : public QObject
{
	Q_OBJECT
	QML_ELEMENT
public:
	enum DayOfWeek {Monday = 0x1, Tuesday = 0x2, Wednesday = 0x4, Thursday = 0x8, Friday = 0x10, Saturday = 0x20, Sunday = 0x40, Weekday = 0x1F, Weekend = 0x60, All = 0x7F};
	Q_ENUM(DayOfWeek)
private:
	static AlarmFileManager* s_alarmFileManager;
public:
	static constexpr auto alarmFileVersion = 1;
public:
	explicit HeAlarm(QObject *parent = nullptr);
public:
	static AlarmFileManager* alarmFileManager();
public:
	static HeAlarm::DayOfWeek fromQtDayOfWeek(Qt::DayOfWeek original);
};

