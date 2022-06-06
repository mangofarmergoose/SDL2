#include "SDL.h"
#ifndef COLLIDER2D
#define COLLIDER2D

class Collider2D{
    public:
        Collider2D();
        ~Collider2D();
        SDL_bool IsColliding(Collider2D& collider);
        void SetAbsolutePosition(int x, int y);
        void SetAbsoluteDimensions(int w, int h);
        SDL_Rect& GetColliderBoundingBox();

    private:
        SDL_Rect m_colliderRect;

};

#endif