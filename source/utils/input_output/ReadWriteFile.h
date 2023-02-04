#ifndef UTILS_INPUT_OUTPUT_READWRITEFILE_H_
#define UTILS_INPUT_OUTPUT_READWRITEFILE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

// Forward declarations

namespace ReadWriteFile
{
	int32_t ReadFromFile(const std::string& fileName, std::vector<std::string>& readStrings);
	int32_t ReadFromFile(const std::string& fileName, std::vector<std::wstring>& readStrings);

	int32_t WriteToFile(const std::string& fileName, const std::string& writeString, WriteMode writeMode);
	int32_t WriteToFile(const std::string& fileName, const std::wstring& writeString, WriteMode writeMode);
} // !ReadWriteFile

#endif //!UTILS_INPUT_OUTPUT_READWRITEFILE_H_