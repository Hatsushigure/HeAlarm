#include "AlarmFileManager.h"
#include <QXmlStreamWriter>
#include "AlarmModel.h"
#include "HeAlarm.h"
#include <format>

AlarmFileManager::AlarmFileManager(AlarmModel* model, QObject* parent) :
	QObject {parent},
	m_model {model}
{
	m_file.setFileName(fileName);
	m_fileReader.setDevice(&m_file);
	m_fileWriter.setDevice(&m_file);
	m_fileWriter.setAutoFormatting(true);
	read();
	connect(m_model, &AlarmModel::dataChanged, this, &AlarmFileManager::write);
	connect(m_model, &AlarmModel::rowsInserted, this, &AlarmFileManager::write);
	connect(m_model, &AlarmModel::rowsMoved, this, &AlarmFileManager::write);
	connect(m_model, &AlarmModel::rowsRemoved, this, &AlarmFileManager::write);
}

void AlarmFileManager::write()
{
	if (m_model == nullptr)
	{
		qWarning() << "Alarm data list not initialized, skipping instead.";
		return;
	}
	m_file.open(QFile::WriteOnly);
	m_fileWriter.writeStartDocument();
	m_fileWriter.writeStartElement("AlarmData");
	m_fileWriter.writeTextElement("FileVersion", std::format("{}", HeAlarm::alarmFileVersion));
	for (const auto& alm : m_model->rawData())
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
	m_fileWriter.writeEndDocument();
	m_file.close();
}

void AlarmFileManager::read()
{
	if (m_model == nullptr)
	{
		qWarning() << "Alarm data list not initialized, skipping instead.";
		return;
	}
	m_model->clear();
	m_file.open(QFile::ReadOnly);
	while (!m_fileReader.atEnd())
	{
		auto tokenType = m_fileReader.readNext();
		switch (tokenType)
		{
		case QXmlStreamReader::StartElement:
		{
			auto name = m_fileReader.name();
			if (name == u"FileVersion")
			{
				m_fileReader.readNext();
				auto ver = m_fileReader.text().toInt();
				if (ver > HeAlarm::alarmFileVersion)
				{
					qWarning() << "Cannot read a file that has an unsupported version. Try to update your software.";
					m_file.close();
					return;
				}
			}
			else if (name == u"Alarm")
			{
				auto almData = AlarmData();
				auto attributes = m_fileReader.attributes();
				almData.hour = attributes.value("hour").toInt();
				almData.minute = attributes.value("minute").toInt();
				almData.isActive = attributes.value("isActive") == u"true" ? true : false;
				almData.activeDays = attributes.value("activeDays").toInt();
				almData.title = attributes.value("title").toString();
				m_model->append(almData);
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}
	m_file.close();
}
