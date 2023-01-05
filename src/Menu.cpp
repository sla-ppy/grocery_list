#define ORANGE sf::Color(206, 122, 26, 19)

// HEADER:
#include "Menu.h"

using s_int = signed int;

Menu::Menu(int _screen_width, int _screen_height) {
    m_screen_width = _screen_width;
    m_screen_height = _screen_height;
}

sf::Font Menu::loadFont() {
    sf::Font font;
    if (!font.loadFromFile("./assets/font/IBMPlexMono-Regular.ttf")) {
        std::cerr << "ERROR: Font wasn't able to load." << '\n';
    }

    return font;
}

void Menu::init(sf::RenderWindow &window) {
    sf::Font font = loadFont();

    sf::Text title("Achievement:\n", font, 48);
    // fill text vector
    const auto entries = std::string("1. Check status\n") +
                         "2. Add achievement\n" +
                         "3. Remove achievement\n" +
                         "4. Edit achievement\n" +
                         "5. Quit";
    m_entries = { sf::Text(entries, font, 32) };

    // declare center text position
    sf::Vector2f center(m_screen_width / 2.0f, m_screen_height / 2.0f);

    // display main title
    sf::FloatRect title_text_bounds = title.getGlobalBounds();
    sf::Vector2f bounds_vector((title_text_bounds.left + title_text_bounds.width) / 2.0f,
                               (title_text_bounds.top + title_text_bounds.height) / 2.0f);
    title.setOrigin(bounds_vector);
    title.setFillColor(ORANGE);    // orange
    sf::Vector2f titlePos(center.x, center.y - 125.0f);
    title.setPosition(titlePos);
    window.draw(title);

    // display all texts inside vector
    float last_height{0};
    auto pos = center;
    for (auto &text: Menu::m_entries) {
        // center text
        sf::FloatRect bounds = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f(
                (bounds.left + bounds.width) / 2.0f,
                (bounds.top + bounds.height) / 2.0f));

        text.setFillColor(ORANGE);   // orange

        // line spacing
        pos.y += last_height;
        last_height = text.getGlobalBounds().height;
        text.setPosition(pos);

        window.draw(text);
    }

    window.display();
}
void Menu::processInput(sf::RenderWindow &window, sf::Event &event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // change menu highlight by one towards up
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // change menu highlight by one towards down
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        if (event.type == sf::Event::Closed) {
            // TODO: prompt the user if they really want to quit or not
            sf::Vector2f pos(255.0, 350.5);
            sf::RectangleShape rect(pos);
            sf::Vector2f size (310.0, 315.0);
            rect.setSize(size);
            window.draw(rect);

            for (auto &text : m_entries) {
                text.setFillColor(sf::Color(13, 123, 111, 19));
            }

            window.close();
        }
    };
}
void Menu::update(sf::RenderWindow &window) {
    // do the thing!!!!!!
}