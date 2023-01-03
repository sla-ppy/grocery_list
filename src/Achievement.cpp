#include "Achievement.h"

#include <utility>

using s_int = signed int;

// def. ctor
Achievement::Achievement() : id{0}, name{"unnamed"}, price{0.0f}, quantity{0} {}

// member initializer list
Achievement::Achievement(s_int _id, std::string _name, float _price, s_int _quantity)
    : id{_id}, name{std::move(_name)}, price{_price}, quantity{_quantity} {}

// overloading the << operator
std::ostream &operator<<(std::ostream &os, const Achievement &achievement) {
   os << achievement.id << '\t';
   os << achievement.name << '\t';
   os << achievement.price << '\t';
   os << achievement.quantity << '\t';
   return os;
}