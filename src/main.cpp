#include <iostream>

#include "Item.h"
#include "List.h"

using s_int = signed int;

int main() {

   List list;

   std::cout << "Item" << std::endl;
   std::cout << "1. Check status" << std::endl;
   std::cout << "2. Add item" << std::endl;
   std::cout << "3. Remove item" << std::endl;
   std::cout << "4. Quit" << std::endl;

   s_int menuChoice{0};
   bool inMenu{true};
   while(inMenu) {
      std::cin >> menuChoice;
      if (menuChoice == 1) {
         list.status();
      } else if (menuChoice == 2) {
         list.add();
      } else if (menuChoice == 3) {
         std::cout << "list.remove()" << std::endl;
      } else if (menuChoice == 4) {
         inMenu = false;
      } else {
         std::cout << "Choose a correct option! (1-4)" << std::endl;
         break;
      }
   }

   return 0;
}
