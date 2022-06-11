#include "DynamicText.hpp"
DynamicText::DynamicText(std::string fontfilepath, int fontsize){
    m_ourFont = TTF_OpenFont(fontfilepath.c_str(), fontsize);
    //check whether font can be loaded
    if(m_ourFont == nullptr){
        std::cout << "Font cannot be loaded" << std::endl;
        exit(1);
    }
}

DynamicText::~DynamicText(){
    SDL_DestroyTexture(m_texture);
    TTF_CloseFont(m_ourFont);
}

void DynamicText::DrawText(SDL_Renderer* renderer, std::string text, int x, int y, int w, int h){
    m_surface = TTF_RenderText_Solid(m_ourFont, text.c_str(), {255,255,255});
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    SDL_FreeSurface(m_surface);

    m_rectangle.x = x;
    m_rectangle.y = y;
    m_rectangle.w = w;
    m_rectangle.h = h;

    SDL_RenderCopy(renderer, m_texture, NULL, &m_rectangle);
    if(m_texture == nullptr){
        SDL_DestroyTexture(m_texture);
    }
}


