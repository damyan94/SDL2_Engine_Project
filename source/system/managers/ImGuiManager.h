#ifndef MANAGERS_IMGUIMANAGER_H_
#define MANAGERS_IMGUIMANAGER_H_

#include "system/sdl_utils/input/InputEvent.h"

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

private:
	void				DrawInternal() const;
};

#endif // !MANAGERS_IMGUIMANAGER_H_