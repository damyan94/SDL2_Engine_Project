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
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	m_ImageId	= Utils::ReadInt(readStrings[1], "id");
	m_TextId	= Utils::ReadInt(readStrings[2], "id");
	m_SoundId	= Utils::ReadInt(readStrings[3], "id");

	return true;
}