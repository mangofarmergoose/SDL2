#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <string.h>
#include "SDL.h"
#include "TexturedRect.hpp"
#include "Collider2D.hpp"

class GameEntity{
    public:
        GameEntity(SDL_Renderer* renderer, std::string filepath);
        ~GameEntity();
        void Update();
        void Render();
        TexturedRect& GetTexturedRect();
        Collider2D& GetCollider2D();
        

    private:
        TexturedRect* m_sprite;   
        SDL_Renderer* m_renderer;   
        Collider2D* m_collider;  
};


#endif