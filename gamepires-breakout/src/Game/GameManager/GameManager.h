#pragma once
#include <SDL.h>
#include "Window/WindowManager.h"
#include "Assert.h"
#include "Renderer/Renderer.h"
#include "Input/Input.h"
#include "Object/Object.h"

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

	WindowManager *s_Window = nullptr;
	Renderer *s_Renderer = nullptr;
	Input *s_Input = nullptr;
	Object *s_Object = nullptr;

	bool s_IsRunning = true;
	Uint64 s_TimeNow = 0;
	Uint64 s_TimeLast = 0;
	double s_DeltaTime = 0;
};
