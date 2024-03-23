#pragma once
#include "SFML/Audio.hpp"

class Sound {
private:
    sf::Sound       m_sound;
    sf::SoundBuffer m_buffer;

public:
    Sound(std::string src);
    ~Sound() = default;
    void play() {m_sound.play();}
    bool is_playing();
};
