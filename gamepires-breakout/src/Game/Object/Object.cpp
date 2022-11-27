#include "Object.h"
#include <cmath>

namespace Game {
	extern int windowWidth;
	extern int windowHeight;
}

Object::Object(std::shared_ptr<Sprite> sprite, float x, float y, float width, float height) :
	m_X(x),
	m_Y(y),
	m_Width(width),
	m_Height(height) {
	m_Sprite.swap(sprite);
	if(!m_Width) m_Width = (float)m_Sprite->getWidth();
	if(!m_Height) m_Height = (float)m_Sprite->getHeight();
}

Object::~Object() {

}

SDL_Point Object::getCollision(const SDL_Rect &object) {
	int leftA = (int)round(m_X);
	int rightA = (int)round(m_X + m_Width);
	int topA = (int)round(m_Y);
	int bottomA = (int)round(m_Y + m_Width);

	int leftB = object.x;
	int rightB = object.x + object.w;
	int topB = object.y;
	int bottomB = object.y + object.h;

	/*if(bottomA <= topB) {
		return SDL_Point();
	}

	if(topA >= bottomB) {
		return SDL_Point();
	}

	if(rightA <= leftB) {
		return SDL_Point();
	}

	if(leftA >= rightB) {
		return SDL_Point();
	}*/

	int xdiff = 0;
	int ydiff = 0;

	if(rightA > leftB and rightA < rightB) {
		LOG_INFO("RIGHT COL");
		xdiff = leftB - rightA;
	}
	if(leftA < rightB and leftA > leftB) {
		LOG_INFO("LEFT COL");
		xdiff = rightB - leftA;
	}
	if(bottomA > topB and bottomA < bottomB) {
		ydiff = topB - bottomA;
	}
	if(topA < bottomB and topA > topB) {
		ydiff = bottomB - topA;
	}

	return SDL_Point(xdiff, ydiff);
}

void Object::move(float x, float y) {
	m_X += x;
	m_Y += y;
}

void Object::render() {
	m_Sprite->render((int)round(m_X), (int)round(m_Y), (int)round(m_Width), (int)round(m_Height));
}
