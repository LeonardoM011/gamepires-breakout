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

	WindowManager *m_Window = nullptr;
	Renderer *m_Renderer = nullptr;
	Input *m_Input = nullptr;

	bool m_IsRunning = true;
	Uint64 m_TimeNow = 0;
	Uint64 m_TimeLast = 0;
	double m_DeltaTime = 0;
};