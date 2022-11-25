#include "Object.h"
#include <cmath>

Object::Object(float x, float y) :
	Sprite(),
	m_X(x),
	m_Y(y) {}

Object::~Object() {

}

void Object::move(float x, float y) {
	m_X += x;
	m_Y += y;
}

void Object::render() {
	Sprite::render((int)round(m_X), (int)round(m_Y), m_Width, m_Height);
}
