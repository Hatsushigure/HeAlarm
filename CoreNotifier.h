#pragma once
#include <QObject>
#include <QList>
#include <QVariant>

class AlarmModel;
class QTimer;

class CoreNotifier : public QObject
{
	Q_OBJECT
private:
	AlarmModel* m_model;
	QList<QTimer*> m_timerList;
public:
	explicit CoreNotifier(AlarmModel* model, QObject *parent = nullptr);
signals:
	void alarmTriggered(QVariant data);
private slots:
	void restartTimers();
};
