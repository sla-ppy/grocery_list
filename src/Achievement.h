#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <iostream>
#include <vector>


class Achievement {
public:
    int id;
    // TODO: make it steps based
    std::string description;
    char type;
    std::string category;
    // TODO: progress is based on the current_steps and maximum_steps, render as %
    float progress;
    // Date completed_on; // when progress reached 100

    Achievement();
    Achievement(int _id, std::string _description, char _type, std::string _category, float _progress);
};

std::ostream &operator<<(std::ostream &os, const Achievement &achievement);

#endif // ACHIEVEMENT_H