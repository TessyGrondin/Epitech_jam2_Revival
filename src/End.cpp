#include "End.hpp"

End::End(bool state, sf::Font& font) :
m_sp("assets/end.png", 1920),
m_box("", font, "assets/button.png"),
m_name("", font, "assets/button.png")
{
    m_box.setTextureRect({0, 0, 128, 32});
    m_name.setTextureRect({0, 0, 128, 32});
    m_box.set_scale({15, 5});
    m_box.setposition({0, 850}, {50, 65});
    m_name.set_scale({2, 2});
    m_name.setposition({30, 786}, {20, 10});
    if (!state) {
        m_sp.setTextureRect({1920, 0, 1920, 1080});
        load("config/dialogue_3.txt");
    } else {
        load("config/dialogue_2.txt");
    }
}

void End::load(std::string str) {
    std::fstream source_file;
    std::string line;
    source_file.open(str);
    if (source_file.is_open()) {
        while (source_file.good()) {
            std::getline(source_file, line);
            m_src.push_back(line);
        }
    }
    source_file.close();
}

void End::update_dialogue()
{
    m_position++;
    int pos = m_position - 1;
    if (pos >= (int)m_src.size())
        return;
    m_name.set_visibility(true);
    std::string line = m_src[pos];
    int i = line.find(';');
    m_name.set_string(line.substr(0, i));
    m_box.set_string(line.substr(i + 1));
    if (m_name.get_string() == "")
        m_name.set_visibility(false);
    if (m_name.get_string() == "Op")
        m_name.setposition({150, 786}, {20, 10});
    else
        m_name.setposition({1500, 786}, {20, 10});
}

void End::loop(sf::RenderWindow& win, sf::Event& evt)
{
    int size = m_src.size();
    update_dialogue();
    while (win.isOpen()) {
        while (win.pollEvent(evt))
            if (evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        if (m_clock.getElapsedTime().asSeconds() >= 2.5) {
            update_dialogue();
            m_clock.restart();
        }
        if (m_position > size)
            return;
        win.clear();
        m_sp.draw(win);
        m_box.draw(win);
        m_name.draw(win);
        win.display();
    }
}
