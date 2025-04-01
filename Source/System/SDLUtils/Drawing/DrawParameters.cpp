#include "stdafx.h"

#include "System/SDLUtils/Drawing/DrawParameters.h"

////////////////////////////////////////////////////////////////////////////////
DrawParameters::DrawParameters()
	: Position(Point::Undefined)
	, Width(0)
	, Height(0)
	, StandardWidth(0)
	, StandardHeight(0)
	, FrameRect(Rectangle::Zero)
	, Opacity(Constants::FullOpacity)
	, RotationAngle(Constants::ZeroRotation)
	, RotationCenter(Point::Undefined)
	, ObjectType(EObjectType::Invalid)
	, BlendMode(EBlendMode::Blend)
	, FlipMode(EFlipMode::None)
	, DrawLayer(EDrawLayer::Invalid)
	, IsVisible(true)
	, ResourceId(-1)
{
}

////////////////////////////////////////////////////////////////////////////////
DrawParameters::~DrawParameters()
{
}

////////////////////////////////////////////////////////////////////////////////
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

	m_IsVisible				= true;
	m_ResourceId			= -1;*/
}