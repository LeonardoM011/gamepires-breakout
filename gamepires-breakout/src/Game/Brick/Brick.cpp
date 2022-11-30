#include "Brick.h"

Brick::Brick(std::shared_ptr<Sprite> sprite,
			 float x,
			 float y,
			 float width,
			 float height,
			 int hitPoints,
			 std::shared_ptr<Sound> hitSound,
			 std::shared_ptr<Sound> breakSound,
			 int breakScore) :
	Object(sprite, x, y, width, height) {

	m_HitPoints = hitPoints;
	m_BreakScore = breakScore;
	m_HitSound = hitSound;
	m_BreakSound = breakSound;
}

Brick::~Brick() {}
