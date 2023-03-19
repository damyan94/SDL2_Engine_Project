// Corresponding header
#include "utils/drawing/DrawParameters.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
DrawParameters::DrawParameters()
	: m_Pos(Point::Undefined)
	, m_Width(0)
	, m_Height(0)
	, m_StandardWidth(0)
	, m_StandardHeight(0)
	, m_FrameRect(Rectangle::Zero)
	, m_Opacity(Constants::FullOpacity)
	, m_RotationAngle(Constants::ZeroRotation)
	, m_RotationCenter(Point::Undefined)
	, m_ObjectType(EObjectType::Invalid)
	, m_BlendMode(EBlendMode::Blend)
	, m_FlipMode(EFlipMode::None)
	, m_IsVisible(true)
{
}

// =============================================================================
DrawParameters::~DrawParameters()
{
}

// =============================================================================
void DrawParameters::Reset()
{
	m_Pos					= Point::Undefined;
	m_FrameRect				= Rectangle::Zero;
	m_Width					= 0;
	m_Height				= 0;
	m_StandardWidth			= 0;
	m_StandardHeight		= 0;

	m_Opacity				= Constants::FullOpacity;
	m_RotationAngle			= Constants::ZeroRotation;
	m_RotationCenter		= Point::Undefined;

	m_ObjectType			= EObjectType::Invalid;
	m_BlendMode				= EBlendMode::Blend;
	m_FlipMode				= EFlipMode::None;

	m_IsVisible				= true;
}