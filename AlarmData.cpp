#include "AlarmData.h"

bool AlarmData::operator==(const AlarmData& other) const
{
	return hour == other.hour &&
			minute == other.minute &&
			isActive == other.isActive &&
			activeDays == other.activeDays &&
			title == other.title;

}
