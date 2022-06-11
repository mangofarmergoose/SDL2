#ifndef SOUND_HPP
#define SOUND_HPP
#include <string>
#include "SDL.h"

class Sound{
public:
    Sound(std::string filepath);
    ~Sound();
    void PlaySound();
    void StopSound();
    void SetupDevice();
private:
    SDL_AudioDeviceID m_device;
    // Properties of the Wave File that is loaded
    SDL_AudioSpec m_audioSpec;
    Uint8*        m_waveStart;
    Uint32        m_waveLength;
};

#endif