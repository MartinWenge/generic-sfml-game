#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include "Button.h"
#include <list>
#include <iostream>
// define screen Size
#include "windowSize.h"

class PauseScreen
{
    public:
        PauseScreen();
        virtual ~PauseScreen();
        
        enum PauseResult { Nothing, Exit, Play };

        std::list<Button<PauseScreen::PauseResult> > GetitemList() { return _menuItems; }
        void SetitemList(std::list<Button<PauseScreen::PauseResult> > val) { _menuItems = val; }

        // draw all the stuff
        PauseResult Show(sf::RenderWindow& window);

    private:
        std::list<Button<PauseResult> > _menuItems;
        
        // loop over all buttons and check click events
        PauseResult HandleClick(const sf::Vector2i& mousePos);
        
        // check mouse position if no click is made to chenge texture
        void HandleMouseposition(const sf::Vector2i& mousePos);
        
        // event loop for buttons or close event
        PauseResult GetMenuResponse(sf::RenderWindow& window);
        
        //print all buttons of menu items list
        void drawMenu(sf::RenderWindow& window);
        
        // backround texture/sprite
        sf::Sprite _sprite;
        
};

#endif // PAUSESCREEN_H
