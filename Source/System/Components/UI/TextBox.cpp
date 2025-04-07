#include "stdafx.h"

#include "System/Components/UI/TextBox.h"
#include "System/Components/UI/Config/UIComponentsConfig.h"

#include "System/SDLUtils/Drawing/SDLDrawing.h"

////////////////////////////////////////////////////////////////////////////////
TextBox::TextBox()
	: m_MaxChars(0)
{
}

////////////////////////////////////////////////////////////////////////////////
TextBox::~TextBox()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool TextBox::Init(const TextBoxConfig& cfg)
{
	m_Image.Init(cfg.m_ImageId);

	TextInputterConfig tiCfg{ cfg.m_Pos, cfg.m_MaxChars, "", cfg.m_FontId, cfg.m_TextColor };
	m_TextInputter.Init(tiCfg);
	SetPosition(cfg.m_Pos);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::HandleEvent(const InputEvent& e)
{
	ReturnIf(!m_IsEnabled);

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

////////////////////////////////////////////////////////////////////////////////
void TextBox::Update(int32_t dt)
{
	ReturnIf(!m_IsEnabled);

	m_TextInputter.Update(dt);
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::Draw() const
{
	UIComponentBase::Draw();
}

////////////////////////////////////////////////////////////////////////////////
const std::string& TextBox::GetTextContent() const
{
	return m_TextInputter.GetTextContent();
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::SetPosition(const Point& newPos)
{
	UIComponentBase::SetPosition(newPos);

	m_TextInputter.SetPosition(Point(m_Pos.x + 4, m_Pos.y +
		(m_Image.GetHeight() - m_TextInputter.GetHeight()) / 2));
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::ToggleShouldHandleEnterKey(bool enterKey)
{
	m_TextInputter.ToggleShouldHandleEnterKey(enterKey);
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::Reset()
{
	m_TextInputter.Reset();
	m_IsActive = false;
}

////////////////////////////////////////////////////////////////////////////////
void TextBox::SetIsEnabled(bool enable)
{
	UIComponentBase::SetIsEnabled(enable);
	if (enable)
	{
		m_TextInputter.Show();
	}
	else
	{
		m_TextInputter.Hide();
	}
}