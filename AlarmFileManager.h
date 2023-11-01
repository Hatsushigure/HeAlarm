#pragma once
#include <QList>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class AlarmModel;

class AlarmFileManager : public QObject
{
	static constexpr auto fileName = "alarms.xml";
private:
	QFile m_file;
	AlarmModel* m_model;
	QXmlStreamWriter m_fileWriter;
	QXmlStreamReader m_fileReader;
public:
	explicit AlarmFileManager(AlarmModel* model, QObject* parent = nullptr);
public slots:
	void write();
	void read();
};

