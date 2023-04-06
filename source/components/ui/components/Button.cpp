// Corresponding header
#include "components/ui/components/Button.h"
#include "components/ui/components/config/ButtonConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/geometry/Position.h"
#include "sdl_utils/containers/text_container/TextData.h"

// =============================================================================
Button::Button()
{
}

// =============================================================================
Button::~Button()
{
	Deinit();
	UIComponentBase::~UIComponentBase();
}

// =============================================================================
bool Button::Init(const ButtonConfig& cfg)
{
	UIComponentBase::Init({ cfg.m_Pos, cfg.m_ImageId });

	m_Text.Init(cfg.m_TextId);
	m_Sound.Init(cfg.m_SoundId);
	SetPosition(cfg.m_Pos);

	return true;
}

// =============================================================================
void Button::Deinit()
{
	UIComponentBase::Deinit();
}

// =============================================================================
void Button::HandleEvent(const InputEvent& e)
{
	HandleMouseHoverEvent(e);

	if (m_Image.ContainsPoint(e.m_Pos) && e.m_Type == EEventType::MouseButtonDown && e.m_Mouse == EMouseKey::Left)
	{
		HandleMouseClickPressEvent(e);
	}
	else if (m_IsPressed && e.m_Type == EEventType::MouseButtonUp && e.m_Mouse == EMouseKey::Left)
	{
		HandleMouseClickReleaseEvent(e);
	}
}

// =============================================================================
void Button::Update(int32_t dt)
{
}

// =============================================================================
void Button::Draw() const
{
	UIComponentBase::Draw();
	m_Text.Draw();
}

// =============================================================================
void Button::SetPosition(const Point& newPos)
{
	UIComponentBase::SetPosition(newPos);

	const auto& textPos = Position::MiddleCenter(m_Text.GetData()->m_FrameRect, m_Image.GetPosRect());
	m_Text.SetPos(textPos);
}

// =============================================================================
void Button::Reset()
{
	UIComponentBase::Reset();
	m_Image.SetCurrFrame((int32_t)EButtonFrame::Normal);
	SetPosition(m_Pos);
}

// =============================================================================
void Button::HandleMouseHoverEvent(const InputEvent& e)
{
	if (m_Image.GetData()->m_FramesCount == 3)
	{
		if (m_Image.ContainsPoint(e.m_Pos) && !m_IsPressed)
		{
			m_Image.SetCurrFrame((int32_t)EButtonFrame::Selected);
		}
		else if (!m_Image.ContainsPoint(e.m_Pos) && !m_IsPressed)
		{
			m_Image.SetCurrFrame((int32_t)EButtonFrame::Normal);
		}
	}
}

// =============================================================================
void Button::HandleMouseClickPressEvent(const InputEvent& e)
{
	m_IsPressed = true;
	m_Image.SetCurrFrame((int32_t)EButtonFrame::Clicked);
	m_Text.MoveDown(1);
	m_Text.MoveRight(1);
	m_Sound.Play();
}

// =============================================================================
void Button::HandleMouseClickReleaseEvent(const InputEvent& e)
{
	Reset();
	if (m_Image.ContainsPoint(e.m_Pos))
	{
		m_WasClicked = true;

		if (m_Image.GetData()->m_FramesCount == 3)
		{
			m_Image.SetCurrFrame((int32_t)EButtonFrame::Selected);
		}
	}
}