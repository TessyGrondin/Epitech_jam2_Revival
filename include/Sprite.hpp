#pragma once
#include <SFML/Graphics.hpp>

class Sprite
{
protected:
    sf::Sprite      m_sprite;
    sf::Texture     m_texture;
    bool            m_visible = true;

public:
    Sprite();
    Sprite(std::string path);
    ~Sprite() = default;
    void draw(sf::RenderWindow& win);
    void set_position(sf::Vector2f position) {m_sprite.setPosition(position);}
    sf::Vector2f get_position() {return m_sprite.getPosition();}
    void move(float x, float y) {m_sprite.move(x, y);}
    void set_scale(sf::Vector2f scale) {m_sprite.setScale(scale);}
    void set_texture(std::string path);
    void set_visibility(bool visible) {m_visible = visible;}
    bool collide(Sprite other);
    sf::FloatRect get_global_bound() {return m_sprite.getGlobalBounds();}
    bool is_cliked();
};
