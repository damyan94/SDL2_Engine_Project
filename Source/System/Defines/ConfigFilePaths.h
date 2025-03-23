#pragma once

namespace ConfigFilePaths
{
inline std::string ConfigFilePath(const std::string& path)
{
#if defined _DISTRIBUTION
	return path;
#elif defined _DEBUG || _RELEASE
	return "../../../" + path;
#endif // !_DEBUG || _RELEASE
}

static const std::string SystemConfig	= ConfigFilePath("Config/System.cfg");
static const std::string AssetsConfig	= ConfigFilePath("Config/Config.cfg");
static const std::string ObjectsConfig	= ConfigFilePath("Config/Config.cfg");
} // !ConfigFilePaths