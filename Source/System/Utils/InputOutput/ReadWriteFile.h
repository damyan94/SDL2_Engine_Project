#pragma once

namespace ReadWriteFile
{
bool ReadFromFile(const std::string& fileName, std::string& readString);
bool ReadFromFile(const std::string& fileName, std::vector<std::string>& readStrings);

bool WriteToFile(const std::string& fileName, const std::string& writeString, EWriteMode writeMode);
} // !ReadWriteFile