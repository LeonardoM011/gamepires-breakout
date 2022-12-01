#include <unordered_map>
#include <map>

#include "Game.h"

#define BALL_DEFAULT_SPEED 0.5f
#define DEFAULT_PLAYER_SPEED 0.4f
#define MAX_PLAYER_LIVES 3
#define PLAYER_BALL_CURVE -0.3f
#define DEFAULT_FONT_COLOR 0, 0, 0

#define PLAYER_TEXTURE_PATH "src/assets/textures/player.png"
#define WALL_TEXTURE_PATH "src/assets/textures/brick_white.png"
#define BALL_TEXTURE_PATH "src/assets/textures/ball_white.png"
#define BARRIER_HIT_SOUND "src/assets/soundfx/sound_hit_barrier.wav"
#define PLAYER_HIT_SOUND "src/assets/soundfx/sound_player_hit.wav"
#define LOSE_LIFE_SOUND "src/assets/soundfx/sound_lost.wav"
#define LOSE_ALL_SOUND "src/assets/soundfx/sound_winddown.wav"
#define START_LEVEL_SOUND "src/assets/soundfx/sound_windup.wav"

int level = 0;
int lives = MAX_PLAYER_LIVES;
int points = 0;

std::unordered_map<std::string, std::shared_ptr<Sprite>> loadedTextures = {{"", std::shared_ptr<Sprite>(nullptr)}};
std::unordered_map<std::string, std::shared_ptr<Sound>> loadedSounds = {{"", std::shared_ptr<Sound>(nullptr)}};
std::vector<std::shared_ptr<XMLParser>> levels;
std::shared_ptr<XMLParser> curLevel;

#include "Background.h"
#include "Wall.h"
#include "Bricks.h"
#include "Player.h"
#include "Ball.h"
#include "Collisions.h"
#include "Scoreboard.h"
#include "Level.h"

std::vector<std::string> texturePaths = {
	"src/assets/textures/ball_blue.png",
	"src/assets/textures/ball_white.png",
	"src/assets/textures/brick_blue.png",
	"src/assets/textures/brick_green.png",
	"src/assets/textures/brick_purple.png",
	"src/assets/textures/brick_red.png",
	"src/assets/textures/brick_white.png",
	"src/assets/textures/brick_yellow.png",
	"src/assets/textures/player.png",
	"src/assets/textures/powerup.png"
};

std::vector<std::string> soundPaths = {
	"src/assets/soundfx/sound_break1.wav",
	"src/assets/soundfx/sound_break2.wav",
	"src/assets/soundfx/sound_hit_barrier.wav",
	"src/assets/soundfx/sound_hit1.wav",
	"src/assets/soundfx/sound_lost.wav",
	"src/assets/soundfx/sound_player_hit.wav",
	"src/assets/soundfx/sound_wind.wav",
	"src/assets/soundfx/sound_winddown.wav",
	"src/assets/soundfx/sound_windup.wav"
};

std::vector<std::string> levelPaths = {
	"src/assets/levels/leveltesteasy.xml",
	"src/assets/levels/leveltest.xml",
	//"src/assets/levels/level1.xml"
};

void main_program() {
	LOG_OK("program successfully started");
}

void start() {
	LOG_OK("everything is initialized");
	for(std::string path : texturePaths) {
		loadedTextures.insert({path, std::shared_ptr<Sprite>(new Sprite(path))});
	}
	for(std::string path : soundPaths) {
		loadedSounds.insert({path, std::shared_ptr<Sound>(new Sound(path))});
	}
	for(std::string path : levelPaths) {
		levels.push_back(std::shared_ptr<XMLParser>(new XMLParser(path)));
	}

	startLevel();
}

void running(double delta) {
	renderLevel(delta);
}

void exit() {
	restartLevel();

	loadedSounds.clear();
	loadedTextures.clear();
	levels.clear();

	curLevel.reset();
	LOG_OK("program closed");
}

