#pragma once

//TODO think of a config database that will hold all the configs for the application

//TODO move to enums/defines file
enum class EUIComponentType
	: int8_t
{
	Invalid = -1
	, ImageBox
	, Label
	, Button
	, Checkbox
	, RadioButton
	, TextBox
	, Count
};

EUIComponentType GetUIComponentTypeFromString(const std::string& text);

struct IUIComponentConfig
{
	virtual ~IUIComponentConfig() = default;

	virtual EUIComponentType GetType() const = 0;
	virtual bool Parse(const std::string& line) = 0;
};

////////////////////////////////////////////////////////////////////////////////
struct ImageBoxConfig
	: IUIComponentConfig
{
	static constexpr EUIComponentType ComponentType = EUIComponentType::ImageBox;

	EUIComponentType GetType() const final { return ComponentType; };
	bool Parse(const std::string& line) final;

	Point				m_Pos = Point::Undefined;
	ImageId				m_ImageId = 0;
};

////////////////////////////////////////////////////////////////////////////////
struct LabelConfig
	: IUIComponentConfig
{
	static constexpr EUIComponentType ComponentType = EUIComponentType::Label;

	EUIComponentType GetType() const final { return ComponentType; };
	bool Parse(const std::string& line) final;

	Point				m_Pos = Point::Undefined;
	TextId				m_TextId = 0;
};

////////////////////////////////////////////////////////////////////////////////
struct ButtonConfig
	: IUIComponentConfig
{
	static constexpr EUIComponentType ComponentType = EUIComponentType::Button;

	EUIComponentType GetType() const final { return ComponentType; };
	bool Parse(const std::string& line) final;

	Point				m_Pos = Point::Undefined;
	ImageId				m_ImageId = 0;
	TextId				m_TextId = 0;
	SoundId				m_SoundId = 0;
};

////////////////////////////////////////////////////////////////////////////////
struct CheckboxConfig
	: IUIComponentConfig
{
	static constexpr EUIComponentType ComponentType = EUIComponentType::Checkbox;

	EUIComponentType GetType() const final { return ComponentType; };
	bool Parse(const std::string& line) final;

	Point				m_Pos = Point::Undefined;
	ImageId				m_ImageId = 0;
	TextId				m_TextId = 0;
	SoundId				m_SoundId = 0;
};

////////////////////////////////////////////////////////////////////////////////
struct RadioButtonConfig
	: IUIComponentConfig
{
	static constexpr EUIComponentType ComponentType = EUIComponentType::RadioButton;

	EUIComponentType GetType() const final { return ComponentType; };
	bool Parse(const std::string& line) final;

	Point				m_Pos = Point::Undefined;
	ImageId				m_ImageId = 0;
	TextId				m_TextId = 0;
	SoundId				m_SoundId = 0;
};

////////////////////////////////////////////////////////////////////////////////
struct TextBoxConfig
	: IUIComponentConfig
{
	static constexpr EUIComponentType ComponentType = EUIComponentType::TextBox;

	EUIComponentType GetType() const final { return ComponentType; };
	bool Parse(const std::string& line) final;

	Point				m_Pos = Point::Undefined;
	ImageId				m_ImageId = 0;
	int32_t				m_MaxChars = 0;
	FontId				m_FontId = 0;
	Color				m_TextColor = Colors::Black;
};

////////////////////////////////////////////////////////////////////////////////
struct UIComponentsConfig
{
	bool Read();

	template <typename T>
	bool ReadUIComponentsConfig(const std::string& filePath);

	template <typename T>
	const T* GetUIComponentConfig(size_t id) const;

	const IUIComponentConfig* GetUIComponentConfig(EUIComponentType type, size_t id) const;
	
private:
	std::unordered_map<EUIComponentType, std::vector<std::unique_ptr<IUIComponentConfig>>> m_Data;
};

////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool UIComponentsConfig::ReadUIComponentsConfig(const std::string& filePath)
{
	const auto buttonsCfg = File(filePath).GetLines();
	for (const auto& item : buttonsCfg)
	{
		auto newCfg = std::make_unique<T>();
		newCfg->Parse(item);
		m_Data[T::ComponentType].emplace_back(std::move(newCfg));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T* UIComponentsConfig::GetUIComponentConfig(size_t id) const
{
	const auto type = T::ComponentType;
	AssertReturnIf(!IsEnumValueValid(type), nullptr);

	auto cfgs = m_Data.find(type);
	AssertReturnIf(cfgs == m_Data.end(), nullptr);

	AssertReturnIf(id >= cfgs->second.size(), nullptr);

	return dynamic_cast<const T*>(cfgs->second[id].get());
}