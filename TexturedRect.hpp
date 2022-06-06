#ifndef TEXTUREDRECT_HPP
#define TEXTUREDRECT_HPP 
#include <string>
#include "SDL.h"

class TexturedRect
{
private:
    SDL_Rect m_rect;
    SDL_Texture *m_texture;
    inline SDL_Rect GetRect() const{return m_rect;};

public:
    // constructor
    TexturedRect(SDL_Renderer* renderer, std::string filepath);
    // destructor
    ~TexturedRect();
    void SetPosition(int x, int y);
    void SetDimension(int w, int h);
    SDL_bool IsColliding(TexturedRect& obj);
    void Update();
    void Render(SDL_Renderer* renderer);
    int GetPositionX();
    int GetPositionY();
    int GetWidth();
    int GetHeight();
};
#endif