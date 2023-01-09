#define ORANGE sf::Color(206, 122, 26, 255)
#define WHITE sf::Color(255, 255, 255, 255)
#define BLACK sf::Color(0, 0, 0, 255)

// HEADER:
#include "Menu.h"

Menu::Menu() {}
Menu::Menu(int _screen_width, int _screen_height, const std::vector<std::string> &_options) {
    m_screen_width = _screen_width;
    m_screen_height = _screen_height;
    m_options = _options;

    if (!m_font.loadFromFile("./assets/font/IBMPlexMono-Regular.ttf")) {
        std::cerr << "ERROR: Font didn't load properly!" << '\n';
    }

    // FIXME: this is supposed to be taken as input from menu_input.csv
    m_title = sf::Text("Achievements", m_font, 48);
    for (const auto &text: m_texts) {
        m_entries.emplace_back(sf::Text(text, m_font, 32));
    }

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
        // FIXME: text shadowing, from using global bounds?
        sf::FloatRect bounds = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f((bounds.left + bounds.width) / 2.0f, (bounds.top + bounds.height) / 2.0f));
        text.setFillColor(ORANGE);

        // line spacing
        // FIXME: use sf::Transformable::move()?
        pos.y += last_height;
        last_height = text.getGlobalBounds().height;
        text.setPosition(pos);

        /*
        // TODO: drawing quitting prompt
        sf::RectangleShape rect;
        sf::Vector2f size(m_screen_width, m_screen_height / 3);
        rect.setSize(size);
        sf::Vector2f pos(0.0f, m_screen_height / 3);
        rect.setPosition(pos);
        rect.setFillColor(ORANGE);

        sf::Text prompt;
        //window.clear(WHITE);      use this?
        window.draw(rect);
        */
    }
}

void Menu::update(sf::RenderWindow &window) {
    window.clear(BLACK);

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
    // TODO: status
}
void Menu::handle_event(const sf::Event &event) {
// if (event.type == sf::Event::Resized) { screen_width = event.size.width; screen_height = event.size.height; }
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
            m_highlighted--;
        }
        if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
            m_highlighted++;
        }

        if (event.key.code == sf::Keyboard::Enter && m_highlighted == 0) {
            std::cout << "Status" << '\n';
        }
        if (event.key.code == sf::Keyboard::Enter && m_highlighted == 1) {
            std::cout << "Add" << '\n';
        }
        if (event.key.code == sf::Keyboard::Enter && m_highlighted == 2) {
            std::cout << "Remove" << '\n';
        }
        if (event.key.code == sf::Keyboard::Enter && m_highlighted == 3) {
            std::cout << "Edit" << '\n';
        }
    }
}