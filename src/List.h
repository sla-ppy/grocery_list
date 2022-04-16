#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Item.h"

class List {
 public:
   std::vector<Item> items = {Item(0, "Apple", 50.0, 5)};

   void add();
   void remove();
   void status();
};

#endif // LIST_H
