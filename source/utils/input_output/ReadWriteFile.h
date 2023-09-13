#ifndef UTILS_INPUT_OUTPUT_READWRITEFILE_H_
#define UTILS_INPUT_OUTPUT_READWRITEFILE_H_

namespace ReadWriteFile
{
bool ReadFromFile(const std::string& fileName, std::string& readString);
bool ReadFromFile(const std::string& fileName, std::vector<std::string>& readStrings);

bool WriteToFile(const std::string& fileName, const std::string& writeString, EWriteMode writeMode);
} // !ReadWriteFile

#endif //!UTILS_INPUT_OUTPUT_READWRITEFILE_H_