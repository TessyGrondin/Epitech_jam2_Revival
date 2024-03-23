#pragma once
#include "Engine.hpp"

class GameState
{
private:
    SpriteSheet m_player;
    Sprite      m_rigor_droplet;
    Sprite      m_excellency_droplet;
    Sprite      m_courage_droplet;
    Sprite      m_background;
    int         m_rigor_count;
    int         m_excellency_count;
    int         m_courage_count;
    TextBox     m_rigor_display;
    TextBox     m_excellency_display;
    TextBox     m_courage_display;

public:
    GameState(sf::Font& font);
    ~GameState() = default;
    void loop(sf::RenderWindow&, sf::Event);
    void draw(sf::RenderWindow&);
    void animate();
};
