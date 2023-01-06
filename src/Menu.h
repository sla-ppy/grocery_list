#ifndef MENU_H
#define MENU_H

// C++:
#include <iostream>

// LIB:
#include "SFML/Graphics.hpp"

using s_int = signed int;

class Menu {
private:
    int m_screen_width;
    int m_screen_height;

    // FIXME: m_entries only stores a single object (all of the texts in a clump), perhaps its better to store them individually
    sf::Font m_font;
    std::vector<std::string> texts = { "Check status\n",
                                       "Add achievement\n",
                                       "Remove achievement\n",
                                       "Edit achievement\n",
                                       "Quit\n" };
    std::vector<sf::Text> m_entries;
    s_int m_highlighted{0};

public:
    Menu(int _screen_width, int _screen_height);

    void init(sf::RenderWindow &window);
    void processInput(sf::RenderWindow &window, sf::Event &event);
    void update(sf::RenderWindow &window);
};

#endif // MENU_H
