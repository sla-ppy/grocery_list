#ifndef MENU_H
#define MENU_H

class Menu {
 public:
   static sf::Font loadFont();
   static void display(sf::RenderWindow &window, float SCREEN_WIDTH, float SCREEN_HEIGHT);
   static void processInput();
};

#endif // MENU_H
