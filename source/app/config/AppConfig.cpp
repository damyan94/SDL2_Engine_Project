// Corresponding header
#include "app/config/AppConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryTypeString = "image";

// =============================================================================
bool AppConfig::Read(const ConfigStrings& readStrings)
{
	m_StartMenuConfig.Read(readStrings);

	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	m_ImageId	= Utils::ReadStringHashed(readStrings[1], "id").m_Hash;
	m_TextId	= Utils::ReadStringHashed(readStrings[2], "id").m_Hash;
	m_SoundId	= Utils::ReadStringHashed(readStrings[3], "id").m_Hash;

	return true;
}