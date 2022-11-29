#pragma once

extern std::shared_ptr<XMLParser> curLevel;

std::vector<std::pair<char, std::shared_ptr<Sprite>>> bricksSprite;
std::vector<std::shared_ptr<Object>> bricks;

void initBricks() {
	std::vector<Brick> brickTypes = curLevel->getBrickTypes();
	for(Brick brick : brickTypes) {
		std::shared_ptr<Sprite> sprite;
		sprite.reset(new Sprite());
		sprite->loadMedia(brick.texture);
		bricksSprite.push_back(std::pair(brick.id, sprite));
	}

	int leftBorder = 44;
	int rightBorder = Game::windowWidth - 44;
	int topBorder = 48;
	int availableWidth = rightBorder - leftBorder;

	int columnSpacing = curLevel->getColumnSpacing();
	int columnCount = curLevel->getColumnCount();

	int rowSpacing = curLevel->getRowSpacing();
	int rowCount = curLevel->getRowCount();

	float brickWidth = ((float)availableWidth - (float)columnSpacing * ((float)columnCount + 1.f)) / (float)columnCount;
	float brickHeight = 30.f;


	std::vector<std::vector<char>> layout = curLevel->getLayout();

	float x = (float)(leftBorder + columnSpacing);
	float y = (float)(topBorder + rowSpacing);
	for(auto row : layout) {
		for(char c : row) {
			for(Brick brick : brickTypes) {
				if(c != brick.id) continue;
				std::shared_ptr<Object> obj;
				for(auto spr : bricksSprite) {
					if(spr.first == brick.id) {
						obj.reset(new Object(spr.second, (float)x, (float)y, (float)brickWidth, (float)brickHeight));
						bricks.push_back(obj);
					}
				}

			}
			x += columnSpacing + brickWidth;
		}
		x = (float)(leftBorder + columnSpacing);
		y += rowSpacing + brickHeight;
	}
}

void renderBricks() {
	for(auto b : bricks) {
		b->render();
	}
}

void freeBricks() {
	for(int i = 0; i < bricks.size(); i++) {
		bricks[i].reset();
	}
	bricks.clear();
	for(int i = 0; i < bricksSprite.size(); i++) {
		bricksSprite[i].second.reset();
	}
	bricksSprite.clear();
}