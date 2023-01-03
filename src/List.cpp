#include "List.h"
#include "Achievement.h"

void List::status() {
   // check if obj vector is empty
   int count{0};
   for(const auto &item : achievements) {
       count++;
   }
   if(count == 0) {
      std::cerr << "You haven't added any achievements. Returning to main menu." << '\n';
      return;
   } else {
       std::cout << "Total: " << count << " rendered." << "\n";
   }

   // output format
   std::cout << "################################" << '\n';
   std::cout << "\t\tAchievements" << '\n';
   std::cout << "################################" << '\n';
   std::cout << "ID" << '\t' << "Name" << '\t' << "Price" << '\t' << "Quantity"
             << '\n';
   std::cout << "--------------------------------" << '\n';
   // display all items
   for(const auto &achievement : achievements) {
      std::cout << achievement << '\n';
      std::cout << "--------------------------------" << '\n';
   }
   std::cout << "################################" << '\n';
}

void List::add() {
   int count{1};
   for(const auto &item : achievements) {
       count++;
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
   Achievement achievement{count, inName, inPrice, inQuantity};
   achievements.push_back(achievement);
}

void List::remove() {
   bool isRemoving{true};
   while(isRemoving) {
      // output format
      std::cout << "Which item would you like to remove?" << '\n';
      for(const auto &achievement : achievements) {
         std::cout << achievement.id << '\t';
         std::cout << achievement.name << '\t';
         std::cout << achievement.price << '\t';
         std::cout << achievement.quantity << '\n';
      }

      // which item to remove
      s_int rmChoice{0};
      std::cin >> rmChoice;

      for(const auto &achievement : achievements) {
         if(rmChoice == achievement.id) {
             achievements.erase((achievements.begin() + achievement.id - 1));
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
      int count{1};
      for(auto &achievement : achievements) {
          achievement.id = count;
          count++;
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
      for(const auto &achievement : achievements) {
         std::cout << achievement.id << '\t';
         std::cout << achievement.name << '\t';
         std::cout << achievement.price << '\t';
         std::cout << achievement.quantity << '\n';
      }

      // which item to edit
      s_int editChoice{1};
      std::cin >> editChoice;

      for(auto &achievement : achievements) {
         if(editChoice == achievement.id) {

            bool isEditingPartly{true};
            while(isEditingPartly) {
               // TODO: re-format code so 0 comes first in if-else statements, reformat me
               // TODO: maybe count amount of items, and assign quit button based on that so its fancy?
               std::cout << "Which part of the item would you like to edit?" << '\n';
               std::cout << "(1-3) to edit" << '\n';
               std::cout << "(0) to quit" << '\n';
               std::cout << achievement.name << '\t';
               std::cout << achievement.price << '\t';
               std::cout << achievement.quantity << '\n';

               s_int partChoice{0};
               std::cin >> partChoice;

               if(partChoice == 1) {
                  std::cout << "Enter new name: " << '\n';

                  std::string newName;
                  std::cin >> newName;

                  achievement.name = newName;
               } else if(partChoice == 2) {
                  std::cout << "Enter new price: " << '\n';

                  float newPrice{0.0f};
                  std::cin >> newPrice;

                  achievement.price = newPrice;
               } else if(partChoice == 3) {
                  std::cout << "Enter new quantity: " << '\n';

                  s_int newQuantity{0};
                  std::cin >> newQuantity;

                  achievement.quantity = newQuantity;
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