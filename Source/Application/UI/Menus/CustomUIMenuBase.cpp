#include "stdafx.h"

#include "Application/UI/Menus/CustomUIMenuBase.h"
#include "Application/UI/Menus/Config/MenuManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
CustomUIMenuBase::CustomUIMenuBase()
	: m_Id(EMenuId::Invalid)
{
}

////////////////////////////////////////////////////////////////////////////////
CustomUIMenuBase::~CustomUIMenuBase()
{
	for (auto uiComponent : m_UIComponents)
	{
		SafeDelete(uiComponent);
	}

	m_UIComponents.clear();
}

////////////////////////////////////////////////////////////////////////////////
bool CustomUIMenuBase::Init(const MenuConfig& cfg)
{
	m_PosRect = cfg.PosRect;

	//TODO maybe have some fancy factory that will construct and initialize the objects, instead of using a macro

#define ALLOCATE_AND_INIT(_Type)\
	m_UIComponents.emplace_back(new _Type);\
	ReturnIf(!static_cast<_Type*>(m_UIComponents.back())->Init(*static_cast<const _Type##Config*>(uiComponentCfg)), false)

	for (const auto& uiComponentCfg : cfg.ComponentsConfig)
	{
		const auto type = uiComponentCfg->GetType();

		//TODO implement these classes
		/*if (type == EUIComponentType::ImageBox) ALLOCATE_AND_INIT(ImageBox);
		else if (type == EUIComponentType::Label) ALLOCATE_AND_INIT(Label);
		else */if (type == EUIComponentType::Button) { ALLOCATE_AND_INIT(Button); }
		else if (type == EUIComponentType::Checkbox) { ALLOCATE_AND_INIT(Checkbox); }
		else if (type == EUIComponentType::RadioButton) { ALLOCATE_AND_INIT(RadioButton); }
		else if (type == EUIComponentType::TextBox) { ALLOCATE_AND_INIT(TextBox); }
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
EMenuId CustomUIMenuBase::GetId() const
{
	return m_Id;
}