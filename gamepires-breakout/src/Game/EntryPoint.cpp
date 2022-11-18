#pragma once
#include "GameManager.h"

// EXTERN FUNCTIONS - for use inside main.cpp
extern void main_program();


int main(int argc, char* argv[]) {
    main_program ();

    GameManager gameManager;
    gameManager.start();
    return 0;
}