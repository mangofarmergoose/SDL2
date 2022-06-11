//To Compile
//clang++ -std=c++17 -D MAC *.cpp -I/usr/local/include -o prog `sdl2-config --cflags --libs` -lSDL2_ttf
#include <iostream>
#include <string>
#include <vector>
// Third Party
#include "SDL.h"
#include "SDLApp.hpp"
#include "TexturedRect.hpp"
#include "AnimatedSprite.hpp"
#include "GameEntity.hpp"
#include "Collider2D.hpp"
#include "Sound.hpp"
#include "DynamicText.hpp"
SDLApp *app;
GameEntity *object1;
GameEntity *object2;
Sound* CollisionSound;
DynamicText* text;


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

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (object2->GetCollider2D(0).IsColliding(object1->GetCollider2D(0)))
            {
                std::cout << "Is colliding with hitbox" << std::endl;
                CollisionSound->PlaySound();
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

    object1->GetTexturedRect().SetPosition(app->GetMouseX(), app->GetMouseY());
    object1->GetTexturedRect().SetDimension(100, 100);

    static int posX = 0;
    static int posY = 0;
    static bool up = true;
    static bool right = true;

    if (up)
    {
        posY--;
    }
    else
    {
        posY++;
    }

    if (right)
    {
        posX++;
    }
    else
    {
        posX--;
    }

    if (posX > app->GetWindowWidth())
    {
        right = false;
    }
    else if (posX < 0)
    {
        right = true;
    }

    if (posY < 0)
    {
        up = false;
    }
    else if (posY > app->GetWindowHeight())
    {
        up = true;
    }

    object2->GetTexturedRect().SetPosition(posX, posY);
    object2->GetTexturedRect().SetDimension(100, 100);

    object1->GetCollider2D(0).SetAbsolutePosition(object1->GetTexturedRect().GetPositionX(),
    object1->GetTexturedRect().GetPositionY());
    object1->GetCollider2D(0).SetAbsoluteDimensions(object1->GetTexturedRect().GetWidth(),
    object1->GetTexturedRect().GetHeight());

    object2->GetCollider2D(0).SetAbsolutePosition(object2->GetTexturedRect().GetPositionX(),
    object2->GetTexturedRect().GetPositionY());
    object2->GetCollider2D(0).SetAbsoluteDimensions(object2->GetTexturedRect().GetWidth(),
    object2->GetTexturedRect().GetHeight());
}

void HandleRendering()
{
    // Render our objects
    object1->Render();
    object2->Render();
    //Render Text
    text = new DynamicText("./fonts/8bitOperatorPlus8-Regular.ttf", 16);
    text->DrawText(app->GetRenderer(), "Goose", 0, 0 ,100, 50);
    delete text;
}

int main()
{
    // Setup the SDLApp
    const char *title = "New SDL2 Abstraction";
    app = new SDLApp("SDL2", 20, 20, 640, 480);
    app->SetMaxFrameRate(8);
    app->InitAudio();
    app->InitDynamicText();
    
    // Create any objects in our scene
    
    object1 = new GameEntity(app->GetRenderer());
    object1->AddTexturedRectComponent("./images/kong.bmp", 0xFF, 0x00, 0xFF);
    object1->AddCollider2D();
    object1->AddCollider2D();
    
    object2 = new GameEntity(app->GetRenderer());
    object2->AddTexturedRectComponent("./images/kong.bmp");
    object2->AddCollider2D();

    CollisionSound = new Sound("/sounds/collide.wav");
    CollisionSound->SetupDevice();
    
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
    delete CollisionSound;

    return 0;
}
