#include "WindowManager.h"

WindowManager::WindowManager (std::string title, int width, int height) :
	m_Width(width),
	m_Height(height) {
	m_Window = SDL_CreateWindow (title.c_str (),
								 SDL_WINDOWPOS_UNDEFINED,
								 SDL_WINDOWPOS_UNDEFINED,
								 width,
								 height,
								 SDL_WINDOW_SHOWN);
	ASSERT_THAT (m_Window != NULL, "SDL Window failed to create");
}

WindowManager::~WindowManager () {
	SDL_DestroyWindow(m_Window);
	m_Window = NULL;
}

void WindowManager::update() {
	SDL_UpdateWindowSurface(m_Window);
}
