#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <iostream>
#include <vector>


class Achievement {
public:
    // TODO: add automatic ID assignment after data entry from .csv
    int id;
    // TODO: make it steps based
    std::string description;
    std::string type;
    std::string category;
    // TODO: progress is based on the current_steps and maximum_steps, render as %
    float progress;
    // Date completed_on; // when progress reached 100

    Achievement();
    Achievement(std::string _description, std::string _type, std::string _category, float _progress);
};

std::ostream &operator<<(std::ostream &os, const Achievement &achievement);

#endif // ACHIEVEMENT_H