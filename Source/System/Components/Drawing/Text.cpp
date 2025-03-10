#include "stdafx.h"

#include "System/Components/Drawing/Text.h"

#include "System/Managers/AssetManager.h"
#include "System/Managers/DrawManager.h"

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

	//TODO remove this complexity and bring back the Draw method and handle drawing explicitly
	//Will not be implementing the ECS idea - too complex and benefits questionable at this stage
	//Turns out SDL_RenderPresent takes the bulk of processor time, even for 50000 objects, which
	//is way too much more than would realistically be drawn or updated, the ECS does not show
	//any improvement (perhaps a skill issue on my side and I cannot create a good ECS, but still).
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