#ifndef UTILS_INPUT_OUTPUT_READWRITEFILE_H_
#define UTILS_INPUT_OUTPUT_READWRITEFILE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

// Forward declarations

namespace ReadWriteFile
{
	bool ReadFromFile(const std::string& fileName, std::vector<std::string>& readStrings);
	bool ReadFromFile(const std::string& fileName, std::vector<std::wstring>& readStrings);

	bool WriteToFile(const std::string& fileName, const std::string& writeString, EWriteMode writeMode);
	bool WriteToFile(const std::string& fileName, const std::wstring& writeString, EWriteMode writeMode);
} // !ReadWriteFile

#endif //!UTILS_INPUT_OUTPUT_READWRITEFILE_H_