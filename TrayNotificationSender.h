#pragma once
#include <QObject>

class TrayNotificationSender : public QObject
{
	Q_OBJECT
private:
	static constexpr int duration = 600000;
private:
	QObject* m_trayIcon;
public:
	explicit TrayNotificationSender(QObject* trayIcon, QObject *parent = nullptr);
public slots:
	void sendNotification(const QVariant& var);
};

