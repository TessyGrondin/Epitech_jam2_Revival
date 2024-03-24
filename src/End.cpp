#include "End.hpp"

End::End(bool state) :
m_sp("assets/end.png", 1920)
{
    if (!state)
        m_sp.setTextureRect({1920, 0, 1920, 1080});
}

void End::loop(sf::RenderWindow& win, sf::Event& evt)
{
    m_clock.restart();
    while (win.isOpen()) {
        while (win.pollEvent(evt))
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        if (m_clock.getElapsedTime().asSeconds() >= 5)
            return;
        win.clear();
        m_sp.draw(win);
        win.display();
    }
}
