#include "Object.h"
#include <cmath>

Object::Object(float x, float y) :
	Sprite(),
	s_X(x),
	s_Y(y) {}

Object::~Object() {

}

void Object::move(float x, float y) {
	s_X += x;
	s_Y += y;
}

void Object::render(Renderer *renderer) {
	Sprite::render(renderer, round(s_X), round(s_Y), s_Width, s_Height);
}
