// Corresponding header
#include "components/ui/TextBox.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/geometry/Position.h"

#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "defines/ConfigFilePaths.h"
#include "sdl_utils/containers/text_container/TextData.h"
#include "sdl_utils/drawing/SDLDrawing.h"

static const std::string c_CategoryTypeString = "text_box";

// =============================================================================
bool TextBoxConfig::Read()
{
	return true;
}

// =============================================================================
TextBox::TextBox()
	: m_MaxChars(0)
{
}

// =============================================================================
TextBox::~TextBox()
{
	Deinit();
	UIComponentBase::~UIComponentBase();
}

// =============================================================================
bool TextBox::Init(const TextBoxConfig& cfg)
{
	m_Image.Init(cfg.m_ImageId);
	//_text.Init(L" ", cfg.fontId, cfg.textColor);
	//_text.SetPos(10000, 10000);
	//_text.Hide();

	m_TextInputter.Init({ 32, "", 1100000, Colors::Black });

	return true;
}

// =============================================================================
void TextBox::Deinit()
{
	UIComponentBase::Deinit();
}

// =============================================================================
void TextBox::HandleEvent(const InputEvent& e)
{
	if (m_Image.ContainsPoint(e.m_Pos) && e.m_Type == EEventType::MouseButtonDown
		&& e.m_Mouse == EMouseKey::Left)
	{
		m_TextInputter.ToggleActive(true);
		m_IsActive = true;
	}

	else if (m_IsActive && (!m_Image.ContainsPoint(e.m_Pos) &&
		(e.m_Type == EEventType::MouseButtonDown && e.m_Mouse == EMouseKey::Left)) ||
			(e.m_Type == EEventType::KeyboardPress && e.m_Key == EKeyboardKey::Escape))
	{
		Reset();
		m_TextInputter.ToggleActive(false);
		m_IsActive = false;
	}

	if (m_IsActive)
	{
		m_TextInputter.HandleEvent(e);
	}
}

// =============================================================================
void TextBox::Update(int32_t dt)
{
	m_TextInputter.Update(dt);
}

// =============================================================================
void TextBox::Draw() const
{
	UIComponentBase::Draw();
	m_TextInputter.Draw();

	if (m_IsActive)
	{
		SDLDrawing::DrawRectangle({ m_Pos.x - 1, m_Pos.y - 1,
			m_Image.GetWidth() + 2, m_Image.GetHeight() + 2}, Colors::SkyBlue );
		SDLDrawing::DrawRectangle({m_Pos.x - 2, m_Pos.y - 2,
			m_Image.GetWidth() + 4, m_Image.GetHeight() + 4}, Colors::SkyBlue);
	}
}

// =============================================================================
const std::string& TextBox::GetTextContent() const
{
	return m_TextInputter.GetTextContent();
}

// =============================================================================
void TextBox::SetPosition(const Point& newPos)
{
	UIComponentBase::SetPosition(newPos);

	m_TextInputter.SetPosition(Point(m_Pos.x + 4, m_Pos.y + (m_Image.GetHeight() - m_TextInputter.GetHeight()) / 2));
}

// =============================================================================
void TextBox::ToggleShouldHandleEnterKey(bool enterKey)
{
	m_TextInputter.ToggleShouldHandleEnterKey(enterKey);
}

// =============================================================================
void TextBox::Reset()
{
	m_TextInputter.Reset();
	m_IsActive = false;
}