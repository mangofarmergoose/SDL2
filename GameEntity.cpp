#include "GameEntity.hpp"
#include <iostream>
GameEntity::GameEntity(){
    m_sprite = nullptr;
}

GameEntity::GameEntity(SDL_Renderer* renderer){
    m_renderer = renderer;
    m_sprite = nullptr;
}

GameEntity::~GameEntity(){
    if (m_sprite != nullptr)
    {
        delete m_sprite;
    }
    for (int i = 0; i < m_colliders.size(); ++i)
    {
        delete m_colliders[i];
    }
};

void GameEntity::Update(){
    //Update the position of collider to be same as m_sprite
    /* if(m_sprite != nullptr){
        int x = m_sprite->GetPositionX();
        int y = m_sprite->GetPositionY();
        int w = m_sprite->GetWidth();
        int h = m_sprite->GetHeight();
        if (nullptr != m_collider){
        m_collider->SetAbsolutePosition(x,y);
        m_collider->SetAbsoluteDimensions(w,h);
        }
    } */
};

void GameEntity::Render()
{
    if (m_sprite != nullptr)
    {   
        m_sprite->Render(m_renderer);
    }
    for (int i=0; i<m_colliders.size(); ++i){
        if (m_colliders[i] != nullptr)
        {
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(m_renderer, &m_colliders[i]->GetColliderBoundingBox());
        }
    }
};

void GameEntity::AddTexturedRectComponent(std::string spritepath){
    m_sprite = new TexturedRect(m_renderer, spritepath);
}

void GameEntity::AddTexturedRectComponent(std::string spritepath, int r, int g, int b){
    m_sprite = new TexturedRect(m_renderer, spritepath, r, g, b);
}

void GameEntity::AddCollider2D(){
    m_colliders.push_back(new Collider2D);
}

TexturedRect& GameEntity::GetTexturedRect()
{
    return *m_sprite;
}

Collider2D& GameEntity::GetCollider2D(int idx)
{
    return *m_colliders[idx];
}

