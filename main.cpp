#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    sf::Font font;
    win.create(sf::VideoMode(1920, 1080), "One for one");
    font.loadFromFile("assets/SummerPixel22Regular.ttf");
    GameState game(font);

    game.loop(win, evt);
    return 0;
}
