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

   sf::Text mainMenuTitle("Grocery List:\n", font, 48);
   // fill text vector
   const auto menuEntries = std::string("1. Check status\n") +
                            "2. Add item\n" +
                            "3. Remove item\n" +
                            "4. Edit item\n" +
                            "5. Quit";
   std::vector<sf::Text> mainMenuText = {
       sf::Text(menuEntries, font, 32),
   };

   // FIXME: revise title and menu text code, clean up the code if needed
   // declare center text position
   sf::Vector2f centerPos(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);

   // display main title
   sf::FloatRect titleTextBounds = mainMenuTitle.getGlobalBounds();
   sf::Vector2f boundsVector((titleTextBounds.left + titleTextBounds.width) / 2.0f, (titleTextBounds.top + titleTextBounds.height) / 2.0f);

   mainMenuTitle.setOrigin(boundsVector);
   // orange
   mainMenuTitle.setFillColor(sf::Color(206, 122, 26, 19));

   sf::Vector2f titlePos(centerPos.x, centerPos.y - 125.0f);
   mainMenuTitle.setPosition(titlePos);

   window.draw(mainMenuTitle);

   // display all texts inside vector
   float lastHeight{0};
   auto  tempPos = centerPos;
   for(auto &text : mainMenuText) {
      // FIXME: have title as a separate object
      // center text
      sf::FloatRect textBounds = text.getGlobalBounds();
      text.setOrigin(sf::Vector2f((textBounds.left + textBounds.width) / 2.0f, (textBounds.top + textBounds.height) / 2.0f));

      // orange
      text.setFillColor(sf::Color(206, 122, 26, 19));

      // line spacing
      tempPos.y += lastHeight;
      lastHeight = text.getGlobalBounds().height;
      text.setPosition(tempPos);

      window.draw(text);
   }

   window.display();

   // TODO: highlight is selection. starts at 1, goes till 5, then start from one again to loop through the menu points
   // TODO: iterate through, then we take the index and apply the correct part to it.
   s_int highlightIndex{1};

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