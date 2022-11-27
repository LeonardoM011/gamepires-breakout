#include "Renderer.h"
#include <sdl2-image/SDL_image.h>

Renderer::Renderer (const std::shared_ptr<WindowManager> &window) {
	m_Renderer = SDL_CreateRenderer (window->getSDLWindow (), -1, SDL_RENDERER_ACCELERATED);
	ASSERT_THAT (m_Renderer != NULL, "SDL Renderer failed to create");

	SDL_SetRenderDrawColor(m_Renderer, RENDERER_COLOR);
}

Renderer::~Renderer () {
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = NULL;
}

void Renderer::prepare() {
	SDL_SetRenderDrawColor(m_Renderer, RENDERER_COLOR);
	SDL_RenderClear(m_Renderer);
}

void Renderer::update() {
	SDL_RenderPresent(m_Renderer);
}
