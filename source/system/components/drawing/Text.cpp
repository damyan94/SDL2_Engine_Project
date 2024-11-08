#include "stdafx.h"

#include "system/components/drawing/Text.h"

#include "system/managers/AssetManager.h"
#include "system/managers/DrawManager.h"

////////////////////////////////////////////////////////////////////////////////
Text::Text()
	: m_Data(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
Text::~Text()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Text::Init(TextId id)
{
	m_Data = AssetManager::Instance().GetTextData(id);
	ReturnIf(!m_Data, false);

	m_DrawParameters.m_PosRect			= Rectangle::Zero;
	m_DrawParameters.m_FrameRect		= m_Data->m_FrameRect;
	m_DrawParameters.m_PosRect.w		= m_DrawParameters.m_FrameRect.w;
	m_DrawParameters.m_PosRect.h		= m_DrawParameters.m_FrameRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::Text;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;

	DrawManager::Instance().AddText(this);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Text::Deinit()
{
	SetIsVisible(false);

	m_Data = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
const TextData* Text::GetData() const
{
	return m_Data;
}