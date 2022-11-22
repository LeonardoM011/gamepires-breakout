#pragma once
#include <SDL.h>
#include "Window/WindowManager.h"
#include "Assert.h"
#include "Renderer/Renderer.h"
#include "Sprite/Sprite.h"
#include "Input/Input.h"

// EXTERN FUNCTIONS - for use inside main.cpp
extern void start();
extern void running(double delta);

class GameManager {
public:
	GameManager ();
	~GameManager ();
	void start();
	void update();
private:
	void init();
	void calcDelta();

	WindowManager *s_Window;
	Renderer *s_Renderer;
	Sprite *sprite;
	Input *s_Input;

	bool s_IsRunning = true;
	Uint64 s_TimeNow = 0;
	Uint64 s_TimeLast = 0;
	double s_DeltaTime = 0;
};
