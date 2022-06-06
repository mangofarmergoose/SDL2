#include <iostream>
#include <unordered_map>
#include <string>
#include <SDL.h>
#ifndef RESMANAGER
#define RESMANAGER

class ResourceManager{
    private:
        ResourceManager();
        ResourceManager(ResourceManager const&);
        //copy assignment
        std::unordered_map<std::string, SDL_Surface*> m_surfaces;
    public:
        static ResourceManager& GetInstance();
        SDL_Surface* GetSurface(std::string filepath);

};

#endif