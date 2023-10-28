#pragma once
#include <QObject>
#include <QQmlEngine>

class AlarmData : public QObject
{
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(int hour READ hour WRITE setHour NOTIFY hourChanged FINAL)
	Q_PROPERTY(int minute READ minute WRITE setMinute NOTIFY minuteChanged FINAL)
	Q_PROPERTY(int activeDays READ activeDays WRITE setActiveDays NOTIFY activeDaysChanged FINAL)
	Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
	Q_PROPERTY(bool isActive READ isActive WRITE setIsActive NOTIFY isActiveChanged FINAL)
public:
	struct AlarmData_data
	{
		int hour {10};
		int minute {10};
		int activeDays {0};
		QString title {"闹铃"};
		bool isActive;
	};
private:
	AlarmData_data m_data;
public:
	AlarmData(QObject* parent = nullptr);
	AlarmData(int hour, int minute, int activeDays, const QString& title, bool isActive, QObject* parent = nullptr);
	AlarmData(const AlarmData_data& data);
	AlarmData(AlarmData_data&& data);
public:
	int hour() const {return m_data.hour;}
	void setHour(int newHour);
	int minute() const {return m_data.minute;}
	void setMinute(int newMinute);
	int activeDays() const {return m_data.activeDays;}
	void setActiveDays(int newActiveDays);
	QString title() const {return m_data.title;}
	void setTitle(const QString& newTitle);
	bool isActive() const {return m_data.isActive;}
	void setIsActive(bool newIsActive);
signals:
	void hourChanged();
	void minuteChanged();
	void activeDaysChanged();
	void titleChanged();
	void isActiveChanged();
};

