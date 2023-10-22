#pragma once
#include <QObject>
#include <QQmlEngine>

class HeAlarm : public QObject
{
	Q_OBJECT
	QML_ELEMENT
public:
public:
	explicit HeAlarm(QObject *parent = nullptr);
};

