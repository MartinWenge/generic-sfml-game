#ifndef MAINMENU_H
#define MAINMENU_H

#include <list>
#include <iostream>

#include "Button.h"
#include "windowSize.h"

/** @file MainMenu.h
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief definition of MainMenu class
 */

class MainMenu
{
    public:
        //! default constructor
        MainMenu();
        //! default destructor
        virtual ~MainMenu();
        
        //! possible button results
        enum MenuResult { Nothing, Exit, Play };

        //! getter for button list
        std::list<Button<MenuResult> > GetitemList() { return _menuItems; }
        //! setter for button list
        void SetitemList(std::list<Button<MenuResult> > val) { _menuItems = val; }

        //! handle mouse/close events and draw backround and buttons 
        MenuResult Show(sf::RenderWindow& window);

    private:
        //! list of all buttons
        std::list<Button<MenuResult> > _menuItems;
        
        //! loop over all buttons and check click events
        MenuResult HandleClick(const sf::Vector2i& mousePos);
        
        //!loop over all buttons and check mouse position if no click is made to change texture
        void HandleMouseposition(const sf::Vector2i& mousePos);
        
        //! loop over all buttons and draw them with the backround sprite
        void drawMenu(sf::RenderWindow& window);
        
        //! event loop for buttons or close event
        MenuResult GetMenuResponse(sf::RenderWindow& window);
        
        //! backround sprite
        sf::Sprite _sprite;
        
};

#endif // MAINMENU_H
