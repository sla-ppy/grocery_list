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

   // input for obj
   std::cout << "Item adding format: Name - Price - Quantity" << '\n';
   std::cout << "Name:" << '\n';
   std::cin >> inName;
   std::cout << "Price:" << '\n';
   std::cin >> inPrice;
   std::cout << "Quantity:" << '\n';
   std::cin >> inQuantity;

   // add new obj
   Item item{itemAmount, inName, inPrice, inQuantity};
   items.push_back(item);
}

void List::remove() {
   bool isRemoving{true};
   while (isRemoving) {
      // output format
      std::cout << "Which item would you like to remove?" << '\n';
      for (const auto &item : items) {
         std::cout << item.id << '\t';
         std::cout << item.name << '\t';
         std::cout << item.price << '\t';
         std::cout << item.quantity << '\n';
      }

      // which item to remove
      s_int rmChoice{0};
      std::cin >> rmChoice;
      for (const auto &item : items) {
         if (rmChoice == item.id) {
            items.erase((items.begin() + item.id -1));
         }
      }

      // fixme: reassign correctly
      // continue item removal?
      std::cout << "Keep removing? y/N?" << '\n';
      char inResponse{'y'};
      std::cin >> inResponse;
      if (inResponse == 'n' || inResponse == 'N') {
         isRemoving = false;
      }
   }

   // re-assign id's after removal
   int itemAmount{0};
   for (const auto &item : items) {
      itemAmount++;
   }
}

void List::status() {
   // check if obj vector is empty
   int itemAmount{0};
   for (const auto &item : items) {
      itemAmount++;
   }
   if (itemAmount == 0) {
      std::cout << "You haven't added any items. Returning to main menu." << '\n';
      return;
   }

   // output format
   std::cout << "################################" << '\n';
   std::cout << "\tItem status" << '\n';
   std::cout << "################################" << '\n';
   std::cout << "ID" << '\t' << "Name" << '\t' << "Price" << '\t' << "Quantity"
             << '\n';
   std::cout << "--------------------------------" << '\n';
   // display all items
   for (const auto &item : items) {
      std::cout << item << '\n';
      std::cout << "--------------------------------" << '\n';
   }
   std::cout << "################################" << '\n';
}

void List::edit() {}