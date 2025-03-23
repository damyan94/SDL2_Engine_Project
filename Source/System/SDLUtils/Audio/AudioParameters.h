#pragma once

struct AudioParameters
{
	AudioParameters();
	~AudioParameters();

	void				Reset();

	int32_t				Loops;
	bool				LoopInfinitely;

	uint8_t				Volume;
	uint8_t				MaxVolume;

	EObjectType			ObjectType;
	uint32_t			ResourceId;
};