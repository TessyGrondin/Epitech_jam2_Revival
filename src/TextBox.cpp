#include "../include/TextBox.hpp"

TextBox::TextBox()
{
}

TextBox::TextBox(std::string str, sf::Font& font, std::string path) {
    m_string = str;
    m_text.setFont(font);
    m_text.setFillColor(sf::Color::Black);
    m_text.setOutlineThickness(1);
    m_text.setOutlineColor(sf::Color::White);
    m_text.setString(m_string);
    if (!path.empty())
        set_texture(path);
    else
        m_drawable = false;
    m_sprite.setScale({0.5, 0.5});
}

void TextBox::load(std::string str, sf::Font& font, std::string path)
{
    m_string = str;
    m_text.setFont(font);
    m_text.setFillColor(sf::Color::Black);
    m_text.setOutlineThickness(1);
    m_text.setOutlineColor(sf::Color::White);
    m_text.setString(m_string);
    if (!path.empty())
        set_texture(path);
    else
        m_drawable = false;
    m_sprite.setScale({0.5, 0.5});
}

void TextBox::draw(sf::RenderWindow& win) {
    if (m_drawable)
        win.draw(m_sprite);
    win.draw(m_text);
}

void TextBox::setposition(sf::Vector2f vec, sf::Vector2f padding = {0, 0}) {
    m_sprite.setPosition(vec);
    vec.x += padding.x;
    vec.y += padding.y;
    m_text.setPosition(vec);
}

void TextBox::set_string(std::string str) {
    m_string = str;
    m_text.setString(str);
}
