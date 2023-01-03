#include "Achievement.h"

#include <utility>

using s_int = signed int;

// def. ctor
Achievement::Achievement() : id{}, description{"No description"}, type{'X'}, category{"No category"}, progress{0.0} {}

// member initializer list
Achievement::Achievement(s_int _id, std::string _description, char _type, std::string _category, float _progress)
    : id{_id}, description{std::move(_description)}, type{_type}, category{std::move(_category)}, progress{_progress} {}

// overloading the << operator
std::ostream &operator<<(std::ostream &os, const Achievement &achievement) {
   os << achievement.id << '\t';
   os << achievement.description << '\t';
   os << achievement.type << '\t';
   os << achievement.category << '\t';
   os << achievement.progress << '\t';
   return os;
}