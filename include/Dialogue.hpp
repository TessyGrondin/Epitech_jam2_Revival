#pragma once
#include "Engine.hpp"

class Dialogue
{
private:
    Sprite                 m_sp;
    sf::Clock                   m_clock;
    TextBox                     m_box;
    TextBox                     m_name;
    std::vector<std::string>    m_src;
    Sprite                      m_op;
    Sprite                      m_en;
    int                         m_position = 0;
public:
    Dialogue(sf::Font& font);
    ~Dialogue() = default;
    void loop(sf::RenderWindow& win, sf::Event& evt);
    void load(std::string);
    void update_dialogue();
};
