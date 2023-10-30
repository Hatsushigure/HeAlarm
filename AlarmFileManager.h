#pragma once
#include "AlarmData.h"
#include <QList>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class AlarmFileManager
{
	static constexpr auto fileName = "alarms.xml";
private:
	QFile m_file;
	QList<AlarmData>* m_data;
	QXmlStreamWriter m_fileWriter;
	QXmlStreamReader m_fileReader;
public:
	AlarmFileManager(QList<AlarmData>* data = nullptr);
public:
	void setData(QList<AlarmData>* data);
public:
	void write();
};

