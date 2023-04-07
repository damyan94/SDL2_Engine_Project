// Corresponding header
#include "app/config/AppConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryTypeString = "ui_image";

// =============================================================================
bool AppConfig::Read(const ConfigStrings& readStrings)
{
	m_StartMenuConfig.Read(readStrings);

	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	m_ImageId	= Utils::ReadStringHashed(readStrings[startLine], "image_id").m_Hash;
	const auto& pos1 = Utils::ReadIntArray(readStrings[startLine], "position", 2);
	AssertReturnIf(pos1.size() != 2, false, _CONFIG_ERROR_INFO(startLine));
	m_ImagePos = Point(pos1[0], pos1[1]);

	m_TextId = Utils::ReadStringHashed(readStrings[startLine + 1], "text_id").m_Hash;
	const auto& pos2 = Utils::ReadIntArray(readStrings[startLine + 1], "position", 2);
	AssertReturnIf(pos2.size() != 2, false, _CONFIG_ERROR_INFO(startLine + 1));
	m_TextPos = Point(pos2[0], pos2[1]);

	return true;
}