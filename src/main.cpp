#include <iostream>

#include "List.h"

using s_int = signed int;

// clear screen
void cls() { std::cout << std::string(100, '\n'); }

int main() {

   List list;

   s_int menuChoice{0};
   bool  inMenu{true};
   while (inMenu) {
      std::cout << "Item list:" << '\n';
      std::cout << "1. Check status" << '\n';
      std::cout << "2. Add item" << '\n';
      std::cout << "3. Remove item" << '\n';
      std::cout << "4. Clear screen" << '\n';
      std::cout << "5. Quit" << '\n';

      // main menu
      std::cin >> menuChoice;
      if (menuChoice == 1) {
         list.status();
      } else if (menuChoice == 2) {
         list.add();
      } else if (menuChoice == 3) {
         list.remove();
      } else if (menuChoice == 4) {
         cls();
      } else if (menuChoice == 5) {
         inMenu = false;
      } else {
         std::cout << "Choose a correct option! (1-4)" << '\n';
      }
   }

   return 0;
}