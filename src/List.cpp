#include "List.h"
#include "Item.h"

void List::add() {
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

   Item item = *new Item(inName, inPrice, inQuantity);
   objects.push_back(item);
}

void List::remove() {

}

void List::status() {
   // todo: check if object vector is empty, and if so, return to the menu

   for(const auto& object : objects) {
      std::cout << object << '\n';
   }
}