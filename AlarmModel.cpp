#include "AlarmModel.h"
#include <AlarmData.h>

AlarmModel::AlarmModel(QObject *parent)
	: QAbstractListModel(parent)
{
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
	auto ret = m_data[index.row()];
	switch (role)
	{
	case AlarmDataRoles::HourRole:
		return ret->hour();
	case AlarmDataRoles::MinuteRole:
		return ret->minute();
	case AlarmDataRoles::TitleRole:
		return ret->title();
	case AlarmDataRoles::ActiveDaysRole:
		return ret->activeDays();
	case AlarmDataRoles::IsActiveRole:
		return ret->isActive();
	default:
		return QVariant::fromValue(ret);
	}
}

bool AlarmModel::insertRows(int row, int count, const QModelIndex &parent)
{
	if (parent.isValid())
		return false;
	if (row < 0 || row > m_data.size() || count < 1)
		return false;
	beginInsertRows(parent, row, row + count - 1);
	for (auto i = row; i < row + count; i++)
		m_data.insert(i, new AlarmData);
	endInsertRows();
	return true;
}

bool AlarmModel::removeRows(int row, int count, const QModelIndex &parent)
{
	if (parent.isValid())
		return false;
	if (row < 0 || row > m_data.size() || count < 1 || row + count > m_data.size())
		return false;
	beginRemoveRows(parent, row, row + count - 1);
	for (auto i = row + count - 1; i >= row; i--)
		delete m_data[i];
	m_data.remove(row, count);
	endRemoveRows();
	return true;
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

void AlarmModel::addTestData()
{
	insertRows(0, 1);
	m_data[0]->setHour(1);
}
