#pragma once
#include <QString>
#include <QQmlEngine>

struct AlarmData
{
	int hour {10};
	int minute {10};
	int activeDays {0};
	QString title {"闹铃"};
	bool isActive;
	bool operator==(const AlarmData& other) const;
};

