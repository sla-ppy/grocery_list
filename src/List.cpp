#include "List.h"
#include "Item.h"

void List::add() {
   // assign id based on current object amount
   int itemAmount{1};
   for (const auto &item : items) {
      itemAmount++;
   }

   std::string inName{};
   float       inPrice{0};
   s_int       inQuantity{0};

   std::cout << "Item adding format: Name - Price - Quantity" << std::endl;
   std::cout << "Name:" << std::endl;
   std::cin >> inName;
   std::cout << "Price:" << std::endl;
   std::cin >> inPrice;
   std::cout << "Quantity:" << std::endl;
   std::cin >> inQuantity;

   Item item{itemAmount, inName, inPrice, inQuantity};
   items.push_back(item);
}

void List::remove() {
   bool isRemoving{true};
   while(isRemoving) {
      std::cout << "Which item would you like to remove?" << '\n';
      for (const auto &item : items) {
         std::cout << item.id << '\n';
         std::cout << item.name << '\n';
      }

      s_int rmChoice{0};
      std::cin >> rmChoice;
      for (const auto &item : items) {
         if (rmChoice == 1) {
            break;
         }
         else if (rmChoice == item.id) {
            items.erase((items.begin() + item.id) + 1);
         } else {
            std::cout << "Choose out of the available ID's." << '\n';
         }
      }
   }

   // fixme: after removal, we need to re-assign id's somehow
}

void List::status() {
   // todo: check if object vector is empty, and if so, return to the menu

   std::cout << "################################" << '\n';
   std::cout << "\tItem status" << '\n';
   std::cout << "################################" << '\n';
   std::cout << "ID" << '\t' << "Name" << '\t' << "Price" << '\t' << "Quantity" << '\n';
   std::cout << "--------------------------------" << '\n';
   for (const auto &item : items) {
      std::cout << item << '\n';
      std::cout << "--------------------------------" << '\n';
   }
   std::cout << "################################" << '\n';
}