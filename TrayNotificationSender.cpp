#include "TrayNotificationSender.h"
#include "AlarmData.h"
#include <QIcon>
#include <QSystemTrayIcon>

TrayNotificationSender::TrayNotificationSender(QObject *parent) :
	QObject{parent}
{
	m_trayIcon = new QSystemTrayIcon;
	m_trayIcon->setIcon(QIcon(":/res/Logo.png"));
	m_trayIcon->setToolTip("HeAlarm 0.1.1");
	m_trayIcon->show();
}

void TrayNotificationSender::sendNotification(const QVariant& var)
{
	auto alm = var.value<AlarmData>();
	m_trayIcon->showMessage(alm.title, QTime(alm.hour, alm.minute).toString("HH:mm"), m_trayIcon->icon(), 600000);
}
