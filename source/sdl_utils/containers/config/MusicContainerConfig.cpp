// Corresponding header
#include "sdl_utils/containers/config/MusicContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryTypeString = "music";

// =============================================================================
bool MusicContainerConfig::Read(const ConfigStrings& readStrings)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_CategoryTypeString);

		const int32_t id = Utils::ReadInt(readStrings[i], "id");

		MusicConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false, _CONFIG_ERROR_INFO(i));

		newCfg.m_Volume = Utils::ReadInt(readStrings[i], "volume");
		AssertReturnIf(newCfg.m_Volume <= 0, false, _CONFIG_ERROR_INFO(i));

		m_MusicContainerConfig.emplace(MusicId(i), std::move(newCfg));
	}

	return true;
}