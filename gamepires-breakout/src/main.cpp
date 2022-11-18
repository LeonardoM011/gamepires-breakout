#include "Game.h"
#include <iostream>

#include <Windows.h>
#include <Logging/Log.h>

void main_program () {
	LOG_ERROR("greska")
	LOG_WARN("warning")
	LOG_INFO("info")
	std::cout << "Main" << std::endl;
}

void start () {
	std::cout << "Hello";
}

void running (double delta) {

}

