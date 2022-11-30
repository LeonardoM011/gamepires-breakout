#pragma once
#include <string>
#include <SDL_mixer.h>
#include "Assert.h"

#define DEFAULT_VOLUME 16

class Sound {
public:
	Sound(const std::string& path);
	~Sound();
	void playSound();
private:
	Mix_Chunk *m_Chunk = NULL;
};

