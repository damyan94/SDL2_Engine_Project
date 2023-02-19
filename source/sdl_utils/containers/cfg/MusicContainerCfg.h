#ifndef DEFINES_MUSICDEFINES_H_
#define DEFINES_MUSICDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"

// Forward declarations

struct MusicCfg
{
	MusicCfg();
	~MusicCfg();

	MusicCfg(const char* fileName, MusicId id);

	const char*			m_FileName;
	MusicId				m_Id;
};

typedef std::vector<MusicCfg> MusicCfgsContainer;

class MusicContainerCfg
{
public:
	MusicContainerCfg();
	~MusicContainerCfg();

	bool				Read();
	MusicCfgsContainer	GetData() const;

private:
	MusicCfgsContainer	m_MusicsCfgData;
};

#endif // !DEFINES_MUSICDEFINES_H_