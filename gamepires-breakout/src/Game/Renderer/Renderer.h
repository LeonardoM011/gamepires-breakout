#pragma once
#include <SDL.h>
#include "Window/WindowManager.h"
#include "Assert.h"

#define RENDERER_COLOR 0xA9, 0xA9, 0xA9, 0xFF

class Renderer {
public:
	Renderer (const std::shared_ptr<WindowManager> &window);
	~Renderer ();
	void prepare();
	void update();
	SDL_Renderer *getSDLRenderer() { return m_Renderer; }
private:
	SDL_Renderer *m_Renderer;
};
