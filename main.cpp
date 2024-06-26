#include "include/Game.hpp"

int main(void)
{
    sf::RenderWindow win;
    sf::Event evt;
    sf::Font font;
    win.create(sf::VideoMode(1920, 1080), "One for one");
    font.loadFromFile("assets/SummerPixel22Regular.ttf");
    Menu menu(font);
    menu.loop(win, evt);
    Dialogue dial(font);
    dial.loop(win, evt);
    GameState game(font);
    End res(game.loop(win, evt), font);
    res.loop(win, evt);
    return 0;
}
