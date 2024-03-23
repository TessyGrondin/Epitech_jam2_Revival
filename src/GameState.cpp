#include "GameState.hpp"

GameState::GameState(sf::Font& font) :
m_player("assets/player.png", 32),
m_rigor_droplet("assets/Rigor_droplet.png"),
m_excellency_droplet("assets/Excellency_droplet.png"),
m_courage_droplet("assets/Courage_droplet.png"),
m_background("assets/background.png"),
m_rigor_display("00", font, ""),
m_excellency_display("00", font, ""),
m_courage_display("00", font, "")
{
    srand(std::time(0));
    m_rigor_count = rand() % (61 + 1);
    m_excellency_count = rand() % (61 - m_rigor_count + 1);
    m_courage_count = 60 - m_rigor_count - m_excellency_count;
    m_rigor_display.set_string(std::to_string(m_rigor_count));
    m_excellency_display.set_string(std::to_string(m_excellency_count));
    m_courage_display.set_string(std::to_string(m_courage_count));
    m_player.set_position({500, 500});
    m_rigor_droplet.set_scale({3, 3});
    m_excellency_droplet.set_scale({3, 3});
    m_courage_droplet.set_scale({3, 3});
    m_rigor_display.setposition({90, 60});
    m_excellency_droplet.set_position({110, 0});
    m_excellency_display.setposition({200, 60});
    m_courage_droplet.set_position({230, 0});
    m_courage_display.setposition({320, 60});
    m_player.set_origin({32 / 2, 32 / 2});
    m_player.add_animation("up", {13, 14, 15, 16});
    m_player.add_animation("down", {3, 4, 5, 6});
    m_player.add_animation("side", {8, 9, 10, 11});
    m_player.add_animation("hit", {12});
    m_player.set_scale({4, 4});
}

void GameState::animate()
{
    std::vector<std::string> anim = {"", "up", "down", "side"};
    int current = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        current = 1;
        m_background.move(0, 1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        current = 2;
        m_background.move(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_player.set_scale({4, 4});
        current = 3;
        m_background.move(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_player.set_scale({-4, 4});
        current = 3;
        m_background.move(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        m_player.play_animation("hit");
    m_player.play_animation(anim[current]);
}

void GameState::draw(sf::RenderWindow& win)
{
    m_background.draw(win);
    m_rigor_display.draw(win);
    m_excellency_display.draw(win);
    m_courage_display.draw(win);
    m_rigor_droplet.draw(win);
    m_excellency_droplet.draw(win);
    m_courage_droplet.draw(win);
    m_player.draw(win);
}

void GameState::loop(sf::RenderWindow& win, sf::Event evt)
{
    while (win.isOpen()) {
        while (win.pollEvent(evt))
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        win.clear(sf::Color::Blue);
        draw(win);
        animate();
        m_player.play_animation("idle");
        win.display();
    }
}
