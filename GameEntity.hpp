#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <string.h>
#include "SDL.h"
#include "TexturedRect.hpp"
#include "Collider2D.hpp"

class GameEntity{
    public:
        GameEntity();
        GameEntity(SDL_Renderer* renderer);
        ~GameEntity();
        void Update();
        void Render();
        //adding components
        void AddTexturedRectComponent(std::string spritepath);
        void AddTexturedRectComponent(std::string spritepath, int r, int g, int b);
        void AddCollider2D();
        //retrieve components
        TexturedRect& GetTexturedRect();
        Collider2D& GetCollider2D();
        

    private:
        TexturedRect* m_sprite;   
        SDL_Renderer* m_renderer;   
        Collider2D* m_collider;  
};


#endif