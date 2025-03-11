#pragma once

#include "System/Components/UI/BaseClasses/UIMenuBase.h"

struct MenuManagerConfig;

class MenuManager
{
public:
	MenuManager();
	~MenuManager();

	MenuManager(const MenuManager& other) = delete;
	MenuManager(MenuManager&& other) = delete;

	MenuManager& operator=(const MenuManager& other) = delete;
	MenuManager& operator=(MenuManager&& other) = delete;

	bool				Init(const MenuManagerConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	void				ActivateMenu(EMenuId id);
	void				DeactivateMenu(EMenuId id);
	void				DeactivateAllMenus();
	bool				IsMenuActive(EMenuId id) const;

	//TODO have something like a stack
	void				FocusMenu(EMenuId id);
	void				UnfocusMenu(EMenuId id);
	bool				IsMenuFocused(EMenuId id) const;
	EMenuId				GetFocusedMenuId() const;

private:
	EMenuId				m_FocusedMenu;

	std::deque<EMenuId>	m_ActiveMenus;
	std::deque<EMenuId>	m_FocusedMenusHistory;

	//TODO maybe use unordered_map
	std::vector<UIMenuBase*> m_Menus;
};