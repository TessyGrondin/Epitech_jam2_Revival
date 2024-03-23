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
    bool        m_destroyed = false;
    int         m_col1;
    int         m_col2;
    int         m_color;
public:
    Hole(sf::Font&, int mole_color);
    ~Hole() = default;
    void draw(sf::RenderWindow&);
    void move(float x, float y);
    SpriteSheet get_hole() {return m_hole;}
    void set_visible(bool v) {m_visible = v;}
    void set_destroyed(bool v) {m_destroyed = v;}
    bool get_state() {return m_destroyed;}
    bool get_visible() {return m_visible;}
    void break_ground();
    int is_click(sf::RenderWindow& win);
    int get_color() {return m_color;}
    void set_position(sf::Vector2f);
};
