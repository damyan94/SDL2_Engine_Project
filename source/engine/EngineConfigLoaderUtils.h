#ifndef ENGINE_ENGINECONFIGLOADERUTILS_H_
#define ENGINE_ENGINECONFIGLOADERUTILS_H_

// C/C++ system includes
#include <cstdint>
#include <vector>
#include <string>

// Third-party includes

// Own includes

// Forward declarations

namespace Utils
{
int32_t						ReadInt(const std::string& source, const std::string& str);
std::vector<int32_t>		ReadIntArray(const std::string& source, const std::string& str, size_t size);

double						ReadDouble(const std::string& source, const std::string& str);
std::vector<double>			ReadDoubleArray(const std::string& source, const std::string& str, size_t size);

std::string					ReadString(const std::string& source, const std::string& str);
std::vector<std::string>	ReadStringArray(const std::string& source, const std::string& str, size_t size);
} // !Utils

#endif // !ENGINE_ENGINECONFIGLOADERUTILS_H_