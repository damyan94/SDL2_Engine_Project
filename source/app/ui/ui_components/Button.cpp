// Corresponding header
#include "app/ui/ui_components/Button.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/geometry/Position.h"

#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "defines/ConfigFilePaths.h"
#include "sdl_utils/containers/text_container/TextData.h"

static const std::string c_CategoryTypeString = "ui";

// =============================================================================
bool ButtonConfig::Read()
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
Button::Button()
{
}

// =============================================================================
Button::~Button()
{
	Deinit();
}

// =============================================================================
bool Button::Init(const ButtonConfig& cfg)
{
	m_Image.Init(cfg.m_ImageId);
	m_Text.Init(cfg.m_TextId);
	m_Sound.Init(cfg.m_SoundId);

	m_Image.Resize(200);

	return true;
}

// =============================================================================
void Button::Deinit()
{
}

// =============================================================================
void Button::HandleEvent(const InputEvent& e)
{
	if ((e.m_Type == EEventType::KeyboardPress || e.m_Type == EEventType::KeyboardRelease) &&
		(e.m_Key == EKeyboardKey::E || e.m_Key == EKeyboardKey::R))
	{
		SetPosition(m_Image.GetPos());
	}

	ReturnIf(!m_Image.ContainsPoint(e.m_Pos), void());

	if (e.m_Type == EEventType::MouseButtonDown)
	{
		m_Image.SetNextFrame();
		m_Sound.Play();
	}
	else if (e.m_Type == EEventType::MouseButtonUp)
	{
		m_Image.SetPrevFrame();
	}
}

// =============================================================================
void Button::Update(int32_t dt)
{
}

// =============================================================================
void Button::Draw() const
{
	m_Image.Draw();
	m_Text.Draw();
}

// =============================================================================
void Button::SetPosition(const Point& pos)
{
	m_Image.SetPos(pos);

	const auto textPos = Position::MiddleCenter(m_Text.GetData()->m_FrameRect, m_Image.GetPosRect());
	m_Text.SetPos(textPos);
}