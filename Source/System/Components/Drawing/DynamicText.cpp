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
	
	m_DrawParameters.PosRect.x			= 0;
	m_DrawParameters.PosRect.y			= 0;
	m_DrawParameters.PosRect.w			= data.FrameRect.w;
	m_DrawParameters.PosRect.h			= data.FrameRect.h;
	m_DrawParameters.FrameRect.w		= m_DrawParameters.PosRect.w;
	m_DrawParameters.FrameRect.h		= m_DrawParameters.PosRect.h;
	m_DrawParameters.StandardWidth		= m_DrawParameters.PosRect.w;
	m_DrawParameters.StandardHeight		= m_DrawParameters.PosRect.h;
	
	m_DrawParameters.RotationCenter		= Point(m_DrawParameters.PosRect.w / 2,
												m_DrawParameters.PosRect.h / 2);

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

	m_DrawParameters.PosRect.w			= data.FrameRect.w;
	m_DrawParameters.PosRect.h			= data.FrameRect.h;
	m_DrawParameters.FrameRect.w		= m_DrawParameters.PosRect.w;
	m_DrawParameters.FrameRect.h		= m_DrawParameters.PosRect.h;
	m_DrawParameters.StandardWidth		= m_DrawParameters.PosRect.w;
	m_DrawParameters.StandardHeight		= m_DrawParameters.PosRect.h;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::SetColor(const Color& newColor)
{
	AssetManager::Instance().m_DynamicTextContainer.SetDynamicTextColor(m_DrawParameters.ResourceId, newColor);
	const auto& data = AssetManager::Instance().m_DynamicTextContainer.GetData(m_DrawParameters.ResourceId);

	m_DrawParameters.PosRect.w			= data.FrameRect.w;
	m_DrawParameters.PosRect.h			= data.FrameRect.h;
	m_DrawParameters.FrameRect.w		= m_DrawParameters.PosRect.w;
	m_DrawParameters.FrameRect.h		= m_DrawParameters.PosRect.h;
	m_DrawParameters.StandardWidth		= m_DrawParameters.PosRect.w;
	m_DrawParameters.StandardHeight		= m_DrawParameters.PosRect.h;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& DynamicText::GetText() const
{
	const auto& data = AssetManager::Instance().m_DynamicTextContainer.GetData(m_DrawParameters.ResourceId);
	return data.String;
}