#pragma once

struct DrawParameters
{
	DrawParameters();
	~DrawParameters();

	void				Reset();

	Point				Position;
	int32_t				Width;
	int32_t				Height;
	Rectangle			FrameRect;
	int32_t				StandardWidth;
	int32_t				StandardHeight;

	int32_t				Opacity;
	int32_t				RotationAngle;
	Point				RotationCenter;

	EObjectType			ObjectType;
	EBlendMode			BlendMode;
	EFlipMode			FlipMode;

	EDrawLayer			DrawLayer;

	bool				IsVisible;
	uint32_t			ResourceId;
};