#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"

#include "defines/id/ImageId.h"
#include "defines/id/TextId.h"

// Forward declarations
struct DrawManagerConfig;
struct DrawParameters;
class Window;
class Renderer;

class DrawManager
{
public:
	DrawManager();
	~DrawManager();

	DrawManager(const DrawManager& other) = delete;
	DrawManager(DrawManager&& other) = delete;

	DrawManager& operator=(const DrawManager& other) = delete;
	DrawManager& operator=(DrawManager&& other) = delete;

	bool				Init(const DrawManagerConfig& cfg);
	void				Deinit();

	void				ClearScreen() const;
	void				FinishFrame() const;

	void				DrawImage(ImageId id, const DrawParameters& p) const;
	void				DrawText(TextId id, const DrawParameters& p) const;
	void				DrawDynamicText(const String& string, const DrawParameters& p) const;

	bool				IsInsideWindow(const DrawParameters& p) const;

	Window*				GetWindow() const;
	Renderer*			GetRenderer() const;

private:
	Window*				m_Window;
	Renderer*			m_Renderer;
};

extern DrawManager* g_DrawManager;

#endif // !MANAGERS_DRAWMANAGER_H_