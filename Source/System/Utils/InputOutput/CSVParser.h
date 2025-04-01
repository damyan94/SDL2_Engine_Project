#pragma once

class CSVParser
{
public:
	CSVParser(const std::string& fileName, EWriteMode writeMode = EWriteMode::App);
	~CSVParser();

private:
	File m_File;
	bool m_HasHeader;
};