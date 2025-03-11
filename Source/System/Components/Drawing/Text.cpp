#include "stdafx.h"

#include "System/Components/Drawing/Text.h"

#include "System/Managers/AssetManager.h"
#include "System/Managers/DrawManager.h"

////////////////////////////////////////////////////////////////////////////////
Text::Text()
	: m_TextId(TextId(0))
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
	const auto& data = AssetManager::Instance().GetTextData(id);
	//ReturnIf(!data, false);

	m_DrawParameters.m_PosRect			= Rectangle::Zero;
	m_DrawParameters.m_FrameRect		= data.m_FrameRect;
	m_DrawParameters.m_PosRect.w		= m_DrawParameters.m_FrameRect.w;
	m_DrawParameters.m_PosRect.h		= m_DrawParameters.m_FrameRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::Text;
	m_TextId							= id;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Text::Deinit()
{
	SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void Text::Draw() const
{
	DrawManager::Instance().DrawTexture(*AssetManager::Instance().GetTextData(m_TextId).m_Texture, m_DrawParameters);
}