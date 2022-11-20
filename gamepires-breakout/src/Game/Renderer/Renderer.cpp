#include "Renderer.h"
#include <cassert>

Renderer::Renderer (WindowManager &window) {
	s_Renderer = SDL_CreateRenderer (window.getSDLWindow (), -1, SDL_RENDERER_ACCELERATED);
	ASSERT_THAT (s_Renderer == NULL, "SDL Renderer failed to create");
}

Renderer::~Renderer () {
	SDL_DestroyRenderer(s_Renderer);
}
