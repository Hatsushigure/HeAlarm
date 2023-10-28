#include "AlarmData.h"

AlarmData::AlarmData(QObject* parent) :
	QObject {parent} {}

AlarmData::AlarmData(int hour, int minute, int activeDays, const QString& title, bool isActive, QObject* parent) :
	QObject {parent},
	m_data {hour, minute, activeDays, title, isActive} {}

AlarmData::AlarmData(const AlarmData_data& data) :
	m_data {data} {}

AlarmData::AlarmData(AlarmData_data&& data) :
	m_data {data} {}

void AlarmData::setHour(int newHour)
{
	if (m_data.hour == newHour)
		return;
	m_data.hour = newHour;
	emit hourChanged();
}

void AlarmData::setMinute(int newMinute)
{
	if (m_data.minute == newMinute)
		return;
	m_data.minute = newMinute;
	emit minuteChanged();
}

void AlarmData::setActiveDays(int newActiveDays)
{
	if (m_data.activeDays == newActiveDays)
		return;
	m_data.activeDays = newActiveDays;
	emit activeDaysChanged();
}

void AlarmData::setTitle(const QString& newTitle)
{
	if (m_data.title == newTitle)
		return;
	m_data.title = newTitle;
	emit titleChanged();
}

void AlarmData::setIsActive(bool newIsActive)
{
	if (m_data.isActive == newIsActive)
		return;
	m_data.isActive = newIsActive;
	emit isActiveChanged();
}
