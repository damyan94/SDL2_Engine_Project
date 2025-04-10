#pragma once

class CSVParser
{
public:
	CSVParser(const std::string& fileName);
	~CSVParser();

private:
	File m_File;
	bool m_HasHeader;
};