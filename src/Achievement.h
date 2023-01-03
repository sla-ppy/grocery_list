#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <iostream>

using s_int = signed int;

class Achievement {
 public:
   s_int       id{0};
   std::string name;
   float       price{0.0};
   s_int       quantity{0};

   Achievement();
   Achievement(s_int _id, std::string _name, float _price, s_int _quantity);
};

std::ostream &operator<<(std::ostream &os, const Achievement &achievement);

#endif // ACHIEVEMENT_H