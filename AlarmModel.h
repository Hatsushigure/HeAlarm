#pragma once
#include <QAbstractListModel>
#include <QQmlEngine>
#include <QList>

class AlarmData;

class AlarmModel : public QAbstractListModel
{
	Q_OBJECT
	QML_ELEMENT
public:
	enum AlarmDataRoles {HourRole = Qt::UserRole + 1, MinuteRole, ActiveDaysRole, TitleRole, IsActiveRole};
	Q_ENUM(AlarmDataRoles)
private:
	QList<AlarmData*> m_data {};
public:
	explicit AlarmModel(QObject *parent = nullptr);
public:
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	// Add data:
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
	// Remove data:
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
	QHash<int, QByteArray> roleNames() const override;
	Q_INVOKABLE void addTestData();
};

