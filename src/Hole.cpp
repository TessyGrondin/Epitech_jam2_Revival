#include "Hole.hpp"

Hole::Hole(sf::Font& fn) :
m_hole("assets/hole.png", 160),
m_box("What do you\nwant to trade ?", fn, "")
{
    srand(std::time(0));
    int r = rand() % 3;
    int d1 = 0;
    int d2 = 2;
    int pos1 = rand() % (1920 * 3 - 160);
    int pos2 = rand() % (1080 * 3 - 160);
    std::vector<std::string> sp = {"assets/Rigor_mole.png", "assets/Excellency_mole.png", "assets/Courage_mole.png"};
    std::vector<std::string> dr = {"assets/Rigor_droplet.png", "assets/Excellency_droplet.png", "assets/Courage_droplet.png"};
    m_mole.set_texture(sp[r]);
    if (r == 0)
        d1 = 1;
    else if (r == 2)
        d2 = 1;
    m_drop1.set_texture(dr[d1]);
    m_drop2.set_texture(dr[d2]);
    m_hole.set_position({(float)pos1, (float)pos2});
    m_mole.set_scale({2, 2});
    m_mole.set_position({(float)(pos1 + 53), (float)(pos2 + 32)});
    m_hole.add_animation("break", {0,1,2});
    m_hole.set_loop("break", false);
    m_box.setposition({(float)(pos1), (float)(pos2 - 32)});
}

void Hole::move(float x, float y)
{
    m_hole.move(x, y);
    m_mole.move(x, y);
    // m_drop1.move(x, y);
    // m_drop2.move(x, y);
    m_box.move(x, y);
    m_box.setposition(m_box.get_position());
}

void Hole::draw(sf::RenderWindow& win)
{
    m_hole.draw(win);
    if (m_visible) {
        m_mole.draw(win);
        m_box.draw(win);
    }
}
