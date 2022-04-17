#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Item.h"

class List {
 public:
   std::vector<Item> items{Item(1, "Apple", 50.0, 6),
                           Item(2, "Banana", 30.0, 3),
                           Item(3, "Orange", 40.0, 20),
                           Item(4, "Cherry", 25.0, 15),
                           Item(5, "Pear", 15.0, 3)};

   void add();
   void remove();
   void edit();
   void status();
};

#endif // LIST_H
