#pragma once

// ---- ASSERT DEF ----
#ifdef PLATFORM_WINDOWS
	#define DEBUGBREAK __debugbreak()
#elif PLATFORM_LINUX
	#include <signal.h>
	#define DEBUGBREAK raise(SIGTRAP)
#endif

#ifdef DEBUG
	#include <Logging/Log.h>
	#define ASSERT_THAT(exp, msg) { if(!exp) { LOG_FAILED(msg); DEBUGBREAK; } }
#else
	#define ASSERT_THAT(exp, msg) exp;
#endif
// ---- ----