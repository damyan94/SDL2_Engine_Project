#include "stdafx.h"

#include "Application/Application/Settings/Settings.h"
#include "System/Defines/ConfigFilePaths.h"

static const std::string c_SettingsFileName = ConfigFilePaths::ConfigFilePath("Config/Settings.cfg");

////////////////////////////////////////////////////////////////////////////////
Settings::Settings()
	: m_SettingsFile(c_SettingsFileName, EWriteMode::Out)
	, m_TargetFPS(0)
	, m_Language(ELanguage::Invalid)
{
}

////////////////////////////////////////////////////////////////////////////////
Settings::~Settings()
{
}

////////////////////////////////////////////////////////////////////////////////
Settings& Settings::Instance()
{
	static Settings instance;
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
bool Settings::Read()
{
	ReturnIf(!m_SettingsFile.IsOpen(), false);

	const auto& readStrings = m_SettingsFile.GetFileContents();

	auto findString = [&](const std::string& lookup) -> const std::string&
		{
			const auto it = std::find_if(readStrings.begin(), readStrings.end(),
				[&](const std::string& text)
				{
					return text.find(lookup) != std::string::npos;
				});
			AssertReturnIf(it == readStrings.end(), "");

			return *it;
		};

	m_TargetFPS = Utils::ReadInt(findString("fps"), "fps");
	AssertReturnIf(m_TargetFPS <= 0 || m_TargetFPS > 100, false);

	const std::string langString = Utils::ReadString(findString("language"), "language");
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

	m_SettingsFile.Write(writeString);

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