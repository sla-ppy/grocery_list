#define menu_enter "./assets/sound/sound.wav"
#define menu_select "./assets/sound/finalized.wav"

// C++:
#include <iostream>
#include <fstream>

// LIB:
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// HEADER:
#include "List.h"
#include "Menu.h"

int main() {
    // init window
    int screen_width{1920};
    int screen_height{1080};

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Achievements");

    State state = State::MAIN_MENU;

    Menu menu;

    std::vector<std::string> options;
    std::ifstream file("./assets/menu_input.csv");

    if (file.is_open()) {
        std::string line;
        int i{0};
        while (getline(file, line, ';')) {
            options.emplace_back(line);
            // FIXME: get input based on keyword and dependant on program state
            // CONTINUE
            i++;
        }
    } else {
        std::cerr << "ERROR: File didn't open successfully when importing from menu_input.csv" << '\n';
    }
    file.close();

    while (window.isOpen()) {
        sf::Event event{};

        switch (state) {
            case State::MAIN_MENU:
                menu = Menu(screen_width, screen_height, options);
                break;
            case State::STATUS:
                menu = Menu(screen_width, screen_height, options);
                break;
            case State::QUIT:
                menu = Menu(screen_width, screen_height, options);
                break;
        }

        menu.update(window);

        // controls
        while (window.pollEvent(event)) {
            // TODO: fix menu.m_highlighted being public
            // quit
            if (event.type == sf::Event::Closed
                || event.key.code == sf::Keyboard::Escape
                || event.key.code == sf::Keyboard::Enter && menu.m_highlighted == 4) {
                state = State::QUIT;
            }

            switch (state) {
                case State::MAIN_MENU:
                    menu.handle_event(event);
                    break;
                case State::STATUS:
                    menu.handle_event(event);
                    break;
                case State::QUIT:
                    window.close();
                    break;
            }
        }
    }

    // std::string file_path("./assets/data.csv");
    // List list(file_path);

    return 0;
}