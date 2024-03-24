#include "Menu.hpp"

Menu::Menu(sf::Font& font) :
m_sp("assets/menu.png", 1920), m_start_text("", font, "assets/button.png"), m_quit_text("", font, "assets/button.png")
{
    m_sp.setTextureRect({0, 0, 1920, 1080});

    m_start_text.set_string("Start");
    m_start_text.set_scale({1.5, 1.5});
    m_start_text.set_character_size(32);
    m_start_text.set_color(sf::Color::Black);
    m_start_text.setTextureRect({0, 0, 128, 32});
    m_start_text.setposition({1920 / 2 - 32, 1080 / 2 - 16}, {32 / 2, 0});

    m_quit_text.set_string("Quit");
    m_quit_text.set_scale({1.5, 1.5});
    m_quit_text.set_character_size(32);
    m_quit_text.set_color(sf::Color::Black);
    m_quit_text.setTextureRect({0, 0, 128, 32});
    m_quit_text.setposition({1920 / 2 - 32, 1080 / 2 + 32}, {32 / 2, 0});
}

int Menu::button_pressed(sf::Event& evt, sf::Mouse::Button button, sf::RenderWindow& win)
{
    if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == button) {
        if (m_start_text.is_cliked(win))
            return 1;
        if (m_quit_text.is_cliked(win))
            return 2;
    }
    return 0;
}

void Menu::loop(sf::RenderWindow& win, sf::Event& evt)
{
    m_clock.restart();
    while (win.isOpen()) {
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            switch (button_pressed(evt, sf::Mouse::Left, win)) {
                case 1:
                    return;
                case 2:
                    exit(0);
                default:
                    break;
            }
        }
        win.clear();
        m_sp.draw(win);
        m_start_text.draw(win);
        m_quit_text.draw(win);
        win.display();
    }
}
