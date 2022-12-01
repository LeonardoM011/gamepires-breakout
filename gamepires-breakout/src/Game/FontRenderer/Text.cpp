#include "Text.h"

std::shared_ptr<Renderer> Text::s_Renderer = nullptr;
TTF_Font* Text::s_Font = NULL;

Text::Text(std::string text, SDL_Color textColor) {
	updateText(text, textColor);
}

Text::~Text() {
	SDL_DestroyTexture(m_Texture);
	m_Texture = NULL;
}

void Text::render(int x,
					int y,
					int width,
					int height,
					SDL_Rect *clip,
					double angle,
					SDL_Point *center,
					SDL_RendererFlip flip) {

	if(!width) width = m_Width;
	if(!height) height = m_Height;

	SDL_Rect rect = {x, y, width, height};
	SDL_RenderCopyEx(s_Renderer->getSDLRenderer(),
					 m_Texture,
					 clip,
					 &rect,
					 angle,
					 center,
					 flip);
}

void Text::setDefaultFont(std::string fontPath, int fontSize) {
	s_Font = TTF_OpenFont(fontPath.c_str(), fontSize);
	ASSERT_THAT(s_Font != NULL, "failed to load font " + fontPath);
}

void Text::updateText(std::string text, SDL_Color textColor) {
	SDL_DestroyTexture(m_Texture);
	m_Texture = NULL;

	LOG_INFO("loading text " + text);
	SDL_Surface *mediaSurface = TTF_RenderText_Solid(s_Font, text.c_str(), textColor);
	ASSERT_THAT(mediaSurface != NULL, "text " + text + " failed to init");

	m_Texture = SDL_CreateTextureFromSurface(s_Renderer->getSDLRenderer(), mediaSurface);
	ASSERT_THAT(m_Texture != NULL, "text " + text + "failed to create");
	m_Width = mediaSurface->w;
	m_Height = mediaSurface->h;
	SDL_FreeSurface(mediaSurface);
	LOG_OK("text " + text + " successfully loaded");
}
