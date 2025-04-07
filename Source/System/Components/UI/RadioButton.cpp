#include "stdafx.h"

#include "System/Components/UI/RadioButton.h"
#include "System/Components/UI/Config/UIComponentsConfig.h"

const int32_t STANDARD_SPACING = 4;

////////////////////////////////////////////////////////////////////////////////
RadioButton::RadioButton()
{
}

////////////////////////////////////////////////////////////////////////////////
RadioButton::~RadioButton()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool RadioButton::Init(const RadioButtonConfig& cfg)
{
	UIComponentBase::Init({ cfg.m_Pos, cfg.m_ImageId });

	m_Text.Init(cfg.m_TextId);
	m_Sound.Init(cfg.m_SoundId);
	SetPosition(cfg.m_Pos);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::HandleEvent(const InputEvent& e)
{
	ReturnIf(!m_IsEnabled);

	if ((m_Image.ContainsPoint(e.m_Pos) || m_Text.ContainsPoint(e.m_Pos))
		&& e.m_Type == EEventType::MouseButtonDown && e.m_Mouse == EMouseKey::Left)
	{
		m_WasClicked = true;
		m_IsActive = !m_IsActive;
		m_Image.SetCurrFrame(m_IsActive + (int32_t)ERadioButtonFrames::Normal);
		m_Sound.Play();
	}
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::Update(int32_t dt)
{
	ReturnIf(!m_IsEnabled);

	m_WasClicked = false;
	m_Image.SetCurrFrame(m_IsActive + (int32_t)ERadioButtonFrames::Normal);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::Draw() const
{
	UIComponentBase::Draw();
	m_Text.Draw();
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::SetPosition(const Point& newPos)
{
	UIComponentBase::SetPosition(newPos);

	m_Text.SetPos(m_Pos.x + m_Image.GetWidth() + STANDARD_SPACING,
		m_Pos.y + (m_Image.GetHeight() - m_Text.GetHeight()) / 2);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::Reset()
{
	m_WasClicked = false;
	m_IsActive = false;
	m_Image.SetCurrFrame((int32_t)ERadioButtonFrames::Normal);
	SetPosition(m_Pos);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::SetIsEnabled(bool enable)
{
	UIComponentBase::SetIsEnabled(enable);
	m_Text.SetIsVisible(enable);
}