#pragma once
#include "Object/Object.h"
#include "Sound/Sound.h"

class Brick : public Object {
public:
	Brick(std::shared_ptr<Sprite> sprite,
		  float x,
		  float y,
		  float width,
		  float height,
		  int hitPoints,
		  std::shared_ptr<Sound> hitSound,
		  std::shared_ptr<Sound> breakSound,
		  int breakScore);
	~Brick();
	void hit() { m_HitPoints--; }
	bool didBreak() const { return m_HitPoints == 0; }
	int getScore() const { return m_BreakScore; }
	void playHitSound() const { m_HitSound->playSound(); }
	void playBreakSound() const { m_BreakSound->playSound(); }
private:
	int m_HitPoints = 0;
	int m_BreakScore = 0;
	std::shared_ptr<Sound> m_HitSound = nullptr;
	std::shared_ptr<Sound> m_BreakSound = nullptr;
};

