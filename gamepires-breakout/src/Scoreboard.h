#pragma once

std::shared_ptr<Text> levelText;
std::shared_ptr<Text> scoreText;
std::shared_ptr<Text> livesText;

void initScoreboard() {
	levelText.reset(new Text("Level: " + std::to_string(level), SDL_Color(DEFAULT_FONT_COLOR)));
	scoreText.reset(new Text("Score: " + std::to_string(points), SDL_Color(DEFAULT_FONT_COLOR)));
	livesText.reset(new Text("Lives: " + std::to_string(lives), SDL_Color(DEFAULT_FONT_COLOR)));
}

void renderScoreboard() {
	levelText->render(12, 16, 0, 32);
	scoreText->render(Game::windowWidth / 2 - 70, 16, 0, 32);
	livesText->render(Game::windowWidth - 12 - 70, 16, 0, 32);
}

void freeScoreboard() {
	levelText.reset();
	scoreText.reset();
	livesText.reset();
}