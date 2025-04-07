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

	m_DrawParameters.Position		= Point::Zero;
	m_DrawParameters.FrameRect		= data.FrameRect;
	m_DrawParameters.Width			= m_DrawParameters.FrameRect.w;
	m_DrawParameters.Height			= m_DrawParameters.FrameRect.h;
	m_DrawParameters.StandardWidth	= m_DrawParameters.FrameRect.w;
	m_DrawParameters.StandardHeight	= m_DrawParameters.FrameRect.h;
	
	m_DrawParameters.RotationCenter	= Point(m_DrawParameters.Width / 2,
											m_DrawParameters.Height / 2);

	m_DrawParameters.ObjectType		= EObjectType::Text;
	m_DrawParameters.ResourceId		= id;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Text::Deinit()
{
	SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void Text::SetPlaceholders(const std::vector<std::string>& values)
{
	//TODO it seems that this situation presents a problem:
	// text textures are stored centrally in the TextContainer
	// for each textId, there is one texture
	// if we have placeholders, when we update, we change the textTexture,
	// but it could be used elsewhere, for example a text with "Score Player {1}",
	// where {1} is the placeholder and if we have 8 of these, they would all be the same.
	// I need to think to make these texts like the dynamic texts

	//Update: Actually, I should be using different textIds and the problem is solved

	const auto& data = AssetManager::Instance().m_TextContainer.GetData(m_DrawParameters.ResourceId);
	AssetManager::Instance().m_TextContainer.UpdateText(m_DrawParameters.ResourceId, data.FontId, data.TextColor, data.WrapWidth, values);

	m_DrawParameters.FrameRect		= data.FrameRect;
	m_DrawParameters.Width			= m_DrawParameters.FrameRect.w;
	m_DrawParameters.Height			= m_DrawParameters.FrameRect.h;
	m_DrawParameters.StandardWidth	= m_DrawParameters.FrameRect.w;
	m_DrawParameters.StandardHeight = m_DrawParameters.FrameRect.h;
	m_DrawParameters.RotationCenter	= Point(m_DrawParameters.Width / 2,
											m_DrawParameters.Height / 2);
}