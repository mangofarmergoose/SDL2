#include "AnimatedSprite.hpp"
#include "ResManager.hpp"

AnimatedSprite::AnimatedSprite(SDL_Renderer*& renderer, std::string filepath){
    SDL_Surface* retrieve_surface = ResourceManager::GetInstance().GetSurface(filepath);
    m_texture = SDL_CreateTextureFromSurface(renderer, retrieve_surface);
}

AnimatedSprite::~AnimatedSprite(){
    SDL_DestroyTexture(m_texture);
}

void AnimatedSprite::Draw(int x, int y, int w, int h){
    //create a rect
    m_dst.x = x;
    m_dst.y = y;
    m_dst.h = h;
    m_dst.w = w;
}

void AnimatedSprite::PlayFrame(int x, int y, int w, int h, int frame){
    m_src.x = x+w*frame;  //move the sprite x coord by w*frame no.
    m_src.y = y;
    m_src.w = w;
    m_src.h = h;
}

void AnimatedSprite::Update(){

}

void AnimatedSprite::Render(SDL_Renderer *&renderer){
    SDL_RenderCopy(renderer, m_texture, &m_src, &m_dst);
}