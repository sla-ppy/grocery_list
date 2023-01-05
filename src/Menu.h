#ifndef MENU_H
#define MENU_H

// C++:
#include <iostream>

// LIB:
#include "SFML/Graphics.hpp"

class Menu {
private:
    int m_screen_width;
    int m_screen_height;
    std::vector<sf::Text> m_entries;

public:
    sf::Font loadFont();

    Menu(int _screen_width, int _screen_height);

    void init(sf::RenderWindow &window);
    void processInput(sf::RenderWindow &window, sf::Event &event);
    void update(sf::RenderWindow &window);
};

#endif // MENU_H
