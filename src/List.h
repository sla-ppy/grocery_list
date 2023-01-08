#ifndef LIST_H
#define LIST_H

#include <vector>

#include "Achievement.h"

class List {
private:
    std::vector<std::string> m_headers;
    std::vector<Achievement> m_achievements;
public:
    List(const std::string& file_path);

    void status();
    void add();
    void remove();
    void edit();
};

#endif // LIST_H
