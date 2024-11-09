#pragma once

#include <string>

namespace ConfigFilePaths
{
#if defined _DEBUG || _RELEASE
static const std::string MainDir = "../../../";
#elif defined _DISTRIBUTION
static const std::string MainDir = "";
#endif // !_DEBUG || _RELEASE

static const std::string SystemConfig			= MainDir + "Config/System.cfg";
static const std::string AssetsConfig			= MainDir + "Config/Config.cfg";
static const std::string ObjectsConfig			= MainDir + "Config/Config.cfg";
} // !ConfigFilePaths
