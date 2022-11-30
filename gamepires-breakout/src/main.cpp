#include <unordered_map>

#include "Game.h"

std::shared_ptr<XMLParser> curLevel;

std::unordered_map<std::string, std::shared_ptr<Sprite>> loadedTextures = {{"", std::shared_ptr<Sprite>(nullptr)}};
std::unordered_map<std::string, std::shared_ptr<Sound>> loadedSounds = {{"", std::shared_ptr<Sound>(nullptr)}};

#include "Background.h"
#include "Wall.h"
#include "Bricks.h"
#include "Player.h"
#include "Ball.h"



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

void main_program() {
	curLevel.reset(new XMLParser("src/assets/levels/level1.xml"));
	/*for(auto b : bricks) {
		LOG_INFO("id:" << b.id << "|texture:" << b.texture << "|hitPoints:"
				 << b.hitPoints << "|hitSound:" << b.hitSound << "|breakSound:"
				 << b.breakSound << "|breakScore:" << b.breakScore);
	}*/
}

void start() {
	for(std::string path : texturePaths) {
		loadedTextures.insert({path, std::shared_ptr<Sprite>(new Sprite(path))});
	}
	for(std::string path : soundPaths) {
		loadedSounds.insert({path, std::shared_ptr<Sound>(new Sound(path))});
	}

	initBackground();
	initWall();
	initPlayer();
	initBall();
	initBricks();
}

void running(double delta) {

	renderBackground();
	renderWall();
	renderPlayer(delta);
	renderBall(delta);
	renderBricks();
}

void exit() {
	freeBackground();
	freeBall();
	freeWall();
	freePlayer();
	freeBricks();

	loadedSounds.clear();
	loadedTextures.clear();

	curLevel.reset();
}

