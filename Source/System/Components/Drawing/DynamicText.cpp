#include "stdafx.h"

#include "System/Components/Drawing/DynamicText.h"

#include "System/Managers/AssetManager.h"

////////////////////////////////////////////////////////////////////////////////
DynamicText::DynamicText()
{
}

////////////////////////////////////////////////////////////////////////////////
DynamicText::~DynamicText()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool DynamicText::Init(const std::string& text, FontId fontId, const Color& textColor, int32_t wrapWidth)
{
	m_DrawParameters.ResourceId = AssetManager::Instance().m_DynamicTextContainer.CreateDynamicText(text, fontId, textColor, wrapWidth);
	const auto& data = AssetManager::Instance().m_DynamicTextContainer.GetData(m_DrawParameters.ResourceId);
	
	m_DrawParameters.Position.x			= 0;
	m_DrawParameters.Position.y			= 0;
	m_DrawParameters.Width				= data.FrameRect.w;
	m_DrawParameters.Height				= data.FrameRect.h;
	m_DrawParameters.FrameRect.w		= data.FrameRect.w;
	m_DrawParameters.FrameRect.h		= data.FrameRect.h;
	m_DrawParameters.StandardWidth		= data.FrameRect.w;
	m_DrawParameters.StandardHeight		= data.FrameRect.h;
	
	m_DrawParameters.RotationCenter		= Point(m_DrawParameters.Width / 2,
												m_DrawParameters.Height / 2);

	m_DrawParameters.ObjectType			= EObjectType::DynamicText;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::Deinit()
{
	SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::SetText(const std::string& newText)
{
	AssetManager::Instance().m_DynamicTextContainer.SetDynamicText(m_DrawParameters.ResourceId, newText);
	const auto& data = AssetManager::Instance().m_DynamicTextContainer.GetData(m_DrawParameters.ResourceId);

	m_DrawParameters.Width				= data.FrameRect.w;
	m_DrawParameters.Height				= data.FrameRect.h;
	m_DrawParameters.FrameRect.w		= data.FrameRect.w;
	m_DrawParameters.FrameRect.h		= data.FrameRect.h;
	m_DrawParameters.StandardWidth		= data.FrameRect.w;
	m_DrawParameters.StandardHeight		= data.FrameRect.h;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::SetColor(const Color& newColor)
{
	AssetManager::Instance().m_DynamicTextContainer.SetDynamicTextColor(m_DrawParameters.ResourceId, newColor);
	const auto& data = AssetManager::Instance().m_DynamicTextContainer.GetData(m_DrawParameters.ResourceId);

	m_DrawParameters.Width				= data.FrameRect.w;
	m_DrawParameters.Height				= data.FrameRect.h;
	m_DrawParameters.FrameRect.w		= data.FrameRect.w;
	m_DrawParameters.FrameRect.h		= data.FrameRect.h;
	m_DrawParameters.StandardWidth		= data.FrameRect.w;
	m_DrawParameters.StandardHeight		= data.FrameRect.h;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& DynamicText::GetText() const
{
	const auto& data = AssetManager::Instance().m_DynamicTextContainer.GetData(m_DrawParameters.ResourceId);
	return data.String;
}