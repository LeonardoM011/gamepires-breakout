#pragma once
#include "Sprite/Sprite.h"

class Object: public Sprite {
public:
	Object(float x = 0, float y = 0);
	~Object();
	void move(float x, float y);
	void render(Renderer *renderer);
private:
	float s_X;
	float s_Y;
};

