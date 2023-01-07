#define ORANGE sf::Color(206, 122, 26, 255)
#define WHITE sf::Color(255, 255, 255, 255)
#define BLACK sf::Color(0, 0, 0, 255)

// HEADER:
#include "Menu.h"

using s_int = signed int;

Menu::Menu(int _screen_width, int _screen_height) {
    m_screen_width = _screen_width;
    m_screen_height = _screen_height;

    if (!m_font.loadFromFile("./assets/font/IBMPlexMono-Regular.ttf")) {
        std::cerr << "ERROR: Font didn't load properly!" << '\n';
    }

    m_title = sf::Text("Achievements", m_font, 48);

    for (const auto &text: texts) {
        m_entries.emplace_back(sf::Text(text, m_font, 32));
    };
}

void Menu::init(sf::RenderWindow &window) {
    sf::Vector2f center(m_screen_width / 2.0f, m_screen_height / 2.0f);

    sf::FloatRect title_bounds = m_title.getGlobalBounds();
    sf::Vector2f bounds_vector((title_bounds.left + title_bounds.width) / 2.0f,
                               (title_bounds.top + title_bounds.height) / 2.0f);
    m_title.setOrigin(bounds_vector);
    m_title.setFillColor(ORANGE);
    sf::Vector2f titlePos(center.x, center.y - 200.0f);
    m_title.setPosition(titlePos);

    float last_height{0.0f};
    auto pos = center;

    for (auto &text: m_entries) {
        // FIXME: text shadowing, from using globalbounds?
        sf::FloatRect bounds = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f((bounds.left + bounds.width) / 2.0f, (bounds.top + bounds.height) / 2.0f));
        text.setFillColor(ORANGE);

        // line spacing
        // FIXME: use sf::Transformable::move()?
        pos.y += last_height;
        last_height = text.getGlobalBounds().height;
        text.setPosition(pos);
    }
}

void Menu::processInput(sf::RenderWindow &window, sf::Event &event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        if (event.type == sf::Event::Closed) {
            // TODO: prompt the user if they really want to quit or not
            sf::RectangleShape rect;
            sf::Vector2f size(m_screen_width, m_screen_height / 3);
            rect.setSize(size);
            sf::Vector2f pos(0.0f, m_screen_height / 3);
            rect.setPosition(pos);
            rect.setFillColor(ORANGE);

            sf::Text prompt;
            //window.clear(WHITE);      use this?
            window.draw(rect);
        }
    };
}

void Menu::update(sf::RenderWindow &window) {
    window.clear();

    // guarantee and constraint correct menu entry loop
    if (m_highlighted < 0) {
        m_highlighted = 4;
    } else if (m_highlighted > 4) {
        m_highlighted = 0;
    }

    // render all obj as orange
    for (auto &text: m_entries) {
        text.setFillColor(ORANGE);
    }

    // change the specific one
    m_entries[m_highlighted].setFillColor(WHITE);
    window.draw(m_entries[m_highlighted]);

    // draw all objects
    // TODO: for the future it could be a good idea to group together all the objects needing to be drawn into one spot?
    for (auto &text: m_entries) {
        window.draw(m_title);
        window.draw(text);
    }

    window.display();
}