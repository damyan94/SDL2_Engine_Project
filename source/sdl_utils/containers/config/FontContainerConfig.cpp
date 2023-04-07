// Corresponding header
#include "sdl_utils/containers/config/FontContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_TypeString = "font";

// =============================================================================
bool FontContainerConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_TypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_TypeString.c_str());
		return true;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "type") != c_TypeString);

		const int32_t id = Utils::ReadStringHashed(readStrings[i], "id").m_Hash;

		FontConfig newCfg;

		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		AssertReturnIf(newCfg.m_FileName.empty(), false, _CONFIG_ERROR_INFO(i));

		newCfg.m_Size = Utils::ReadInt(readStrings[i], "size");
		AssertReturnIf(newCfg.m_Size <= 0, false, _CONFIG_ERROR_INFO(i));

		newCfg.m_WrapAlign = EFontWrapAlign(Utils::ReadInt(readStrings[i], "wrap_align"));
		AssertReturnIf(!IsEnumValueValid(newCfg.m_WrapAlign), false, _CONFIG_ERROR_INFO(i));

		m_FontContainerConfig.emplace(FontId(id), std::move(newCfg));
	}

	return true;
}