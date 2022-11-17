#include "GameManager.h"

GameManager::GameManager () {}

GameManager::~GameManager () {
    SDL_Quit ();
}

int GameManager::start() {
    init ();

    return 0;
}

int GameManager::init() {
    ASSERT_THAT(!SDL_Init (SDL_INIT_VIDEO), "SDL failed to initialize");
    return 0;
}
