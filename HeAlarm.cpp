#include "HeAlarm.h"
#include "AlarmFileManager.h"

AlarmFileManager* HeAlarm::s_alarmFileManager = nullptr;

HeAlarm::HeAlarm(QObject *parent)
	: QObject{parent}
{

}

AlarmFileManager* HeAlarm::alarmFileManager()
{
	if (s_alarmFileManager == nullptr)
		s_alarmFileManager = new AlarmFileManager();
	return s_alarmFileManager;
}

HeAlarm::DayOfWeek HeAlarm::fromQtDayOfWeek(Qt::DayOfWeek original)
{
	auto val = 1 << (original - 1);
	return static_cast<HeAlarm::DayOfWeek>(val);
}
