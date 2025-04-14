#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/UI/UIComponentBase.h"
#include "System/Components/Drawing/Image.h"

struct ImageBoxConfig;

class ImageBox
	: public UIComponentBase
{
public:
	ImageBox();
	~ImageBox();

	bool				Init(const ImageBoxConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;
	void				Draw() const final;

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;
};