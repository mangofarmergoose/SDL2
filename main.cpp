// C++ Standard Libraries
#include <iostream>
#include <string>
#include <vector>
#include <memory>
// Third Party
#include "SDL.h"
#include "SDLApp.hpp"
#include "TexturedRect.hpp"
#include "AnimatedSprite.hpp"
#include "GameEntity.hpp"
#include "Collider2D.hpp"
SDLApp *app;
GameEntity *object1;
GameEntity *object2;

void HandleEvents()
{
    SDL_Event event;
    // (1) Handle Input
    // Start our event loop
    while (SDL_PollEvent(&event))
    {
        // Handle each specific event
        if (event.type == SDL_QUIT)
        {
            app->StopAppLoop();
        }
        // Detect collision from our two shapes if mouse
        // button is pressed
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if(object2->GetCollider2D().IsColliding(object1->GetCollider2D())){
                std::cout << "is colliding" << std::endl;
            }
            else{
                std::cout << "not colliding" << std::endl;
            }
        }
    }
}

void HandleUpdate(){
    object1->Update();
    object2->Update();
}

void HandleRendering()
{
    // Render our objects
    object1->GetTexturedRect().SetPosition(app->GetMouseX(), app->GetMouseY());
    object1->GetTexturedRect().SetDimension(100, 100);

    static int posX;
    static int posY;
    static bool up = true;
    static bool right = true;
    if(up){
        posY--;
    }
    if(!up)
    {
        posY++;
    }
    if(right){
        posX++;
    }
    if(!right)
    {
        posX--;
    }
    if(posX > app->GetWindowWidth()){
        right = false;
    }
    else if(posX <= 0){
        right = true;
    }
    if(posY <= 0){
        up = false;
    }
    else if(posY > app->GetWindowHeight()){
        up = true;
    }
    /* std::cout << posX << ", " << posY << std::endl; */
    object2->GetTexturedRect().SetPosition(posX, posY);
    object2->GetTexturedRect().SetDimension(100, 100);

    object1->Render();
    object2->Render();

}

int main()
{
    // Setup the SDLApp
    const char *title = "New SDL2 Abstraction";
    app = new SDLApp(title, 20, 20, 640, 480);
    app->SetMaxFrameRate(8);
    // Create any objects in our scene
    object1 = new GameEntity(app->GetRenderer(), "./images/wallpaper.bmp");
    object2 = new GameEntity(app->GetRenderer(), "./images/wallpaper.bmp");
    // Set callback functions
    app->SetEventCallback(HandleEvents);
    app->SetUpdateCallback(HandleUpdate);
    app->SetRenderCallback(HandleRendering);
    // Run our application until terminated
    app->RunLoop();

    // Clean up our application
    delete app;
    delete object1;
    delete object2;

    return 0;
}
