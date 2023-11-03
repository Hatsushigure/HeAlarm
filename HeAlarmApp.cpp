#include "HeAlarmApp.h"
#include "AlarmFileManager.h"
#include "AlarmModel.h"
#include "CoreNotifier.h"
#include "HeAlarm.h"
#include "TrayNotificationSender.h"
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QPixmap>

HeAlarmApp::HeAlarmApp(int argc, char** argv) :
	QGuiApplication {argc, argv}
{
	init();
}

void HeAlarmApp::init()
{
	fillAppInfo();
	HeAlarm::s_app = this;
	HeAlarm::s_qmlEngine = new QQmlApplicationEngine;
	HeAlarm::s_alarmModel = new AlarmModel;
	HeAlarm::s_alarmFileManager = new AlarmFileManager(HeAlarm::alarmModel());
	HeAlarm::s_notifier = new CoreNotifier(HeAlarm::alarmModel());
	HeAlarm::s_notificationSender = new TrayNotificationSender;
	connect(HeAlarm::notifier(), &CoreNotifier::alarmTriggered, HeAlarm::s_notificationSender, &TrayNotificationSender::sendNotification);
	QObject::connect(HeAlarm::qmlEngine(), &QQmlApplicationEngine::objectCreationFailed,
					 HeAlarm::app(), []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	HeAlarm::qmlEngine()->loadFromModule("HeAlarm", "Main");
}

void HeAlarmApp::fillAppInfo()
{
	setApplicationName("HeAlarm");
	setApplicationDisplayName("HeAlarm");
	setApplicationVersion(HeAlarm::versionString());
	setOrganizationName("初時雨");
	setOrganizationDomain("Hatsushigure.github.io");
	auto  pix = QPixmap(":/res/Logo.png");
	auto icon = QIcon();
	icon.addPixmap(pix);
	icon.addPixmap(pix.scaled({64, 64}, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	icon.addPixmap(pix.scaled({48, 48}, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	icon.addPixmap(pix.scaled({32, 32}, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	icon.addPixmap(pix.scaled({16, 16}, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	setWindowIcon(QIcon(pix));
}
