// C++:
#include <iostream>

// LIB:
#include "SFML/Graphics.hpp"

// HEADER:
#include "Menu.h"

void Menu::display(sf::RenderWindow &window, const sf::Font &font, float SCREEN_WIDTH, float SCREEN_HEIGHT) {
   // fill text vecor
   const auto menuEntries = std::string("1. Check status\n") +
                            "2. Add item\n" +
                            "3. Remove item\n" +
                            "4. Edit item\n" +
                            "5. Quit";
   std::vector<sf::Text> mainMenuTxt = {
       sf::Text("Item List:", font, 32),
       sf::Text(menuEntries, font, 16),
   };

   // get initial text position
   sf::Vector2f textPos(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0);

   // display all texts inside vector
   float lastHeight{0};
   auto  tempPos = textPos;
   for(auto &text : mainMenuTxt) {
      text.setFillColor(sf::Color(206, 122, 26, 19));
      tempPos.y += lastHeight + 20;
      lastHeight = text.getGlobalBounds().height;
      text.setPosition(tempPos);
      window.draw(text);
   }

   // window.draw(text);
   window.display();
};
