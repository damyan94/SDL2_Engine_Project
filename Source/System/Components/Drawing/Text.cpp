#include "stdafx.h"

#include "System/Components/Drawing/Text.h"

#include "System/Managers/AssetManager.h"

////////////////////////////////////////////////////////////////////////////////
Text::Text()
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
	const auto& data = AssetManager::Instance().m_TextContainer.GetData(id);
	//ReturnIf(!data, false);

	m_DrawParameters.PosRect		= Rectangle::Zero;
	m_DrawParameters.FrameRect		= data.FrameRect;
	m_DrawParameters.PosRect.w		= m_DrawParameters.FrameRect.w;
	m_DrawParameters.PosRect.h		= m_DrawParameters.FrameRect.h;
	m_DrawParameters.StandardWidth	= m_DrawParameters.PosRect.w;
	m_DrawParameters.StandardHeight	= m_DrawParameters.PosRect.h;
	
	m_DrawParameters.RotationCenter	= Point(m_DrawParameters.PosRect.w / 2,
											m_DrawParameters.PosRect.h / 2);

	m_DrawParameters.ObjectType		= EObjectType::Text;
	m_DrawParameters.ResourceId		= id;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Text::Deinit()
{
	SetIsVisible(false);
}