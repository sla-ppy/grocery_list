#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Achievement.h"

class List {
 public:
   std::vector<Achievement> achievements{Achievement(1, "Apple", 50.0f, 6),
                                         Achievement(2, "Banana", 30.0f, 3),
                                         Achievement(3, "Orange", 40.0f, 20),
                                         Achievement(4, "Cherry", 25.0f, 15),
                                         Achievement(5, "Pear", 15.0f, 3)};

   void status();
   void add();
   void remove();
   void edit();
};

#endif // LIST_H
