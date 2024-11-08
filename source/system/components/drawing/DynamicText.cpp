#include "stdafx.h"

#include "system/components/drawing/DynamicText.h"

//TODO major refactoring needed
#include "system/sdl_utils/drawing/Texture.h"

#include "system/managers/AssetManager.h"
#include "system/managers/DrawManager.h"

////////////////////////////////////////////////////////////////////////////////
DynamicText::DynamicText()
	: m_String()
	, m_Data(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
DynamicText::~DynamicText()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool DynamicText::Init(const std::string& string, FontId id,
	const Color& textColor, int32_t wrapWidth)
{
	m_Data = new TextData;
	m_Data->m_Texture = new Texture;

	TextTextureParameters inOutParams{
		string.empty() ? " " : string,
		AssetManager::Instance().GetFontData(id)->m_Font,
		textColor,
		wrapWidth,
		0,
		0
	};
	m_Data->m_Texture->CreateTextureFromText(inOutParams);
	ReturnIf(!m_Data->m_Texture->Get(), false);
	
	m_DrawParameters.m_PosRect.x		= 0;
	m_DrawParameters.m_PosRect.y		= 0;
	m_DrawParameters.m_PosRect.w		= inOutParams.m_Width;
	m_DrawParameters.m_PosRect.h		= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_PosRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::DynamicText;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;
	
	m_String							= string;
	m_Data->m_FontId					= id;
	m_Data->m_TextColor					= textColor;
	m_Data->m_WrapWidth					= wrapWidth;

	DrawManager::Instance().AddDynamicText(this);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::Deinit()
{
	SetIsVisible(false);

	if (m_Data && m_Data->m_Texture)
	{
		m_Data->m_Texture->DestroyTexture();
	}
	DrawManager::Instance().RequestRemoveDynamicText(this);
	SafeDelete(m_Data);
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::SetText(const std::string& newText)
{
	m_Data->m_Texture->DestroyTexture();

	TextTextureParameters inOutParams{
		newText.empty() ? " " : newText,
		AssetManager::Instance().GetFontData(m_Data->m_FontId)->m_Font,
		m_Data->m_TextColor,
		m_Data->m_WrapWidth,
		0,
		0
	};
	m_Data->m_Texture->CreateTextureFromText(inOutParams);
	ReturnIf(!m_Data->m_Texture->Get());

	m_DrawParameters.m_PosRect.w		= inOutParams.m_Width;
	m_DrawParameters.m_PosRect.h		= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_PosRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	m_String							= newText;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicText::SetColor(const Color& newColor)
{
	m_Data->m_Texture->DestroyTexture();

	TextTextureParameters inOutParams{
		m_String,
		AssetManager::Instance().GetFontData(m_Data->m_FontId)->m_Font,
		newColor,
		m_Data->m_WrapWidth,
		0,
		0
	};
	m_Data->m_Texture->CreateTextureFromText(inOutParams);
	ReturnIf(!m_Data->m_Texture->Get());
	
	m_DrawParameters.m_PosRect.w		= inOutParams.m_Width;
	m_DrawParameters.m_PosRect.h		= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_PosRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	m_Data->m_TextColor					= newColor;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& DynamicText::GetText() const
{
	return m_String;
}

////////////////////////////////////////////////////////////////////////////////
TextData* DynamicText::GetData() const
{
	return m_Data;
}