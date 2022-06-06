#include "GameEntity.hpp"

GameEntity::GameEntity(SDL_Renderer *renderer, std::string filepath)
{
    m_sprite = nullptr;
    m_renderer = renderer;
    m_sprite = new TexturedRect(m_renderer, filepath);
    m_collider = new Collider2D();
};

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

};

void GameEntity::Render()
{
    if (m_sprite != nullptr)
    {
        m_sprite->Render(m_renderer);
    }
    if (m_collider != nullptr)
    {
        
    }
};
TexturedRect& GameEntity::GetTexturedRect()
{
    return *m_sprite;
}

Collider2D& GameEntity::GetCollider2D()
{
    return *m_collider;
}


