#pragma once
#include <QObject>

class TrayNotificationSender : public QObject
{
	Q_OBJECT
private:
	QObject* m_trayIcon;
public:
	explicit TrayNotificationSender(QObject* trayIcon, QObject *parent = nullptr);
public slots:
	void sendNotification(const QVariant& var);
};

