#include "GameManager.h"

GameManager::GameManager () {}

GameManager::~GameManager () {
    SDL_Quit ();
}

void GameManager::start() {
    init ();

    sprite = new Sprite();
    sprite->loadMedia("src/assets/test.bmp");


    update();
}

void GameManager::update() {
    while (isRunning) {


        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                isRunning = false;
            }
        }
        s_Window->applySprite(sprite);
        s_Window->update();
    }
}

void GameManager::init() {
    ASSERT_THAT(!SDL_Init (SDL_INIT_EVERYTHING), "SDL failed to initialize");

    s_Window = new WindowManager("Gamepires", 720, 480);
}
