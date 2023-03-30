// Corresponding header
#include "engine/settings/Settings.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "sdl_utils/Utils.h"

static const std::string c_SettingsFileName = "config/settings.cfg";

Settings* const g_Settings = new Settings;

// =============================================================================
Settings::Settings()
	: m_TargetFPS(0)
	, m_Language(ELanguage::Invalid)
{
}

// =============================================================================
Settings::~Settings()
{
}

// =============================================================================
bool Settings::Read()
{
	ConfigStrings readStrings;

	ReturnIf(!ReadWriteFile::ReadFromFile(c_SettingsFileName, readStrings), false);
	AssertReturnIf(readStrings.size() != 2, false,
		"Settings file corrupted: " + c_SettingsFileName);

	m_TargetFPS = Utils::ReadInt(readStrings[0], "fps");
	AssertReturnIf(m_TargetFPS <= 0 || m_TargetFPS >= 100, false,
		"FPS must be between 0 and 100.");

	const std::string langString = Utils::ReadString(readStrings[1], "language");
	m_Language = Utils::GetLanguageIdFromString(langString);
	AssertReturnIf(!IsEnumValueValid(m_Language), false,
		"Invalid language received from settings file: " + c_SettingsFileName);

	return true;
}

// =============================================================================
bool Settings::Write()
{
	std::string writeString;

	writeString +="fps=" + std::to_string(m_TargetFPS) + '\n';
	writeString +="language=\"" + Utils::GetLanguageStringFromId(m_Language) + "\"";

	ReadWriteFile::WriteToFile(c_SettingsFileName, writeString, EWriteMode::Out);

	return true;
}

// =============================================================================
int32_t Settings::GetTargetFPS() const
{
	return m_TargetFPS;
}

// =============================================================================
ELanguage Settings::GetLanguage() const
{
	return m_Language;
}

// =============================================================================
void Settings::SetTargetFPS(int32_t targetFPS)
{
	m_TargetFPS = targetFPS;
}

// =============================================================================
void Settings::SetLanguage(ELanguage language)
{
	m_Language = language;
}