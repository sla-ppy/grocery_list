#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <iostream>
#include <vector>

using s_int = signed int;

class Achievement {
 public:
   s_int id;
   std::string description;
   char type;
   std::string category;
   float progress;

   Achievement();
   Achievement(s_int _id, std::string _description, char _type, std::string _category, float _progress);
};

std::ostream &operator<<(std::ostream &os, const Achievement &achievement);

#endif // ACHIEVEMENT_H