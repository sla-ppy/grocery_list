// C++:
#include <iostream>

// LIB:
#include <SFML/Graphics.hpp>

// HEADER:
#include "List.h"
#include "Menu.h"

using s_int = signed int;

int main() {
   // debug mode so we can both play with SFML and test functionality
   std::cout << "Choose render mode:" << '\n';
   std::cout << "1 - SFML mode" << '\n';
   std::cout << "0 - Terminal mode" << '\n';
   bool mode{0};
   std::cin >> mode;

   if(mode) {
      // init window
      const int        SCREEN_WIDTH{336}; // 1920 * 0,175
      const int        SCREEN_HEIGHT{1080};

      sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Seed");

      while(window.isOpen()) {
         sf::Event event{};

         window.display();
         Menu::display(window, SCREEN_WIDTH, SCREEN_HEIGHT);
         Menu::processInput();

         while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
               window.close();
               return 0;
            }
         }
      }

   } else {
      List list;

      s_int menu_choice{0};
      bool  menu{true};
      while(menu) {
         std::cout << "Seed:" << '\n';
         std::cout << "1. Check status" << '\n';
         std::cout << "2. Add achievement" << '\n';
         std::cout << "3. Remove achievement" << '\n';
         std::cout << "4. Edit achievement" << '\n';
         std::cout << "5. Quit" << '\n';

         // main menu
         std::cin >> menu_choice;
         if(menu_choice == 1) {
            list.status();
         } else if(menu_choice == 2) {
            list.add();
         } else if(menu_choice == 3) {
            list.remove();
         } else if(menu_choice == 4) {
            list.edit();
         } else if(menu_choice == 5) {
             menu = false;
         } else {
            std::cerr << "Choose a correct option! (1-5)" << '\n';
         }
      }
   }

   return 0;
}