#include "ResManager.hpp"

ResourceManager::ResourceManager(){

}

ResourceManager::ResourceManager(ResourceManager const&){

}

//instantiate exactly 1 instance of out class
ResourceManager& ResourceManager::GetInstance(){
    static ResourceManager* s_instance = new ResourceManager;
    return *s_instance;
}

SDL_Surface* ResourceManager::GetSurface(std::string filepath){
    /* we will look through our m_surfaces
    which is an unordered map and see if a 
    file exists */
    auto search = m_surfaces.find(filepath);
    if(search != m_surfaces.end()){
        return m_surfaces[filepath];
    }
    else{
        SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
        m_surfaces.insert(std::make_pair(filepath, surface));
        return m_surfaces[filepath];
    }
}


