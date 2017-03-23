#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

/** @file Button.h
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief definition of simple sfml- Button class
 */

/** @brief generall button class with arbitray action return object
 * 
 *  @details 
 * button providing the following functionalities:
 * - return an action of type <typename ResultType = bool> 
 * - switch between two textures depending on mouse position: \n
 *  active=mouse at button area, inactive=mouse away 
 * - provide a drawable sprite via GetbuttonSprite()
 * 
 * @tparam ResultType the type of the button result, like MenuClass::Exit
 * 
 * Example Usage:
 * @code
 *    // part of a code with an sfml render window and the button only in there
 *    Button<MyResultType> ExitButton(exit,pathToTexInactive, pathtoTexActive, xpos, ypos);
 *    ExitButton.init();
 * 
 *    while(window.pollEvent(menuEvent))
 *    {
 *      if(menuEvent.type == sf::Event::MouseButtonPressed)
 *        if(ExitButton.checkClick())
 *          return ExitButton.GetbuttonAction();
 * 
 *      if(menuEvent.type == sf::Event::MouseMoved){
 *         ExitButton.checkMouseposition(sf::Mouse::getPosition(window));
 *         window.clear(sf::Color(255,255,255));
 *         window.draw(ExitButton.GetbuttonSprite());
 *         window.display();
 *      }
 *    }
 * @endcode
 */
template <typename ResultType = bool>
class Button
{
    public:
        //! constructor handling texturefiles, reaction  and position
        Button(ResultType action_, std::string pathToTexture_, std::string pathToActiveTexture_, float xPos_, float yPos_);

        //! virtual standart constructor
        virtual ~Button();
        
        //! getter for the sprite
        sf::Sprite GetbuttonSprite() const { return buttonSprite; }
        //! setter for the sprite
        void SetbuttonTexture(const sf::Sprite& val) { buttonSprite = val; }
        
        //! getter for the action
        ResultType GetbuttonAction() const { return action; }
        //! setter for the action
        void SetbuttonAction(const ResultType& val) { action = val; }
        
        //! check if button is isClicked
        bool checkClick(const sf::Vector2i& mousePos);
        
        //! check if mouse is on button
        void checkMouseposition(const sf::Vector2i& mousePos);
        
        //! init texture and sprite
        void initButton();

    private:
        //! texture of the inactive button
        sf::Texture buttonTexture;
        
        //! texture of the active button
        sf::Texture buttonActiveTexture;
        
        //! button sprite containing the actual texture
        sf::Sprite buttonSprite;
        
        //! button position in 2D
        sf::Vector2f buttonPosition;
        
        //! path to inactive button texture file
        std::string pathToTexture;
        
        //! path to active button texture file
        std::string pathToActiveTexture;
        
        //! check if Button was clicked
        bool isClicked;
        
        //! check if mouse is inside button area
        bool isMouseSelected;
        
        //! action as template argument
        ResultType action;
};

/* *** implementations follow here in the header (as we use a template class) *** */

template <typename ResultType>
Button<ResultType>::Button(ResultType action_,std::string pathToTexture_, std::string pathToActiveTexture_, float xPos_, float yPos_):
    pathToTexture(pathToTexture_),
    pathToActiveTexture(pathToActiveTexture_),
    buttonPosition(xPos_,yPos_),
    isMouseSelected(false),
    isClicked(false),
    action(action_)
{}

template <typename ResultType>
Button<ResultType>::~Button()
{}

template <typename ResultType>
bool Button<ResultType>::checkClick(const sf::Vector2i& mousePos){
    // check if mouse is on button and button has not been clicked before/is allowed to be clicked
    if(buttonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y) && !isClicked){
        isClicked = true;
        return true;
    }
}

template <typename ResultType>
void Button<ResultType>::checkMouseposition(const sf::Vector2i& mousePos){
    // check if mouse has come to the sprite just right now
    if((buttonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) && !isMouseSelected){
        isMouseSelected=true;
        buttonSprite.setTexture(buttonActiveTexture);
    }
    // check if mouse went out of the sprite just now
    else if((!buttonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) && isMouseSelected){
        isMouseSelected=false;
        buttonSprite.setTexture(buttonTexture);
    }
}

template <typename ResultType>
void Button<ResultType>::initButton(){
    // load texture
    if (!buttonTexture.loadFromFile(pathToTexture))
        std::cerr << "buttonTexture not found: "<< pathToTexture <<std::endl;
    if (!buttonActiveTexture.loadFromFile(pathToActiveTexture))
        std::cerr << "buttonActiveTexture not found: "<< pathToActiveTexture <<std::endl;

    // bind default (inactive) texture (on grafic card)
    buttonSprite.setTexture(buttonTexture);
    // set position
    buttonSprite.setPosition(buttonPosition);
}

#endif // BUTTON_H
