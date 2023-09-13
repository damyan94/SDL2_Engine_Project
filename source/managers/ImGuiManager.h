#ifndef MANAGERS_IMGUIMANAGER_H_
#define MANAGERS_IMGUIMANAGER_H_

#include "sdl_utils/input/InputEvent.h"

struct ImGuiManagerConfig;

class ImGuiManager
{
public:
	ImGuiManager();
	~ImGuiManager();

	ImGuiManager(const ImGuiManager& other) = delete;
	ImGuiManager(ImGuiManager&& other) = delete;

	ImGuiManager& operator=(const ImGuiManager& other) = delete;
	ImGuiManager& operator=(ImGuiManager&& other) = delete;

	bool				Init(const ImGuiManagerConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

private:
	void				DrawInternal() const;
};

extern ImGuiManager* g_ImGuiManager;

#endif // !MANAGERS_IMGUIMANAGER_H_