#include "Engine.hpp"

class Hole
{
private:
    SpriteSheet m_hole;
    Sprite      m_mole;
    TextBox     m_box;
    Sprite      drop1;
    Sprite      drop2;
public:
    Hole(sf::Font&);
    ~Hole() = default;
};

