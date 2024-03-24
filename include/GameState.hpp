#pragma once
#include "Engine.hpp"
#include "Hole.hpp"

class GameState
{
private:
    SpriteSheet                   m_player;
    Sprite                        m_rigor_droplet;
    Sprite                        m_excellency_droplet;
    Sprite                        m_courage_droplet;
    Sprite                        m_background;
    int                           m_rigor_count;
    int                           m_excellency_count;
    int                           m_courage_count;
    TextBox                       m_rigor_display;
    TextBox                       m_excellency_display;
    TextBox                       m_courage_display;
    std::vector<shared_ptr<Hole>> m_holes;
    int                           m_anim = 0;

public:
    GameState(sf::Font& font);
    ~GameState() = default;
    bool loop(sf::RenderWindow&, sf::Event);
    void draw(sf::RenderWindow&);
    void animate();
    void interact(sf::RenderWindow& win);
    bool update(int given, int taken);
    void create_mole_array(sf::Font& font);
    bool lose_condition();
};
