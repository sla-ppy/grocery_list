#define ORANGE sf::Color(206, 122, 26, 19)

// HEADER:
#include "Menu.h"

using s_int = signed int;

sf::Font Menu::loadFont() {
    sf::Font font;
    if (!font.loadFromFile("./assets/font/IBMPlexMono-Regular.ttf")) {
        std::cerr << "ERROR: Font wasn't able to load." << '\n';
    }

    return font;
}

Menu::Menu(int _screen_width, int _screen_height) {
    m_screen_width = _screen_width;
    m_screen_height = _screen_height;

    m_font = loadFont();

    const auto entries = std::string("1. Check status\n") +
                                "2. Add achievement\n" +
                                "3. Remove achievement\n" +
                                "4. Edit achievement\n" +
                                "5. Quit";

    m_entries = { sf::Text(entries, m_font, 32) };
}

void Menu::init(sf::RenderWindow &window) {
    sf::Vector2f center(m_screen_width / 2.0f, m_screen_height / 2.0f);

    sf::Text title("Achievements", m_font, 48);
    // FIXME: text shadowing, from using globalbounds?
    sf::FloatRect title_bounds = title.getGlobalBounds();
    sf::Vector2f bounds_vector((title_bounds.left + title_bounds.width) / 2.0f,
                               (title_bounds.top + title_bounds.height) / 2.0f);
    title.setOrigin(bounds_vector);
    title.setFillColor(ORANGE);
    sf::Vector2f titlePos(center.x, center.y - 150.0f);
    title.setPosition(titlePos);
    window.draw(title);

    float last_height{0.0f};
    auto pos = center;

    for(auto &text : m_entries) {
        sf::FloatRect bounds = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f((bounds.left + bounds.width) / 2.0f, (bounds.top + bounds.height) / 2.0f));
        text.setFillColor(ORANGE);

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
        m_highlighted++;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_highlighted--;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        if (event.type == sf::Event::Closed) {
            // TODO: prompt the user if they really want to quit or not
            sf::Vector2f pos(255.0, 350.5);
            sf::RectangleShape rect(pos);
            sf::Vector2f size (310.0, 315.0);
            rect.setSize(size);
            window.draw(rect);
            window.display();
            // window.close();
        }
    };
}
void Menu::update(sf::RenderWindow &window) {

    // 0 - noneo of them are highlighted
    // 1-5 all others are highlighted
    // guarantee that 5 is max
    if (m_highlighted == 1) {
        m_entries.front().setFillColor(sf::Color(255, 0, 0, 255));
        window.display();
    }
}