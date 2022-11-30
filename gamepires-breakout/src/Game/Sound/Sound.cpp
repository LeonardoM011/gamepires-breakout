#include "Sound.h"

Sound::Sound(const std::string &path) {
	LOG_INFO("loading sound " + path);
	m_Chunk = Mix_LoadWAV(path.c_str());
	ASSERT_THAT(m_Chunk != NULL, "sound " + path + " failed to load");
	Mix_VolumeChunk(m_Chunk, DEFAULT_VOLUME);
	LOG_OK("sound " + path + " successfully loaded");
}

Sound::~Sound() {
	Mix_FreeChunk(m_Chunk);
}

void Sound::playSound() {
	Mix_PlayChannel(-1, m_Chunk, 0);
}
