#include "AlarmFileManager.h"
#include <QXmlStreamWriter>
#include "HeAlarm.h"
#include <format>

AlarmFileManager::AlarmFileManager(QList<AlarmData>* data) :
	m_data {data}
{
	m_file.setFileName(fileName);
	m_fileReader.setDevice(&m_file);
	m_fileWriter.setDevice(&m_file);
	m_fileWriter.setAutoFormatting(true);
}

void AlarmFileManager::setData(QList<AlarmData>* data)
{
	m_data = data;
}

void AlarmFileManager::write()
{
	if (m_data == nullptr)
	{
		qWarning() << "Alarm data list not initialized, skipping instead.";
		return;
	}
	m_file.open(QFile::WriteOnly);
	m_fileWriter.writeStartDocument(QString::number(HeAlarm::alarmFileVersion));
	m_fileWriter.writeStartElement("Alarms");
	for (const auto& alm : (*m_data))
	{
		m_fileWriter.writeStartElement("Alarm");
		m_fileWriter.writeAttribute("hour", std::format("{}", alm.hour));
		m_fileWriter.writeAttribute("minute", std::format("{}", alm.minute));
		m_fileWriter.writeAttribute("isActive", std::format("{}", alm.isActive));
		m_fileWriter.writeAttribute("activeDays", std::format("{}", alm.activeDays));
		m_fileWriter.writeAttribute("title", alm.title);
		m_fileWriter.writeEndElement();
	}
	m_fileWriter.writeEndElement();
	m_file.close();
}
