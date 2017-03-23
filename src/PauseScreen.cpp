#include "PauseScreen.h"

/** @file PauseScreen.cpp
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief implementations of PauseScreen class
 */

PauseScreen::PauseScreen(){}

PauseScreen::~PauseScreen(){}

PauseScreen::PauseResult PauseScreen::Show(sf::RenderWindow& window){

    // set and bind texture of menu backround
    sf::Texture texture;
    if(SCREEN_WIDTH==800){
        if(!texture.loadFromFile("../textures/generic_pauseMenu_800x600.png"))
            std::cerr << "generic_pauseMenu_800x600.png not loaded"<<std::endl;
    }else if(SCREEN_WIDTH==1024){
        if(!texture.loadFromFile("../textures/generic_pauseMenu_1024x768.png"))
            std::cerr << "generic_pauseMenu_1024x768.png not loaded"<<std::endl;
    }
    _sprite.setTexture(texture);
     
    //add "Play" Button:
    Button<PauseScreen::PauseResult> playButton_B(
    PauseScreen::Play,
    "../textures/generic_resumePauseButton_120x60.png",
    "../textures/generic_resumePauseButton_120x60_active.png",
     (SCREEN_WIDTH/2)-60, (SCREEN_HEIGHT/2)+40);
    playButton_B.initButton();
    _menuItems.push_back(playButton_B);
    
    //add "Exit" Button
    Button<PauseScreen::PauseResult> exitButton_B(
        PauseScreen::Exit,
        "../textures/generic_exitPauseButton_120x60.png",
        "../textures/generic_exitPauseButton_120x60_active.png",
        (SCREEN_WIDTH/2)-60, (SCREEN_HEIGHT/2)-40);
    exitButton_B.initButton();
    _menuItems.push_back(exitButton_B);
    
    // draw buttons and backround on the window
    drawMenu(window);

    // get the button answers and input reactions (exit click)
    return GetMenuResponse(window);
}

//! check click event
PauseScreen::PauseResult PauseScreen::HandleClick(const sf::Vector2i&  mousePos){
    // loop over all buttons
    std::list<Button<PauseScreen::PauseResult> >::iterator it;
    for ( it = _menuItems.begin(); it != _menuItems.end(); it++){
            if(it -> checkClick(mousePos)){
                return it -> GetbuttonAction();
            }
    }
    return Nothing;
}

//! check if button should be framed if mouse is on top
void PauseScreen::HandleMouseposition(const sf::Vector2i&  mousePos){
    //loop over all buttons and run the button-mouse pointer detections
    std::list<Button<PauseScreen::PauseResult> >::iterator it;
    for ( it = _menuItems.begin(); it != _menuItems.end(); it++){
        it -> checkMouseposition(mousePos);
    }
}

//! perform the draw and display steps of sfml window
void PauseScreen::drawMenu(sf::RenderWindow& window){
    // clear window
    window.clear(sf::Color(255,255,255));
  
    // draw backround sprite
    window.draw(_sprite);
    
    // loop over the button sprites
    std::list<Button<PauseScreen::PauseResult> >::iterator it;
    for ( it = _menuItems.begin(); it != _menuItems.end(); it++){
        window.draw(it -> GetbuttonSprite());
    }
    
    // display stuff
    window.display();
}

//! run the sfml event detection loop for the menu
PauseScreen::PauseResult PauseScreen::GetMenuResponse(sf::RenderWindow& window)
{
  sf::Event menuEvent;
  while(true)
  {

    while(window.pollEvent(menuEvent))
    {
      if(menuEvent.type == sf::Event::MouseButtonPressed){
        return HandleClick(sf::Mouse::getPosition(window));
      }
      
      if(menuEvent.type == sf::Event::MouseMoved){
        HandleMouseposition(sf::Mouse::getPosition(window));
        // draw buttons
        drawMenu(window);
      }

      if(menuEvent.type == sf::Event::Closed){
        return Exit;
      }
    }

  }
}
