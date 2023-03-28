#ifndef UTILS_DRAWING_DRAWPARAMETERS_H_
#define UTILS_DRAWING_DRAWPARAMETERS_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"

// Forward declarations

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

	bool				m_IsVisible;
};

#endif // !UTILS_DRAWING_DRAWPARAMETERS_H_