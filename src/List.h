#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Item.h"

class List {
 public:
   std::vector<Item> items{Item(1, "Apple", 50.0f, 6),
                           Item(2, "Banana", 30.0f, 3),
                           Item(3, "Orange", 40.0f, 20),
                           Item(4, "Cherry", 25.0f, 15),
                           Item(5, "Pear", 15.0f, 3)};

   void status();
   void add();
   void remove();
   void edit();
};

#endif // LIST_H
