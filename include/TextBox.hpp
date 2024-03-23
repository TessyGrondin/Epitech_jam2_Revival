#pragma once
#include "Sprite.hpp"

class TextBox : public Sprite
{
protected:
    sf::Text    m_text;
    std::string m_string;
    bool        m_drawable = true;
public:
    TextBox();
    TextBox(std::string str, sf::Font&, std::string path);
    ~TextBox() = default;
    void draw(sf::RenderWindow& win);
    void setposition(sf::Vector2f vec, sf::Vector2f padding);
    void set_string(std::string);
    std::string get_string() {return m_string;};
    void load(std::string str, sf::Font&, std::string path);
    sf::Text get_text() {return m_text;}
    void set_character_size(int size) {m_text.setCharacterSize(size);}
};
