#include "GameEntity.hpp"
#include <iostream>
GameEntity::GameEntity(){
    m_sprite = nullptr;
    m_collider = nullptr;
}

GameEntity::GameEntity(SDL_Renderer* renderer){
    m_renderer = renderer;
    m_sprite = nullptr;
    m_collider = nullptr;
}

GameEntity::~GameEntity(){
    if (m_sprite != nullptr)
    {
        delete m_sprite;
    }
    if (m_collider != nullptr)
    {
        delete m_collider;
    }
};

void GameEntity::Update(){
    //Update the position of collider to be same as m_sprite
    if(m_sprite != nullptr){
        int x = m_sprite->GetPositionX();
        int y = m_sprite->GetPositionY();
        int w = m_sprite->GetWidth();
        int h = m_sprite->GetHeight();
        if (nullptr != m_collider){
        m_collider->SetAbsolutePosition(x,y);
        m_collider->SetAbsoluteDimensions(w,h);
        }
    }
};

void GameEntity::Render()
{
    if (m_sprite != nullptr)
    {   
        m_sprite->Render(m_renderer);
    }
    if (m_collider != nullptr)
    {
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(m_renderer, &m_collider->GetColliderBoundingBox());
    }
};

void GameEntity::AddTexturedRectComponent(std::string spritepath){
    m_sprite = new TexturedRect(m_renderer, spritepath);
}

void GameEntity::AddTexturedRectComponent(std::string spritepath, int r, int g, int b){
    m_sprite = new TexturedRect(m_renderer, spritepath, r, g, b);
}

void GameEntity::AddCollider2D(){
    m_collider = new Collider2D();
}

TexturedRect& GameEntity::GetTexturedRect()
{
    return *m_sprite;
}

Collider2D& GameEntity::GetCollider2D()
{
    return *m_collider;
}

