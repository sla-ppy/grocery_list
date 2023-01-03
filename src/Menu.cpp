// C++:
#include <iostream>

// LIB:
#include "SFML/Graphics.hpp"

// HEADER:
#include "Menu.h"

using s_int = signed int;

sf::Font Menu::loadFont() {
   sf::Font font;
   if(!font.loadFromFile("./assets/font/IBMPlexMono-Regular.ttf")) {
      std::cerr << "ERROR: Font wasn't able to load." << '\n';
   }

   return font;
}

void Menu::display(sf::RenderWindow &window, float SCREEN_WIDTH, float SCREEN_HEIGHT) {

   sf::Font font = loadFont();

   sf::Text main_menu_title("Achievement:\n", font, 48);
   // fill text vector
   const auto menu_entries = std::string("1. Check status\n") +
                             "2. Add achievement\n" +
                             "3. Remove achievement\n" +
                             "4. Edit achievement\n" +
                             "5. Quit";
   std::vector<sf::Text> main_menu_text = {
       sf::Text(menu_entries, font, 32),
   };

   // FIXME: revise title and menu text code, clean up the code if needed
   // declare center text position
   sf::Vector2f center_pos(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);

   // display main title
   sf::FloatRect title_text_bounds = main_menu_title.getGlobalBounds();
   sf::Vector2f bounds_vector((title_text_bounds.left + title_text_bounds.width) / 2.0f, (title_text_bounds.top + title_text_bounds.height) / 2.0f);

   main_menu_title.setOrigin(bounds_vector);
   // orange
   main_menu_title.setFillColor(sf::Color(206, 122, 26, 19));

   sf::Vector2f titlePos(center_pos.x, center_pos.y - 125.0f);
   main_menu_title.setPosition(titlePos);

   window.draw(main_menu_title);

   // display all texts inside vector
   float last_height{0};
   auto  temp_pos = center_pos;
   for(auto &text : main_menu_text) {
      // FIXME: have title as a separate object
      // center text
      sf::FloatRect text_bounds = text.getGlobalBounds();
      text.setOrigin(sf::Vector2f((text_bounds.left + text_bounds.width) / 2.0f, (text_bounds.top + text_bounds.height) / 2.0f));

      // orange
      text.setFillColor(sf::Color(206, 122, 26, 19));

      // line spacing
      temp_pos.y += last_height;
      last_height = text.getGlobalBounds().height;
      text.setPosition(temp_pos);

      window.draw(text);
   }

   window.display();

   // TODO: highlight is selection. starts at 1, goes till 5, then start from one again to loop through the menu points
   // TODO: iterate through, then we take the index and apply the correct part to it.
   s_int highlighted{1};

}

void Menu::processInput() {
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // NOLINT(bugprone-branch-clone)
      // change menu highlight by one towards up
   } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      // change menu highlight by one towards down
   }

   // TODO: figure out quitting with escape, probably have to return event.type = sf::Event::Closed
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {};
}