#include "stdafx.h"

#include "System/Components/UI/Components/Config/UIComponentsConfig.h"
#include "System/Defines/ConfigFilePaths.h"

EUIComponentType GetUIComponentTypeFromString(const std::string& text)
{
	if (text == "Label") return EUIComponentType::Label;
	else if (text == "ImageBox") return EUIComponentType::ImageBox;
	else if (text == "Button") return EUIComponentType::Button;
	else if (text == "Checkbox") return EUIComponentType::Checkbox;
	else if (text == "RadioButton") return EUIComponentType::RadioButton;
	else if (text == "TextBox") return EUIComponentType::TextBox;

	AssertReturnIf(true, EUIComponentType::Invalid);
}

////////////////////////////////////////////////////////////////////////////////
bool ImageBoxConfig::Parse(const std::string& line)
{
	const auto& pos = Utils::ReadIntArray(line, "Position", 2);
	//AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
	m_Pos = Point(pos[0], pos[1]);

	m_ImageId = Utils::ReadInt(line, "ImageId");

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool LabelConfig::Parse(const std::string& line)
{
	const auto& pos = Utils::ReadIntArray(line, "Position", 2);
	//AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
	m_Pos = Point(pos[0], pos[1]);

	m_TextId = Utils::ReadInt(line, "TextId");

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool ButtonConfig::Parse(const std::string& line)
{
	const auto& pos = Utils::ReadIntArray(line, "Position", 2);
	//AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
	m_Pos = Point(pos[0], pos[1]);

	m_ImageId = Utils::ReadInt(line, "ImageId");
	m_TextId = Utils::ReadInt(line, "TextId");
	m_SoundId = Utils::ReadInt(line, "SoundId");

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool CheckboxConfig::Parse(const std::string& line)
{
	const auto& pos = Utils::ReadIntArray(line, "Position", 2);
	//AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
	m_Pos = Point(pos[0], pos[1]);

	m_ImageId = Utils::ReadInt(line, "ImageId");
	m_TextId = Utils::ReadInt(line, "TextId");

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool RadioButtonConfig::Parse(const std::string& line)
{
	const auto& pos = Utils::ReadIntArray(line, "Position", 2);
	//AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
	m_Pos = Point(pos[0], pos[1]);

	m_ImageId = Utils::ReadInt(line, "ImageId");
	m_TextId = Utils::ReadInt(line, "TextId");
	m_SoundId = Utils::ReadInt(line, "SoundId");

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool TextBoxConfig::Parse(const std::string& line)
{
	const auto& pos = Utils::ReadIntArray(line, "Position", 2);
	//AssertReturnIf(pos.size() != 2 && _CONFIG_ERROR_INFO(i), false);
	m_Pos = Point(pos[0], pos[1]);

	m_ImageId = Utils::ReadInt(line, "ImageId");

	m_MaxChars = Utils::ReadInt(line, "MaximumChars");
	//AssertReturnIf(m_MaxChars <= 0 && _CONFIG_ERROR_INFO(i), false);

	m_FontId = FontId(Utils::ReadInt(line, "FontId"));

	const auto& color = Utils::ReadIntArray(line, "TextColor", 4);
	//AssertReturnIf(color.size() != 4 && _CONFIG_ERROR_INFO(i), false);
	m_TextColor = Color(color[0], color[1], color[2], color[3]);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool UIComponentsConfig::Read()
{
	ReadUIComponentsConfig<ImageBoxConfig>(ConfigFilePaths::ImageBoxConfig);
	ReadUIComponentsConfig<LabelConfig>(ConfigFilePaths::LabelConfig);
	ReadUIComponentsConfig<ButtonConfig>(ConfigFilePaths::ButtonConfig);
	ReadUIComponentsConfig<CheckboxConfig>(ConfigFilePaths::CheckboxConfig);
	ReadUIComponentsConfig<RadioButtonConfig>(ConfigFilePaths::RadioButtonConfig);
	ReadUIComponentsConfig<TextBoxConfig>(ConfigFilePaths::TextBoxConfig);

	return true;
}

const IUIComponentConfig* UIComponentsConfig::GetUIComponentConfig(EUIComponentType type, size_t id) const
{
	AssertReturnIf(!IsEnumValueValid(type), nullptr);

	auto cfgs = m_Data.find(type);
	AssertReturnIf(cfgs == m_Data.end(), nullptr);

	AssertReturnIf(id >= cfgs->second.size(), nullptr);

	return cfgs->second[id].get();
}