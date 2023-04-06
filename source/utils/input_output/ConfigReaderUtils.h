#ifndef UTILS_INPUT_OUTPUT_CONFIGREADERUTILS_H_
#define UTILS_INPUT_OUTPUT_CONFIGREADERUTILS_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "utils/string/String.h"

// Forward declarations

namespace Utils
{
int32_t						ReadInt(const std::string& source, const std::string& str);
std::vector<int32_t>		ReadIntArray(const std::string& source, const std::string& str, size_t size);

double						ReadDouble(const std::string& source, const std::string& str);
std::vector<double>			ReadDoubleArray(const std::string& source, const std::string& str, size_t size);

std::string					ReadString(const std::string& source, const std::string& str);
std::vector<std::string>	ReadStringArray(const std::string& source, const std::string& str, size_t size);

String						ReadStringHashed(const std::string& source, const std::string& str);
std::vector<String>			ReadStringArrayHashed(const std::string& source, const std::string& str, size_t size);
} // !Utils

#endif // !UTILS_INPUT_OUTPUT_CONFIGREADERUTILS_H_