#include "stdafx.h"

#include "system/sdl_utils/drawing/DrawParameters.h"

// =============================================================================
DrawParameters::DrawParameters()
	: m_PosRect(Rectangle::Undefined)
	, m_StandardWidth(0)
	, m_StandardHeight(0)
	, m_FrameRect(Rectangle::Zero)
	, m_Opacity(Constants::FullOpacity)
	, m_RotationAngle(Constants::ZeroRotation)
	, m_RotationCenter(Point::Undefined)
	, m_ObjectType(EObjectType::Invalid)
	, m_BlendMode(EBlendMode::Blend)
	, m_FlipMode(EFlipMode::None)
	, m_DrawLayer(EDrawLayer::Invalid)
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
	//TODO use this hack everywhere
	*this = DrawParameters();

	/*m_PosRect				= Rectangle::Undefined;
	m_FrameRect				= Rectangle::Zero;
	m_StandardWidth			= 0;
	m_StandardHeight		= 0;

	m_Opacity				= Constants::FullOpacity;
	m_RotationAngle			= Constants::ZeroRotation;
	m_RotationCenter		= Point::Undefined;

	m_ObjectType			= EObjectType::Invalid;
	m_BlendMode				= EBlendMode::Blend;
	m_FlipMode				= EFlipMode::None;

	m_IsVisible				= true;*/
}