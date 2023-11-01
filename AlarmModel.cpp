#include "AlarmModel.h"
#include <AlarmData.h>
#include <AlarmFileManager.h>

AlarmModel::AlarmModel(QObject *parent) :
	QAbstractListModel{parent} {}

const QList<AlarmData>& AlarmModel::rawData() const
{
	return m_data;
}

int AlarmModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return 0;
	return m_data.size();
}

QVariant AlarmModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (index.row() < 0 || index.row() >= m_data.size())
		return QVariant();
	auto& ret = m_data[index.row()];
	switch (role)
	{
	case AlarmDataRoles::HourRole:
		return ret.hour;
	case AlarmDataRoles::MinuteRole:
		return ret.minute;
	case AlarmDataRoles::TitleRole:
		return ret.title;
	case AlarmDataRoles::ActiveDaysRole:
		return ret.activeDays;
	case AlarmDataRoles::IsActiveRole:
		return ret.isActive;
	default:
		return QVariant::fromValue(ret);
	}
}

QHash<int, QByteArray> AlarmModel::roleNames() const
{
	auto hash = QHash<int, QByteArray>();
	hash[AlarmDataRoles::HourRole] = "hour";
	hash[AlarmDataRoles::MinuteRole] = "minute";
	hash[AlarmDataRoles::TitleRole] = "title";
	hash[AlarmDataRoles::ActiveDaysRole] = "activeDays";
	hash[AlarmDataRoles::IsActiveRole] = "isActive";
	return hash;
}

void AlarmModel::append(const AlarmData& data)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_data.emplace_back(data);
	endInsertRows();
}

void AlarmModel::append(int hour, int minute, bool isActive, int activeDays, const QString& title)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_data.emplace_back(hour, minute, activeDays, title, isActive);
	endInsertRows();
}

void AlarmModel::setData(int row, const AlarmData& data)
{
	if (row < 0 || row >= m_data.size())
		return;
	if (m_data.at(row) == data)
		return;
	m_data[row] = data;
	emit dataChanged(index(row), index(row));
}

void AlarmModel::setData(int row, int hour, int minute, bool isActive, int activeDays, const QString& title)
{
	if (row < 0 || row >= m_data.size())
		return;
	setData(row, {hour, minute, activeDays, title, isActive});
}

void AlarmModel::setIsActive(int row, bool isActive)
{
	if (row < 0 || row >= m_data.size())
		return;
	if (m_data[row].isActive == isActive)
		return;
	m_data[row].isActive = isActive;
	emit dataChanged(index(row), index(row), {AlarmDataRoles::IsActiveRole});
}

void AlarmModel::remove(int row)
{
	if (row < 0 || row >= m_data.size())
		return;
	beginRemoveRows(QModelIndex(), row, row);
	m_data.remove(row);
	endRemoveRows();
}

void AlarmModel::clear()
{
	if (rowCount() == 0)
		return;
	beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
	m_data.clear();
	endRemoveRows();
}
