#include "Achievement.h"

#include <utility>

// def. ctor
Achievement::Achievement() : description{"No description"}, type{'X'}, category{"No category"}, progress{0.0} {}

// member initializer list
Achievement::Achievement(std::string _description, std::string _type, std::string _category, float _progress)
        : description{std::move(_description)}, type{std::move(_type)}, category{std::move(_category)},
          progress{_progress} {}

// overloading the << operator
std::ostream &operator<<(std::ostream &os, const Achievement &achievement) {
    //os << achievement.id << '\t';
    os << achievement.description << '\t';
    os << achievement.type << '\t';
    os << achievement.category << '\t';
    os << achievement.progress << '\t';
    return os;
}