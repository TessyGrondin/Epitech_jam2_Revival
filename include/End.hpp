#pragma once
#include "Engine.hpp"

class End
{
private:
    SpriteSheet m_sp;
    sf::Clock   m_clock;
public:
    End(bool state);
    ~End() = default;
    void loop(sf::RenderWindow& win, sf::Event& evt);
};
