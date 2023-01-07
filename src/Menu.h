#ifndef MENU_H
#define MENU_H

// C++:
#include <iostream>

// LIB:
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using s_int = signed int;

class Menu {
private:
    int m_screen_width;
    int m_screen_height;

    sf::Font m_font;

    sf::Text m_title;
    std::vector<std::string> texts = { "Check status\n",
                                       "Add achievement\n",
                                       "Remove achievement\n",
                                       "Edit achievement\n",
                                       "Quit\n" };
    std::vector<sf::Text> m_entries;

public:
    s_int m_highlighted{0};

    Menu(int _screen_width, int _screen_height);

    void init(sf::RenderWindow &window);
    void processInput(sf::RenderWindow &window, sf::Event &event);
    void update(sf::RenderWindow &window);
};

#endif // MENU_H
