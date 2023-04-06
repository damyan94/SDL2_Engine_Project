// Corresponding header
#include "components/ui/components/config/CheckboxConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "utils/geometry/Position.h"
#include "defines/ConfigFilePaths.h"

static const std::string c_CategoryString = "ui_component";
static const std::string c_TypeString = "checkbox";

// =============================================================================
bool CheckboxConfig::Read(const ConfigStrings& readStrings, UIComponentId id)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryString.c_str());
		return true;
	}

	for (size_t i = startLine; i < readStrings.size(); i++)
	{
		BreakIf(Utils::ReadString(readStrings[i], "category") != c_CategoryString);
		ContinueIf(Utils::ReadString(readStrings[i], "type") != c_TypeString);
		ContinueIf(Utils::ReadStringHashed(readStrings[i], "id").m_Hash != id);

		const auto& pos = Utils::ReadIntArray(readStrings[i], "position", 2);
		AssertReturnIf(pos.size() != 2, false, _CONFIG_ERROR_INFO(i));
		m_Pos = Point(pos[0], pos[1]);

		m_ImageId = Utils::ReadStringHashed(readStrings[i], "image_id").m_Hash;
		/*AssertReturnIf(!IsResourceIdValid(ImageId, m_ImageId), false,
			_CONFIG_ERROR_INFO(i));*/

		m_TextId = Utils::ReadStringHashed(readStrings[i], "text_id").m_Hash;
		/*AssertReturnIf(!IsResourceIdValid(TextId, m_TextId), false,
			_CONFIG_ERROR_INFO(i));*/

		m_SoundId = Utils::ReadStringHashed(readStrings[i], "sound_id").m_Hash;
		/*AssertReturnIf(!IsResourceIdValid(SoundId, m_SoundId), false,
			_CONFIG_ERROR_INFO(i));*/
	}

	return true;
}