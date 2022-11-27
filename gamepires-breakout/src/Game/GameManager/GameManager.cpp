#include "GameManager.h"
#include <sdl2-image/SDL_image.h>

extern void start();
extern void running(double delta);
extern void exit();

namespace Game {
    extern int windowWidth;
    extern int windowHeight;
}

GameManager::GameManager () {}

GameManager::~GameManager () {
    IMG_Quit();
    SDL_Quit();
}

void GameManager::start() {
    init ();

    ::start();
    update();
}

void GameManager::update() {
    calcDelta();
    while (m_IsRunning) {
        m_Renderer->prepare();

        m_Input->check();

        m_IsRunning = !m_Input->isQuitRequested();

        if(m_Input->isKeyPressed(SDL_SCANCODE_A))
            LOG_INFO("A");

        calcDelta();
        ::running(m_DeltaTime);

        m_Renderer->update();
    }
    ::exit();
}

void GameManager::init() {
    ASSERT_THAT(!SDL_Init (SDL_INIT_EVERYTHING), "SDL failed to initialize");
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        LOG_WARN("linear texture filtering not enabled");

    m_Window.reset(new WindowManager("Gamepires", WINDOW_SIZE));
    Game::windowWidth = m_Window->getWidth();
    Game::windowHeight = m_Window->getHeight();
    m_Renderer.reset(new Renderer(m_Window));

    Sprite::bindRenderer(m_Renderer);

    ASSERT_THAT(IMG_Init(IMG_INIT_PNG), "failed to initialize sdl img png");

    m_Input.reset(new Input());
}

void GameManager::calcDelta() {
    m_TimeLast = m_TimeNow;
    m_TimeNow = SDL_GetPerformanceCounter();
    m_DeltaTime = (double)((m_TimeNow - m_TimeLast) * 1000 / (double)SDL_GetPerformanceFrequency());
}
