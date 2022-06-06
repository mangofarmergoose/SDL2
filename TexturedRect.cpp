#include <iostream>
#include <string>
#include "SDL.h"
#include "TexturedRect.hpp"
#include "ResManager.hpp"
// constructor
TexturedRect::TexturedRect(SDL_Renderer* renderer, std::string filepath)
{   
    SDL_Surface* surface = ResourceManager::GetInstance().GetSurface(filepath);
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    m_rect.x = 0;
    m_rect.y = 0;
    m_rect.w = 32;
    m_rect.h = 32;
}
// destructor
TexturedRect::~TexturedRect()
{
    SDL_DestroyTexture(m_texture);
}

void TexturedRect::SetPosition(int x, int y)
{
    m_rect.x = x;
    m_rect.y = y;
}


void TexturedRect::SetDimension(int w, int h)
{
    m_rect.w = w;
    m_rect.h = h;
}

SDL_bool TexturedRect::IsColliding(TexturedRect& obj){
    const SDL_Rect tmp = obj.GetRect();
    return SDL_HasIntersection(&m_rect, &tmp);
}

void TexturedRect::Update()
{
}

void TexturedRect::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
}


