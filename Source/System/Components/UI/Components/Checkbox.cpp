#include "stdafx.h"

#include "System/Components/UI/Components/Checkbox.h"
#include "System/Components/UI/Components/Config/CheckboxConfig.h"

const int32_t STANDARD_SPACING = 4;

////////////////////////////////////////////////////////////////////////////////
Checkbox::Checkbox()
{
}

////////////////////////////////////////////////////////////////////////////////
Checkbox::~Checkbox()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Checkbox::Init(const CheckboxConfig& cfg)
{
	UIComponentBase::Init({ cfg.m_Pos, cfg.m_ImageId });

	m_Text.Init(cfg.m_TextId);
	m_Sound.Init(cfg.m_SoundId);
	SetPosition(cfg.m_Pos);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::HandleEvent(const InputEvent& e)
{
	ReturnIf(!m_IsEnabled);

	if ((m_Image.ContainsPoint(e.m_Pos) || m_Text.ContainsPoint(e.m_Pos))
		&& e.m_Type == EEventType::MouseButtonDown && e.m_Mouse == EMouseKey::Left)
	{
		m_IsActive = !m_IsActive;
		m_Image.SetCurrFrame(m_IsActive + (int32_t)ECheckboxFrames::Normal);
		m_Sound.Play();
	}
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::Update(int32_t dt)
{
	ReturnIf(!m_IsEnabled);
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::Draw() const
{
	UIComponentBase::Draw();
	m_Text.Draw();
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::SetPosition(const Point& newPos)
{
	UIComponentBase::SetPosition(newPos);

	m_Text.SetPos(m_Pos.x + m_Image.GetWidth() + STANDARD_SPACING,
		m_Pos.y + (m_Image.GetHeight() - m_Text.GetHeight()) / 2);
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::Reset()
{
	m_IsActive = false;
	m_Image.SetCurrFrame((int32_t)ECheckboxFrames::Normal);
	SetPosition(m_Pos);
}

////////////////////////////////////////////////////////////////////////////////
void Checkbox::SetIsEnabled(bool enable)
{
	UIComponentBase::SetIsEnabled(enable);
	m_Text.SetIsVisible(enable);
}