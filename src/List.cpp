#include "List.h"
#include "Item.h"

void List::status() {
   // check if obj vector is empty
   int itemAmount{0};
   for(const auto &item : items) {
      itemAmount++;
   }
   if(itemAmount == 0) {
      std::cerr << "You haven't added any items. Returning to main menu." << '\n';
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
   for(const auto &item : items) {
      std::cout << item << '\n';
      std::cout << "--------------------------------" << '\n';
   }
   std::cout << "################################" << '\n';
}

void List::add() {
   // count id based on obj amount
   int itemAmount{1};
   for(const auto &item : items) {
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
   while(isRemoving) {
      // output format
      std::cout << "Which item would you like to remove?" << '\n';
      for(const auto &item : items) {
         std::cout << item.id << '\t';
         std::cout << item.name << '\t';
         std::cout << item.price << '\t';
         std::cout << item.quantity << '\n';
      }

      // which item to remove
      s_int rmChoice{0};
      std::cin >> rmChoice;

      for(const auto &item : items) {
         if(rmChoice == item.id) {
            items.erase((items.begin() + item.id - 1));
         }
      }

      // ask if continue removal
      std::cout << "Keep removing? y/N?" << '\n';
      char inResponse{'y'};
      std::cin >> inResponse;
      if(inResponse == 'n' || inResponse == 'N') {
         isRemoving = false;
      }

      // reassign id's after each removal
      int itemAmount{1};
      for(auto &item : items) {
         item.id = itemAmount;
         itemAmount++;
      }
   }
}

void List::edit() {
   bool isEditing{true};
   while(isEditing) {
      // output format
      // TODO: re-format code so 0 comes first in if-else statements, reformat me
      // TODO: maybe count amount of items, and assign quit button based on that so its fancy?
      std::cout << "Which item would you like to edit?" << '\n';
      std::cout << "(0) to quit" << '\n';
      for(const auto &item : items) {
         std::cout << item.id << '\t';
         std::cout << item.name << '\t';
         std::cout << item.price << '\t';
         std::cout << item.quantity << '\n';
      }

      // which item to edit
      s_int editChoice{1};
      std::cin >> editChoice;

      for(auto &item : items) {
         if(editChoice == item.id) {

            bool isEditingPartly{true};
            while(isEditingPartly) {
               // TODO: re-format code so 0 comes first in if-else statements, reformat me
               // TODO: maybe count amount of items, and assign quit button based on that so its fancy?
               std::cout << "Which part of the item would you like to edit?" << '\n';
               std::cout << "(1-3) to edit" << '\n';
               std::cout << "(0) to quit" << '\n';
               std::cout << item.name << '\t';
               std::cout << item.price << '\t';
               std::cout << item.quantity << '\n';

               s_int partChoice{0};
               std::cin >> partChoice;

               if(partChoice == 1) {
                  std::cout << "Enter new name: " << '\n';

                  std::string newName;
                  std::cin >> newName;

                  item.name = newName;
               } else if(partChoice == 2) {
                  std::cout << "Enter new price: " << '\n';

                  float newPrice{0.0f};
                  std::cin >> newPrice;

                  item.price = newPrice;
               } else if(partChoice == 3) {
                  std::cout << "Enter new quantity: " << '\n';

                  s_int newQuantity{0};
                  std::cin >> newQuantity;

                  item.quantity = newQuantity;
               } else if(partChoice == 0) {
                  std::cout << "Returning to edit" << '\n';
                  isEditingPartly = false;
               } else {
                  std::cerr << "Choose valid item part to edit." << '\n';
               }
            }
         } else if (editChoice == 0) {
            isEditing = false;
         }
      }
   }
}