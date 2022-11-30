#pragma once

std::vector<std::shared_ptr<Brick>> bricks;

void initBricks() {
	std::vector<BrickXML> brickTypes = curLevel->getBrickTypes();

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
			for(BrickXML brick : brickTypes) {
				if(c != brick.id) continue;
				bricks.push_back(std::shared_ptr<Brick>(new Brick(loadedTextures[brick.texture],
																  (float)x,
																  (float)y,
																  (float)brickWidth,
																  (float)brickHeight,
																  brick.hitPoints,
																  loadedSounds[brick.hitSound],
																  loadedSounds[brick.breakSound],
																  brick.breakScore)));
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
	bricks.clear();
}