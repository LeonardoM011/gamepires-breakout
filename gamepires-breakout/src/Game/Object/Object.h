#pragma once
#include "Sprite/Sprite.h"

class Object: public Sprite {
public:
	Object(float x = 0, float y = 0);
	~Object();
	float getX() const { return m_X; }
	float getY() const { return m_Y; }
	void move(float x, float y);
	void render();
private:
	float m_X;
	float m_Y;
};

