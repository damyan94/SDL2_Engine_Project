#pragma once

#include "System/Components/Audio/AudioObject.h"

class Music
	: public AudioObject
{
public:
	Music();
	~Music();

	bool				Init(MusicId id);
	void				Deinit();

private:
};