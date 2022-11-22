#include "WindowManager.h"

WindowManager::WindowManager (std::string title, int width, int height) {
	s_Window = SDL_CreateWindow (title.c_str (),
								 SDL_WINDOWPOS_UNDEFINED,
								 SDL_WINDOWPOS_UNDEFINED,
								 width,
								 height,
								 SDL_WINDOW_SHOWN);
	ASSERT_THAT (s_Window != NULL, "SDL Window failed to create");
}

WindowManager::~WindowManager () {
	SDL_DestroyWindow(s_Window);
}

void WindowManager::update() {
	SDL_UpdateWindowSurface(s_Window);
}
