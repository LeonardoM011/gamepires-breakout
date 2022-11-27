#pragma once
#include "Sprite/Sprite.h"

class Object {
public:
	Object(std::shared_ptr<Sprite> sprite, float x = 0, float y = 0, float width = 0, float height = 0);
	~Object();
	float getX() const { return m_X; }
	float getY() const { return m_Y; }
	void setX(float x) { m_X = x; }
	void setY(float y) { m_Y = y; }
	void moveX(float x) { m_X += x; }
	void moveY(float y) { m_Y += y; }
	float getWidth() const { return m_Width; }
	float getHeight() const { return m_Height; }
	void setWidth(float width) { m_Width = width; }
	void setHeight(float height) { m_Height = height; }
	void setSize(float width, float height) { m_Width = width; m_Height = height; }
	// Returns SDL_Point, returns difference in points
	SDL_Point getCollision(const SDL_Rect &object);
	void move(float x, float y);
	void render();
private:
	std::shared_ptr<Sprite> m_Sprite = nullptr;
	float m_X;
	float m_Y;
	float m_Width;
	float m_Height;
};

