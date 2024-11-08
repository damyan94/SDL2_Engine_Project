#include "stdafx.h"

#include "application/ui/menus/MenuManager.h"
#include "application/ui/menus/config/MenuManagerConfig.h"

#include "application/ui/menus/console_menu/ConsoleMenu.h"
#include "application/ui/menus/start_menu/StartMenu.h"

////////////////////////////////////////////////////////////////////////////////
MenuManager::MenuManager()
	: m_FocusedMenu(EMenuId::Invalid)
{
}

////////////////////////////////////////////////////////////////////////////////
MenuManager::~MenuManager()
{
	Deinit();
	for (auto menu : m_Menus)
	{
		SafeDelete(menu);
	}
}

////////////////////////////////////////////////////////////////////////////////
bool MenuManager::Init(const MenuManagerConfig& cfg)
{
	m_Menus.resize((size_t)EMenuId::Count);

#define ALLOCATE_AND_INIT(_Id, _Type)\
m_Menus[(int32_t)_Id] = new _Type;\
ReturnIf(!static_cast<_Type*>(m_Menus[(int32_t)_Id])->Init(cfg.m_##_Type##Config), false)

	ALLOCATE_AND_INIT(EMenuId::ConsoleMenu, ConsoleMenu);
	ALLOCATE_AND_INIT(EMenuId::StartMenu, StartMenu);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::Deinit()
{
	m_ActiveMenus.clear();
	m_FocusedMenusHistory.clear();
	m_FocusedMenu = EMenuId::Invalid;
	for (auto menu : m_Menus)
	{
		menu->Deinit();
	}
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::HandleEvent(const InputEvent& e)
{
	m_Menus[size_t(m_FocusedMenu)]->HandleEvent(e);
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::Update(int32_t dt)
{
	for (auto id : m_ActiveMenus)
	{
		m_Menus[size_t(id)]->Update(dt);
	}
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::ActivateMenu(EMenuId id)
{
	AssertReturnIf(!IsEnumValueValid(id));
	auto& menu = m_Menus[size_t(id)];

	ReturnIf(menu->GetIsActive());

	m_ActiveMenus.emplace_back(id);
	menu->Activate();
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::DeactivateMenu(EMenuId id)
{
	AssertReturnIf(!IsEnumValueValid(id));
	auto& menu = m_Menus[size_t(id)];

	ReturnIf(!menu->GetIsActive());

	if (!m_ActiveMenus.empty())
	{
		m_ActiveMenus.pop_back();
	}
	menu->Deactivate();
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::DeactivateAllMenus()
{
	for (auto id : m_ActiveMenus)
	{
		DeactivateMenu(id);
	}
}

////////////////////////////////////////////////////////////////////////////////
bool MenuManager::IsMenuActive(EMenuId id) const
{
	AssertReturnIf(!IsEnumValueValid(id), false);
	return std::find(m_ActiveMenus.begin(), m_ActiveMenus.end(), id) != m_ActiveMenus.end();
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::FocusMenu(EMenuId id)
{
	AssertReturnIf(!IsEnumValueValid(id));
	m_FocusedMenu = id;
	m_FocusedMenusHistory.emplace_back(id);

	if (!IsMenuActive(id))
	{
		ActivateMenu(id);
	}
}

////////////////////////////////////////////////////////////////////////////////
void MenuManager::UnfocusMenu(EMenuId id)
{
	AssertReturnIf(!IsEnumValueValid(id));
	ReturnIf(!IsMenuFocused(id));

	if (!m_FocusedMenusHistory.empty())
	{
		m_FocusedMenu = m_FocusedMenusHistory.back();
		m_FocusedMenusHistory.pop_back();
	}

	if (!IsMenuActive(id))
	{
		ActivateMenu(id);
	}
}

////////////////////////////////////////////////////////////////////////////////
bool MenuManager::IsMenuFocused(EMenuId id) const
{
	return m_FocusedMenu == id;
}

////////////////////////////////////////////////////////////////////////////////
EMenuId MenuManager::GetFocusedMenuId() const
{
	return m_FocusedMenu;
}