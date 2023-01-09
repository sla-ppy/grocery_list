#ifndef MENU_H
#define MENU_H

// C++:
#include <iostream>

// LIB:
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

enum State {
    MAIN_MENU,
    STATUS,
    QUIT
};

class Menu {
private:
    int m_screen_width;
    int m_screen_height;

    sf::Font m_font;
    sf::Text m_title;
    // TODO: load them from a text file
    std::vector<std::string> m_options;
    std::vector<std::string> m_texts;
    std::vector<sf::Text> m_entries;

public:
    int m_highlighted{0};

    Menu(); // default ctor
    Menu(int _screen_width, int _screen_height, const std::vector<std::string> &_options);

    void update(sf::RenderWindow &window);
    void handle_event(const sf::Event &event);
};

#endif // MENU_H
