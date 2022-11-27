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

#define WINDOW_SIZE 1080, 720

class GameManager {
public:
	GameManager ();
	~GameManager ();
	void start();
	void update();

	int getWindowWidth() const { return m_Window->getWidth(); }
	int getWindowHeight() const { return m_Window->getHeight(); }
private:
	void init();
	void calcDelta();

	std::shared_ptr<WindowManager> m_Window = nullptr;
	std::shared_ptr<Renderer> m_Renderer = nullptr;
	std::unique_ptr<Input> m_Input = nullptr;

	bool m_IsRunning = true;
	Uint64 m_TimeNow = 0;
	Uint64 m_TimeLast = 0;
	double m_DeltaTime = 0;
};