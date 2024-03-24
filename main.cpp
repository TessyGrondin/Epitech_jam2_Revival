#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    sf::Font font;
    win.create(sf::VideoMode(1920, 1080), "One for one");
    font.loadFromFile("assets/SummerPixel22Regular.ttf");
    GameState game(font);

    bool res = game.loop(win, evt);
    if (res)
        std::cout << "I win" << std::endl;
    else
        std::cout << "I lost" << std::endl;
    return 0;
}
