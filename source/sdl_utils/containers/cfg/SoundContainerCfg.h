#ifndef DEFINES_SOUNDDEFINES_H_
#define DEFINES_SOUNDDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"

// Forward declarations

struct SoundCfg
{
	SoundCfg();
	SoundCfg(const char* fileName, SoundId id);

	~SoundCfg();

	const char*			m_FileName;
	SoundId				m_Id;
};

typedef std::vector<SoundCfg> SoundCfgsContainer;

class SoundContainerCfg
{
public:
	SoundContainerCfg();
	~SoundContainerCfg();

	bool				Read();
	SoundCfgsContainer	GetData() const;

private:
	SoundCfgsContainer	m_SoundsCfgData;
};

#endif // !DEFINES_SOUNDDEFINES_H_