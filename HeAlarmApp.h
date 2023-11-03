#pragma once
#include <QGuiApplication>

class HeAlarmApp: public QGuiApplication
{
public:
	HeAlarmApp(int argc, char** argv);
private:
	void init();
	void fillAppInfo();
};

