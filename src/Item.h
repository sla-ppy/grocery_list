#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using s_int = signed int;

class Item {
public:
    s_int id;
    std::string name;
    float price;
    s_int quantity;

    Item(std::string _name, float _price, s_int _quantity);
    Item();
};

std::ostream& operator<<(std::ostream& os, const Item& item);

#endif // ITEM_H