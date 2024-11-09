#pragma once

class IniStruct
{
	struct Section
	{
		String m_Name;
		union Data //TODO Refactor and think of something better
		{
			int Int;
			double Double;
			std::string Str;
		};
		Data m_Data;

		Section* m_Parent;
		std::vector<Section> m_Children;
	};

public:
	IniStruct();
	~IniStruct();

	bool ReadFromFile(const std::string& fileName);

	template<typename T>
	bool Get(const String& nameToSearch, T& outValue);

private:

};

////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline bool IniStruct::Get(const String& nameToSearch, T& outValue)
{
	return true;
}