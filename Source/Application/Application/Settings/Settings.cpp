#include "stdafx.h"

#include "Application/Application/Settings/Settings.h"
#include "System/Defines/ConfigFilePaths.h"

static const std::string c_SettingsFileName = ConfigFilePaths::ConfigFilePath("Config/Settings.cfg");

Settings* const g_Settings = new Settings;

////////////////////////////////////////////////////////////////////////////////
Settings::Settings()
	: m_TargetFPS(0)
	, m_Language(ELanguage::Invalid)
{
}

////////////////////////////////////////////////////////////////////////////////
Settings::~Settings()
{
}

////////////////////////////////////////////////////////////////////////////////
bool Settings::Read()
{
	std::string readString;

	ReturnIf(!ReadWriteFile::ReadFromFile(c_SettingsFileName, readString), false);

	m_TargetFPS = Utils::ReadInt(readString, "fps");
	AssertReturnIf(m_TargetFPS <= 0 || m_TargetFPS > 100, false);

	const std::string langString = Utils::ReadString(readString, "language");
	m_Language = Utils::GetLanguageIdFromString(langString);
	AssertReturnIf(!IsEnumValueValid(m_Language) &&
		("Invalid language received from settings file: " + c_SettingsFileName).c_str(), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool Settings::Write()
{
	std::string writeString;

	writeString += "# Important: do not change the order of the settings!\n\n";
	writeString +="fps=" + std::to_string(m_TargetFPS) + ";\n";
	writeString +="language=" + Utils::GetLanguageStringFromId(m_Language) + ";\n";

	ReadWriteFile::WriteToFile(c_SettingsFileName, writeString, EWriteMode::Out);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
int32_t Settings::GetTargetFPS() const
{
	return m_TargetFPS;
}

////////////////////////////////////////////////////////////////////////////////
ELanguage Settings::GetLanguage() const
{
	return m_Language;
}

////////////////////////////////////////////////////////////////////////////////
void Settings::SetTargetFPS(int32_t targetFPS)
{
	m_TargetFPS = targetFPS;
}

////////////////////////////////////////////////////////////////////////////////
void Settings::SetLanguage(ELanguage language)
{
	m_Language = language;
}