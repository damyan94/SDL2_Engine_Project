// Corresponding header
#include "components/ui/Checkbox.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "defines/ConfigFilePaths.h"

const int32_t STANDARD_SPACING = 4;

static const std::string c_CategoryTypeString = "checkbox";

// =============================================================================
bool CheckboxConfig::Read()
{
	ConfigStrings readStrings;

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::ObjectsConfig, readStrings), false);
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	m_ImageId = Utils::ReadInt(readStrings[startLine], "image_id");
	AssertReturnIf(!IsResourceIdValid(ImageId, m_ImageId), false,
		_CONFIG_ERROR_INFO(startLine));

	m_TextId = Utils::ReadInt(readStrings[startLine], "text_id");
	AssertReturnIf(!IsResourceIdValid(TextId, m_TextId), false,
		_CONFIG_ERROR_INFO(startLine));

	m_SoundId = Utils::ReadInt(readStrings[startLine], "sound_id");
	AssertReturnIf(!IsResourceIdValid(SoundId, m_SoundId), false,
		_CONFIG_ERROR_INFO(startLine));

	return true;
}

// =============================================================================
Checkbox::Checkbox()
{
}

// =============================================================================
Checkbox::~Checkbox()
{
	Deinit();
	UIComponentBase::~UIComponentBase();
}

// =============================================================================
bool Checkbox::Init(const CheckboxConfig& cfg)
{
	UIComponentBase::Init({ cfg.m_ImageId });

	m_Text.Init(cfg.m_TextId);
	m_Sound.Init(cfg.m_SoundId);

	return true;
}

// =============================================================================
void Checkbox::Deinit()
{
	UIComponentBase::Deinit();
}

// =============================================================================
void Checkbox::HandleEvent(const InputEvent& e)
{
	if ((m_Image.ContainsPoint(e.m_Pos) || m_Text.ContainsPoint(e.m_Pos))
		&& e.m_Type == EEventType::MouseButtonDown && e.m_Mouse == EMouseKey::Left)
	{
		m_IsActive = !m_IsActive;
		m_Image.SetCurrFrame(m_IsActive + (int32_t)ECheckboxFrames::Normal);
	}
}

// =============================================================================
void Checkbox::Update(int32_t dt)
{
}

// =============================================================================
void Checkbox::Draw() const
{
	UIComponentBase::Draw();
	m_Text.Draw();
}

// =============================================================================
void Checkbox::SetPosition(const Point& newPos)
{
	UIComponentBase::SetPosition(newPos);

	m_Text.SetPos(m_Pos.x + m_Image.GetWidth() + STANDARD_SPACING,
		m_Pos.y + (m_Image.GetHeight() - m_Text.GetHeight()) / 2);
}

// =============================================================================
void Checkbox::Reset()
{
	m_IsActive = false;
	m_Image.SetCurrFrame((int32_t)ECheckboxFrames::Normal);
	SetPosition(m_Pos);
}