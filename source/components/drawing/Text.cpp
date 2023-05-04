// Corresponding header
#include "components/drawing/Text.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/AssetManager.h"
#include "managers/DrawManager.h"

// =============================================================================
Text::Text()
	: m_Id(0)
	, m_Data(nullptr)
{
}

// =============================================================================
Text::~Text()
{
	Deinit();
}

// =============================================================================
bool Text::Init(TextId id)
{
	m_Data = g_AssetManager->GetTextData(id);
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

	m_Id								= id;

	g_DrawManager->AddText(this);

	return true;
}

// =============================================================================
void Text::Deinit()
{
	DrawObject::Reset();
	g_DrawManager->RemoveText(this);
	m_Data = nullptr;
}

// =============================================================================
const TextData* Text::GetData() const
{
	return m_Data;
}