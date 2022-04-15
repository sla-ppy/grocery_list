#include "Item.h"

// TODO: auto-assign id based on object count
// default
Item::Item() {
   id       = 0;
   name     = "NULL";
   price    = 0.0;
   quantity = 0;
};

Item::Item(std::string _name, float _price, s_int _quantity) {
   name     = _name;
   price    = _price;
   quantity = _quantity;
}

// FIXME: look up operator overloading and make it work here since unsure if this works as expected
std::ostream &operator<<(std::ostream &os, const Item &item) {
   os << item.name << '\n';
   os << item.price << '\n';
   os << item.quantity << '\n';
   return os;
};