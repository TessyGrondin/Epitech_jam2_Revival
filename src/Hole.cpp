#include "Hole.hpp"

Hole::Hole(sf::Font& fn) :
m_hole("assets/hole.png", 160),
m_box("What do you want to trade ?", fn, "")
{
    int r = rand() % 3;
    std::vector<std::string> sp = {"assets/Rigor_mole.png", "assets/Excellency_mole.png", "assets/Courage_mole.png"};
    std::vector<std::string> dr = {"assets/Rigor_droplet.png", "assets/Excellency_droplet.png", "assets/Courage_droplet.png"};
    m_mole = Sprite(sp[r]);
}
