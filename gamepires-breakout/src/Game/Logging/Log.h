#ifdef DEBUG

#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

// ---- ANSI ESCAPE COLOR CODES ----
#define COLOR_BLACK		"\x1B[30m"
#define COLOR_RED		"\x1B[31m"
#define COLOR_GREEN		"\x1B[32m"
#define COLOR_YELLOW	"\x1B[33m"
#define COLOR_BLUE		"\x1B[34m"
#define COLOR_MAGENTA	"\x1B[35m"
#define COLOR_CYAN		"\x1B[36m"
#define COLOR_WHITE		"\x1B[37m"
#define COLOR_RESET		"\x1B[0m"

#define BOLD_MODE		"\x1B[1m"
#define RESET_BOLD_MODE	"\x1B[22m"
// ---- ----

#define LOG_ERROR(msg)	std::cout << \
						std::format("{:%F %OH:%OM:%OS}", std::chrono::zoned_time(std::chrono::current_zone(), std::chrono::system_clock::now())) \
						<< " [" << COLOR_RED << "FAILED" << COLOR_RESET << "] " <<  msg << std::endl;

#define LOG_INFO(msg)	std::cout << \
						std::format("{:%F %OH:%OM:%OS}", std::chrono::zoned_time(std::chrono::current_zone(), std::chrono::system_clock::now())) \
						<< " [" << COLOR_GREEN << "  OK  " << COLOR_RESET << "] " <<  msg << std::endl;

#define LOG_WARN(msg)	std::cout << \
						std::format("{:%F %OH:%OM:%OS}", std::chrono::zoned_time(std::chrono::current_zone(), std::chrono::system_clock::now())) \
						<< " [" << COLOR_YELLOW << " WARN " << COLOR_RESET << "] " <<  msg << std::endl;

#else
#define LOG_ERROR(msg)
#define LOG_INFO(msg)
#define LOG_WARN(msg)
#endif