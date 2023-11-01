#pragma once
#include <QAbstractListModel>
#include <QQmlEngine>
#include <QList>
#include "AlarmData.h"

class AlarmData;

class AlarmModel : public QAbstractListModel
{
	Q_OBJECT
	QML_ELEMENT
public:
	enum AlarmDataRoles {HourRole = Qt::UserRole + 1, MinuteRole, ActiveDaysRole, TitleRole, IsActiveRole};
	Q_ENUM(AlarmDataRoles)
private:
	QList<AlarmData> m_data {};
public:
	explicit AlarmModel(QObject *parent = nullptr);
public:
	const QList<AlarmData>& rawData() const;
public:
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;
public slots:
	void append(const AlarmData& data);
	void append(int hour = 10, int minute = 10, bool isActive = true, int activeDays = 0, const QString& title = "闹铃");
	void setData(int row, const AlarmData& data);
	void setData(int row, int hour, int minute, bool isActive, int activeDays, const QString& title);
	void setIsActive(int row, bool isActive);
	void remove(int row);
	void clear();
};

