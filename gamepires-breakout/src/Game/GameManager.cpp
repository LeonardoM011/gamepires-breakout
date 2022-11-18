#include "GameManager.h"

GameManager::GameManager () {}

GameManager::~GameManager () {
    SDL_Quit ();
}

void GameManager::start() {
    init ();

}

void GameManager::init() {
    ASSERT_THAT(!SDL_Init (SDL_INIT_VIDEO), "SDL failed to initialize");
}
