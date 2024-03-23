#include "Engine.hpp"

class Hole
{
private:
    SpriteSheet m_hole;
    Sprite      m_mole;
    TextBox     m_box;
    Sprite      m_drop1;
    Sprite      m_drop2;
    bool        m_visible = false;
public:
    Hole(sf::Font&);
    ~Hole() = default;
    void draw(sf::RenderWindow&);
    void move(float x, float y);
    SpriteSheet get_hole() {return m_hole;}
    void set_visible(bool v) {m_visible = v;}
    void break_ground() {m_hole.play_animation("break");}
};

