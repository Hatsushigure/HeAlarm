#pragma once
#include <QObject>

class QSystemTrayIcon;

class TrayNotificationSender : public QObject
{
	Q_OBJECT
private:
	static constexpr int duration = 600000;
private:
	QSystemTrayIcon* m_trayIcon;
public:
	explicit TrayNotificationSender(QObject *parent = nullptr);
public slots:
	void sendNotification(const QVariant& var);
};

