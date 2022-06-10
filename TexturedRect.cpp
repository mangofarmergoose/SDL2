#include <iostream>
#include <string>
#include "SDL.h"
#include "TexturedRect.hpp"
#include "ResManager.hpp"
// constructor
TexturedRect::TexturedRect(SDL_Renderer* renderer, std::string filepath)
{   
    SDL_Surface* surface = ResourceManager::GetInstance().GetSurface(filepath);
    SDL_SetColorKey(surface, SDL_FALSE, SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF));
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    InitDefaults();
}

TexturedRect::TexturedRect(SDL_Renderer* renderer, std::string filepath, int r, int g, int b)
{   
    SDL_Surface* surface = ResourceManager::GetInstance().GetSurface(filepath);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    InitDefaults();
    m_redcolorkey = r;
    m_greencolorkey = g;
    m_bluecolorkey = b;
}

void TexturedRect::InitDefaults(){
    m_rect.x = 0;
    m_rect.y = 0;
    m_rect.w = 32;
    m_rect.h = 32;

    m_redcolorkey = 0xFF;
    m_greencolorkey = 0x00;
    m_bluecolorkey = 0xFF;
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

int TexturedRect::GetPositionX(){
    return m_rect.x;
}

int TexturedRect::GetPositionY(){
    return m_rect.y;
}

int TexturedRect::GetWidth(){
    return m_rect.w;
}

int TexturedRect::GetHeight(){
    return m_rect.h;
}

