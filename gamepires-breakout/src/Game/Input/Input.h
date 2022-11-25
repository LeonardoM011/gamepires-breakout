#pragma once
#include <SDL.h>

class Input {
public:
	Input() {
		m_IsQuitRequested = false;
		m_Event = SDL_Event();
		m_KeyDown = SDL_GetKeyboardState(NULL);
	}
	~Input() {
		delete m_KeyDown;
	}
	void check() {
		SDL_PumpEvents();
		while(SDL_PollEvent(&m_Event) != 0) {
			m_IsQuitRequested = m_Event.type == SDL_QUIT;
		}
	}

	bool isQuitRequested() const { return m_IsQuitRequested; }

	bool isKeyPressed(SDL_Scancode scancode) const {
		return m_KeyDown[scancode];
	}
private:
	SDL_Event m_Event;
	const Uint8 *m_KeyDown;
	bool m_IsQuitRequested;
};

