#include "TrayNotificationSender.h"
#include "AlarmData.h"

TrayNotificationSender::TrayNotificationSender(QObject* trayIcon, QObject *parent) :
	QObject{parent},
	m_trayIcon {trayIcon}
{

}

void TrayNotificationSender::sendNotification(const QVariant& var)
{
	auto alm = var.value<AlarmData>();
	QMetaObject::invokeMethod(m_trayIcon, "showMessage",
							  alm.title,
							  QTime::currentTime().toString("HH:mm")
							  );
}