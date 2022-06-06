#include "SDL.h"
#ifndef COLLIDER2D
#define COLLIDER2D

class Collider2D{
    public:
        Collider2D();
        ~Collider2D();
        SDL_bool IsColliding(Collider2D& collider);

    private:
        SDL_Rect m_colliderRect;

};

#endif