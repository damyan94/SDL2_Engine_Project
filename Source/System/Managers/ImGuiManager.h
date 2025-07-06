#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

struct ImGuiManagerConfig;

class ImGuiManager
	: public INonCopyMoveable
{
private:
	ImGuiManager();
	~ImGuiManager();

public:
	static ImGuiManager& Instance();

	bool				Init(const ImGuiManagerConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	void				RenderMassageLoyaltyUI() const;
	void				RenderMainMenu() const;
	void				RenderEmployeesDB() const;
	void				RenderClientsDB() const;
	void				RenderMassagesDB() const;

private:
	void				DrawInternal() const;
};