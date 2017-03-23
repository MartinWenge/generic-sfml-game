#include "SplashScreen.h"
#include "Game.h"

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
  std::cout<<"splash screen\n";

  //load texture
  sf::Texture texture;
  if(SCREEN_WIDTH==800){
    if(texture.loadFromFile("../textures/generic_splash_800x600.png") != true)
    {
      return;
    }
  }else if(SCREEN_WIDTH==1024){
    if(texture.loadFromFile("../textures/generic_splash_1024x768.png") != true)
    {
      return;
    }
  }

  // bind texture to sprite
  sf::Sprite sprite(texture);

  // display the sprite only
  renderWindow.draw(sprite);
  renderWindow.display();

  // skip splash screen by pressing anything using poll event (slow)
  sf::Event event;
  while(true)
  {
    while(renderWindow.pollEvent(event))
    {
      if(event.type == sf::Event::KeyPressed
        || event.type == sf::Event::MouseButtonPressed
        || event.type == sf::Event::Closed )
      {
        return;
      }
    }
  }
}
