#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Item.h"

class List {
 public:
   std::vector<Item> objects;

   void add();
   void remove();
   void status();
};

#endif // LIST_H
