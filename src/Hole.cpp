#include "Hole.hpp"

Hole::Hole(sf::Font& fn, int mole_color) :
m_hole("assets/hole.png", 160),
m_box("What do you\nwant to trade ?", fn, "")
{
    m_col1 = 0;
    m_col2 = 2;
    m_color = mole_color;
    std::vector<std::string> sp = {"assets/Rigor_mole.png", "assets/Excellency_mole.png", "assets/Courage_mole.png"};
    std::vector<std::string> dr = {"assets/Rigor_droplet.png", "assets/Excellency_droplet.png", "assets/Courage_droplet.png"};
    m_mole.set_texture(sp[mole_color]);
    if (mole_color == 0)
        m_col1 = 1;
    else if (mole_color == 2)
        m_col2 = 1;
    m_drop1.set_texture(dr[m_col1]);
    m_drop2.set_texture(dr[m_col2]);
    m_mole.set_scale({2, 2});
    m_hole.add_animation("break", {0, 1, 2});
    m_hole.set_loop("break", false);
    m_drop1.set_scale({2, 2});
    m_drop2.set_scale({2, 2});
}

void Hole::break_ground()
{
    m_hole.play_animation("break");
    if (m_hole.get_frame() == 3)
        m_destroyed = true;
}

int Hole::is_click(sf::RenderWindow& win)
{
    if (m_drop1.is_cliked(win))
        return m_col1;
    if (m_drop2.is_cliked(win))
        return m_col2;
    return -1;
}

void Hole::move(float x, float y)
{
    m_hole.move(x, y);
    m_mole.move(x, y);
    m_drop1.move(x, y);
    m_drop2.move(x, y);
    m_box.move(x, y);
    m_box.setposition(m_box.get_position());
}

void Hole::draw(sf::RenderWindow& win)
{
    m_hole.draw(win);
    if (m_visible) {
        m_mole.draw(win);
        m_box.draw(win);
        m_drop1.draw(win);
        m_drop2.draw(win);
    }
}

void Hole::set_position(sf::Vector2f pos)
{
    m_hole.set_position(pos);
    m_mole.set_position({(float)(pos.x + 53), (float)(pos.y + 32)});
    m_box.setposition({(float)(pos.x), (float)(pos.y - 32)});
    m_drop1.set_position({(float)(pos.x + 16), (float)(pos.y + 32)});
    m_drop2.set_position({(float)(pos.x + 90), (float)(pos.y + 32)});
}
