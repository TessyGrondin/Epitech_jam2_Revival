#include "../include/Sound.hpp"

Sound::Sound(std::string src) {
    m_buffer.loadFromFile(src);
    m_sound.setBuffer(m_buffer);
}

bool Sound::is_playing() {
    if (m_sound.getStatus() == sf::Sound::Playing)
        return true;
    return false;
}
