#include "SDL_ttf.h"
#include <iostream>
#include <string>
#ifndef TEXT_HPP
#define TEXT_HPP

class DynamicText{
public:
    DynamicText(std::string fontfilepath, int fontsize);
    ~DynamicText();
    void DrawText(SDL_Renderer* renderer, std::string text, int x, int y, int w, int h);
private:
    SDL_Rect m_rectangle;
	SDL_Texture* m_texture;
	SDL_Surface* m_surface;
    // The actual font
	TTF_Font* m_ourFont;
};
#endif