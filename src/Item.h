#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using s_int = signed int;

class Item {
 public:
   s_int       id{0};
   std::string name;
   float       price{0.0};
   s_int       quantity{0};

   Item();
   Item(s_int _id, std::string _name, float _price, s_int _quantity);
};

std::ostream &operator<<(std::ostream &os, const Item &item);

#endif // ITEM_H