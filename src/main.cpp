// C++:
#include <iostream>

// LIB:
#include <SFML/Graphics.hpp>

// HEADER:
#include "List.h"
#include "Menu.h"

using s_int = signed int;

int main() {

   // init window
   const int        SCREEN_WIDTH{800};
   const int        SCREEN_HEIGHT{600};
   sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "My window");

   while(window.isOpen()) {
      sf::Event event{};

      Menu::display(window, SCREEN_WIDTH, SCREEN_HEIGHT);

      while(window.pollEvent(event)) {
         if(event.type == sf::Event::Closed) {
            window.close();
            return 0;
         }
      }
      return 0;
   }

   List list;

   s_int menuChoice{0};
   bool  inMenu{true};
   while(inMenu) {
      std::cout << "Item list:" << '\n';
      std::cout << "1. Check status" << '\n';
      std::cout << "2. Add item" << '\n';
      std::cout << "3. Remove item" << '\n';
      std::cout << "4. Edit item" << '\n';
      std::cout << "5. Quit" << '\n';

      // main menu
      std::cin >> menuChoice;
      if(menuChoice == 1) {
         list.status();
      } else if(menuChoice == 2) {
         list.add();
      } else if(menuChoice == 3) {
         list.remove();
      } else if(menuChoice == 4) {
         std::cout << "list.edit()" << '\n';
      } else if(menuChoice == 5) {
         inMenu = false;
      } else {
         std::cerr << "Choose a correct option! (1-4)" << '\n';
      }
   }

   return 0;
}
