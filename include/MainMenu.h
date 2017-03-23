#ifndef MAINMENU_H
#define MAINMENU_H

#include "Button.h"
#include <list>
#include <iostream>
// define screen Size
#include "windowSize.h"

class MainMenu
{
    public:
        MainMenu();
        virtual ~MainMenu();
        
        enum MenuResult { Nothing, Exit, Play };

        std::list<Button<MenuResult> > GetitemList() { return _menuItems; }
        void SetitemList(std::list<Button<MenuResult> > val) { _menuItems = val; }

        // draw all the stuff
        MenuResult Show(sf::RenderWindow& window);

    private:
        std::list<Button<MenuResult> > _menuItems;
        
        // loop over all buttons and check click events
        MenuResult HandleClick(const sf::Vector2i& mousePos);
        
        // check mouse position if no click is made to chenge texture
        void HandleMouseposition(const sf::Vector2i& mousePos);
        
        // loop over all buttons and draw them
        void drawMenu(sf::RenderWindow& window);
        
        // event loop for buttons or close event
        MenuResult GetMenuResponse(sf::RenderWindow& window);
        
        // backround texture/sprite
        sf::Sprite _sprite;
        
};

#endif // MAINMENU_H
