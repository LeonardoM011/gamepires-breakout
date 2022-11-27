#pragma once
#include <SDL.h>

class Input {
public:
	Input() {
		m_IsQuitRequested = false;
		m_Event = SDL_Event();
	}
	~Input() {}
	void check() {
		SDL_PumpEvents();
		while(SDL_PollEvent(&m_Event) != 0) {
			m_IsQuitRequested = m_Event.type == SDL_QUIT;
		}
	}

	static SDL_Point getMousePos() {
		int x;
		int y;
		s_Button = SDL_GetMouseState(&x, &y);
		return SDL_Point(x, y);
	}

	static Uint32 getMouseButton() { return s_Button; }

	bool isQuitRequested() const { return m_IsQuitRequested; }

	static bool isKeyPressed(SDL_Scancode scancode) {
		const Uint8 *keyDown = SDL_GetKeyboardState(NULL);
		return keyDown[scancode];
	}
private:
	SDL_Event m_Event;
	static inline Uint32 s_Button = 0;
	bool m_IsQuitRequested;
};

