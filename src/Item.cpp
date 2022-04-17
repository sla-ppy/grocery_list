#include "Item.h"

#include <utility>

using s_int = signed int;

// def. ctor
Item::Item() : id{0}, name{"unnamed"}, price{0.0}, quantity{0} {}

// member initializer list
Item::Item(s_int _id, std::string _name, float _price, s_int _quantity)
    : id{_id}, name{std::move(_name)}, price{_price}, quantity{_quantity} {}

// overloading the << operator
std::ostream &operator<<(std::ostream &os, const Item &item) {
   os << item.id << '\t';
   os << item.name << '\t';
   os << item.price << '\t';
   os << item.quantity << '\t';
   return os;
}