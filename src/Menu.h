//
// Created by sla-ppy on 17/04/2022.
//

#ifndef GROCERY_LIST_MENU_H
#define GROCERY_LIST_MENU_H

class Menu {
 public:
   static sf::Font loadFont();
   static void display(sf::RenderWindow &window, float SCREEN_WIDTH, float SCREEN_HEIGHT);
};

#endif // GROCERY_LIST_MENU_H
