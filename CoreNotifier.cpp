#include "CoreNotifier.h"
#include "AlarmModel.h"
#include <QTimer>
#include "AlarmData.h"
#include <QDateTime>
#include "HeAlarm.h"

CoreNotifier::CoreNotifier(const AlarmModel* model, QObject *parent) :
	QObject{parent},
	m_model {model}
{
	connect(m_model, &AlarmModel::dataChanged, this, &CoreNotifier::restartTimers);
	connect(m_model, &AlarmModel::layoutChanged, this, &CoreNotifier::restartTimers);
	connect(m_model, &AlarmModel::rowsInserted, this, &CoreNotifier::restartTimers);
	connect(m_model, &AlarmModel::rowsMoved, this, &CoreNotifier::restartTimers);
	connect(m_model, &AlarmModel::rowsRemoved, this, &CoreNotifier::restartTimers);
	restartTimers();
}

void CoreNotifier::restartTimers()
{
	for (auto pt : m_timerList)
		delete pt;
	m_timerList.clear();
	const auto& data = m_model->rawData();
	for (const auto& alm : data)
	{
		if (!alm.isActive)
			continue;
		auto current = QDateTime::currentDateTime();
		if ((alm.activeDays != 0) && ((alm.activeDays & HeAlarm::fromQtDayOfWeek(static_cast<Qt::DayOfWeek>(current.date().dayOfWeek()))) == 0))
			continue;
		auto targetTime = QDateTime(QDate::currentDate(), {alm.hour, alm.minute});
		auto duration = current.msecsTo(targetTime);
		if (duration <= 0)
			continue;
		qInfo() << "Starting alarm " << alm.title << "after" << duration << "ms";
		auto timer = new QTimer(this);
		m_timerList.push_back(timer);
		connect(timer, &QTimer::timeout, this, [this, alm]() {emit this->alarmTriggered(QVariant::fromValue(alm));});
		timer->setInterval(duration);
		timer->setSingleShot(true);
		timer->start();
	}
}
