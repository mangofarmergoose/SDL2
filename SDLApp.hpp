#ifndef SDLAPP_HPP
#define SDLAPP_HPP

#include <functional>
#include "SDL.h"
class SDLApp{
    public:
        // Constructor
        SDLApp(const char* title,int x, int y, int w, int h);
        // Destructor
        ~SDLApp();
        // Handle Events
        void SetEventCallback(std::function<void(void)> func);
        // Handle Update
        void SetUpdateCallback(std::function<void(void)> func);
        // Handle Render
        void SetRenderCallback(std::function<void(void)> func);
        // Loop our application
        void RunLoop();
        // Set max render rate of each frame
        void SetMaxFrameRate(int framerate);
        // Retrive the renderer
        SDL_Renderer* GetRenderer() const;
        // Return mouse positions
        int GetMouseX();
        int GetMouseY();
        // Return window dimensions
        int GetWindowHeight();
        int GetWindowWidth();
        // Stop the main loop of our application
        void StopAppLoop();

    private:
            // Pointer to our SDL Window
            SDL_Window* m_window=nullptr;
            // Pointer to our SDL renderer
            SDL_Renderer* m_renderer = nullptr;
            // Infinite loop for our application
            bool m_gameIsRunning = true;
            // Store mouse Coordinates by default
            int m_mouseX;
            int m_mouseY;
            // Store window width and height
            int m_width;
            int m_height;
            // Set max frame cap
            int m_maxFrameRate;    
            // Store our callback functions
            //function pointers
            std::function<void(void)> m_EventCallback;
            std::function<void(void)> m_UpdateCallback;
            std::function<void(void)> m_RenderCallback;
};

#endif