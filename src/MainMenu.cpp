#include "MainMenu.h"

/** @file MainMenu.cpp
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief implementation of MainMenu class
 */

MainMenu::MainMenu(){}

MainMenu::~MainMenu(){}

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window){
  
  sf::Texture texture;

  if(SCREEN_WIDTH==800){
      if(!texture.loadFromFile("../textures/generic_mainMenu_800x600.png"))
      {
          std::cerr << "generic_mainMenu_800x600.png not loaded"<<std::endl;
      }
  }else if(SCREEN_WIDTH==1024){
    if(!texture.loadFromFile("../textures/generic_mainMenu_1024x768.png"))
      {
          std::cerr << "generic_mainMenu_1024x768.png not loaded"<<std::endl;
      }
  }

  _sprite.setTexture(texture);
  
  
   
  //add Buttons here?
  //Button<retrun type>(action,std::string pathToTexture_, float width_, float height_, float xPos_, float yPos_);
  Button<MainMenu::MenuResult> playButton_B(
      MainMenu::Play,
      "../textures/generic_playButton_120x60.png", 
      "../textures/generic_playButton_120x60_active.png", 
      (SCREEN_WIDTH/2)-60.0, (SCREEN_HEIGHT/2)+40.0 );
  playButton_B.initButton();
  _menuItems.push_back(playButton_B);
  
  Button<MainMenu::MenuResult> exitButton_B(
      MainMenu::Exit,
      "../textures/generic_exitButton_120x60.png", 
      "../textures/generic_exitButton_120x60_active.png", 
      (SCREEN_WIDTH/2)-60, (SCREEN_HEIGHT/2)-40);
  exitButton_B.initButton();
  _menuItems.push_back(exitButton_B);
  
  // draw menu
  drawMenu(window);

  return GetMenuResponse(window);
}

// check click event
MainMenu::MenuResult MainMenu::HandleClick(const sf::Vector2i&  mousePos)
{
  std::list<Button<MainMenu::MenuResult> >::iterator it;

  for ( it = _menuItems.begin(); it != _menuItems.end(); it++){
        if(it -> checkClick(mousePos)){
            return it -> GetbuttonAction();
        }
  }
  return Nothing;
}

// check if button should be framed if mouse is on top
void MainMenu::HandleMouseposition(const sf::Vector2i& mousePos)
{
  std::list<Button<MainMenu::MenuResult> >::iterator it;

  for ( it = _menuItems.begin(); it != _menuItems.end(); it++){
      it -> checkMouseposition(mousePos);
  }
}

void MainMenu::drawMenu(sf::RenderWindow& window){
    // clear window
    window.clear(sf::Color(255,255,255));
  
    // draw backround sprite
    window.draw(_sprite); 
    
    std::list<Button<MainMenu::MenuResult> >::iterator it;
    for ( it = _menuItems.begin(); it != _menuItems.end(); it++){
        window.draw(it -> GetbuttonSprite());
    }
    
    //display stuff
    window.display();
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
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
        //std::cout<< "check Mouse position"<<std::endl;
        HandleMouseposition(sf::Mouse::getPosition(window));
        //redraw all
        drawMenu(window);
      }

      if(menuEvent.type == sf::Event::Closed){
        return Exit;
      }
    }

  }
}
