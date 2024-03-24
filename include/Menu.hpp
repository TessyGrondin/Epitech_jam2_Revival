#pragma once
#include "Engine.hpp"

class Menu
{
private:
    SpriteSheet m_sp;
    sf::Clock   m_clock;
    TextBox     m_start_text;
    TextBox     m_quit_text;
public:
    Menu(sf::Font& font);
    ~Menu() = default;
    void loop(sf::RenderWindow& win, sf::Event& evt);
    int button_pressed(sf::Event& evt, sf::Mouse::Button button, sf::RenderWindow& win);

};
