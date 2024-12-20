#pragma once

struct DrawParameters
{
	DrawParameters();
	~DrawParameters();

	void				Reset();

	Rectangle			m_PosRect;
	Rectangle			m_FrameRect;
	int32_t				m_StandardWidth;
	int32_t				m_StandardHeight;

	int32_t				m_Opacity;
	int32_t				m_RotationAngle;
	Point				m_RotationCenter;

	EObjectType			m_ObjectType;
	EBlendMode			m_BlendMode;
	EFlipMode			m_FlipMode;

	EDrawLayer			m_DrawLayer;

	bool				m_IsVisible;
};