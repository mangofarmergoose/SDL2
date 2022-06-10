#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <string.h>
#include <vector>
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
        Collider2D& GetCollider2D(int idx);
        

    private:
        TexturedRect* m_sprite;   
        SDL_Renderer* m_renderer;   
        std::vector<Collider2D*> m_colliders;  
};


#endif