#ifndef DEFINES_CONFIGFILEPATHS_H_
#define DEFINES_CONFIGFILEPATHS_H_

#include <string>

namespace ConfigFilePaths
{
#if defined _DEBUG || _RELEASE
static const std::string MainDir = "../../../";
#elif defined _DISTRIBUTION
static const std::string MainDir = "";
#endif // !_DEBUG || _RELEASE

static const std::string SystemConfig			= MainDir + "config/system.cfg";
static const std::string AssetsConfig			= MainDir + "config/config.cfg";
static const std::string ObjectsConfig			= MainDir + "config/config.cfg";
} // !ConfigFilePaths

#endif // !DEFINES_CONFIGFILEPATHS_H_