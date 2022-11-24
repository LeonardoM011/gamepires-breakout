#pragma once
#include <SDL.h>

class Input {
public:
	Input() {
		s_IsQuitRequested = false;
		s_Event = SDL_Event();
		s_KeyDown = SDL_GetKeyboardState(NULL);
	}
	~Input() {
		delete s_KeyDown;
	}
	void check() {
		SDL_PumpEvents();
		while(SDL_PollEvent(&s_Event) != 0) {
			s_IsQuitRequested = s_Event.type == SDL_QUIT;
		}
	}

	bool isQuitRequested() const { return s_IsQuitRequested; }

	bool isKeyPressed(SDL_Scancode scancode) const {
		return s_KeyDown[scancode];
	}
private:
	SDL_Event s_Event;
	const Uint8 *s_KeyDown;
	bool s_IsQuitRequested;
};

