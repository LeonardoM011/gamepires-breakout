#pragma once

#include <iostream>
#include <string>

#include <SDL.h>

// ---- ASSERT DEF ----
#ifdef PLATFORM_WINDOWS
	#define DEBUGBREAK __debugbreak()
#elif PLATFORM_LINUX
	#include <signal.h>
	#define DEBUGBREAK raise(SIGTRAP)
#endif

#ifdef DEBUG
	#include <cassert>
	#define ASSERT_THAT(exp, msg) DEBUGBREAK;assert(((void)msg, exp))
#else
	#define ASSERT_THAT(exp, msg) exp
#endif
// ---- ----

#include "Window/WindowManager.h"
#include "Renderer/Renderer.h"
#include "GameManager.h"



// EXTERN FUNCTIONS - for use inside main
extern void main_program ();
extern void start ();
extern void running (double delta);
