#include "GameManager.h"
#include <sdl2-image/SDL_image.h>

extern void start();
extern void running(double delta);

GameManager::GameManager () {}

GameManager::~GameManager () {
    IMG_Quit();
    SDL_Quit();
}

void GameManager::start() {
    init ();

    s_Object = new Object();
    s_Object->loadMedia(s_Renderer, "src/assets/test.png");

    ::start();
    update();
}

void GameManager::update() {
    calcDelta();
    while (s_IsRunning) {
        s_Renderer->prepare();

        s_Input->check();

        s_IsRunning = !s_Input->isQuitRequested();

        if(s_Input->isKeyPressed(SDL_SCANCODE_A))
            LOG_INFO("A");

        calcDelta();
        ::running(s_DeltaTime);

        s_Object->move(0.1 * s_DeltaTime, 0);
        s_Object->render(s_Renderer);


        s_Renderer->update();
    }
}

void GameManager::init() {
    ASSERT_THAT(!SDL_Init (SDL_INIT_EVERYTHING), "SDL failed to initialize");
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        LOG_WARN("linear texture filtering not enabled");

    s_Window = new WindowManager("Gamepires", 720, 480);
    s_Renderer = new Renderer(s_Window);

    ASSERT_THAT(IMG_Init(IMG_INIT_PNG), "failed to initialize sdl img png");

    s_Input = new Input();
}

void GameManager::calcDelta() {
    s_TimeLast = s_TimeNow;
    s_TimeNow = SDL_GetPerformanceCounter();
    s_DeltaTime = (double)((s_TimeNow - s_TimeLast) * 1000 / (double)SDL_GetPerformanceFrequency());
}
