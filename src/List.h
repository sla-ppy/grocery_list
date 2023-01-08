#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Achievement.h"

class List {
public:
    std::vector<Achievement> achievements{Achievement(0, "Exercise 7 times a week!", 'C', "Health", 20.0),
                                          Achievement(1, "Brush your teeth 2 times today", 'D', "-", 51.35),
                                          Achievement(2, "Study for eternity", 'C', "Studies", 100.0),
                                          Achievement(3, "Pick an apple in virtual reality", 'C', "Gaming", 36.315),
                                          Achievement(4, "Work for 5 seconds", 'T', "Work", 0.0)};

    void status();
    void add();
    void remove();
    void edit();
};

#endif // LIST_H
