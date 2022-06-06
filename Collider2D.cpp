#include "Collider2D.hpp"

Collider2D::Collider2D(){

}

Collider2D::~Collider2D(){

}

SDL_bool Collider2D::IsColliding(Collider2D& collider){
    const SDL_Rect tmp = collider.m_colliderRect;
    return SDL_HasIntersection(&m_colliderRect, &tmp);
}