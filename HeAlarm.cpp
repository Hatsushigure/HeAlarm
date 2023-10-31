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
