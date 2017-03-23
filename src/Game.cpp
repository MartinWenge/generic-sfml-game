#include "Game.h"

/** @file Game.cpp
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief implementation of generall game class
 */

// constructor with state and window
Game::Game(GameState_t state, sf::RenderWindow& window):
      _gameState(state),
      _mainWindow(window)
{}

// default destructor
Game::~Game()
{}

// start function called from main
void Game::Start(void){
    // check if game is "plain", if not stop here
    if(_gameState != Uninitialized)
        return;

    // start window
    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32),"MyGame");
    // set frame rate
    _mainWindow.setFramerateLimit(60);

    // start with Splah window
    _gameState= ShowingSplash;

    // run the game in the game loop until exit state is chosen
    while(!IsExiting()){
        GameLoop();
    }

    // close window after game loop
    _mainWindow.close();

}

bool Game::IsExiting()
{
  if(_gameState == Exiting) 
    return true;
  else 
    return false;
}

void Game::ShowSplashScreen()
{
    // create instance of class SplashScreen
    SplashScreen splashScreen;
    // run the splash Screen programm
    splashScreen.Show(_mainWindow);
    // change the game state
    _gameState = ShowingMenu;
}

void Game::ShowMenu()
{
    // create instance of class MainMenue
    std::cout<<"start main menu"<<std::endl;
    MainMenu mainMenu;

    // get the click event result from window
    MainMenu::MenuResult result( mainMenu.Show(_mainWindow) );
    switch(result)
    {
    case MainMenu::Exit:
        _gameState = Exiting;
        break;

    case MainMenu::Play:
        _gameState = Playing;
        break;
    }
}

void Game::ShowPause()
{
    // create instance of class PauseScreen
    PauseScreen pauseScreen;
    
    // get the click event result from window
    PauseScreen::PauseResult result( pauseScreen.Show(_mainWindow) );
    switch(result)
    {
    case PauseScreen::Exit:
        _gameState = Exiting;
        break;

    case PauseScreen::Play:
        _gameState = Playing;
        break;
    }
}


void Game::ShowPlay()
{
    _mainWindow.clear(sf::Color(255,255,255)); // window wite
    //_mainWindow.clear(sf::Color(0,0,0)); // window black

    _mainWindow.display();
    
    
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {
        // if close is pressed exit
        if(currentEvent.type == sf::Event::Closed)
             _gameState = Exiting;
	  
        //if a key is pressed check if ...
        if(currentEvent.type == sf::Event::KeyPressed){
            // ... we want to exit with Escape
            if(currentEvent.key.code == sf::Keyboard::Escape)
                _gameState = ShowingMenu;
            // .. we want to pause with "Pause Untbr"
            if(currentEvent.key.code == sf::Keyboard::Pause)
                 _gameState = Paused;
        }
                
        if(currentEvent.type == sf::Event::LostFocus)
            _gameState = Paused;
        
    }
    return;

}


void Game::GameLoop()
{

    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {

        switch(_gameState)
        {
            case ShowingSplash:
            {
                std::cout << "gameLoop: Showing Splash"<<std::endl;
                ShowSplashScreen();
                break;
            }

            case ShowingMenu:
            {
                std::cout << "gameLoop: Showing Main Menu"<<std::endl;
                ShowMenu();
                break;
            }
            
            case Paused:
            {
                std::cout << "gameLoop: Pause Screen"<<std::endl;
                ShowPause();
                
                // check if pause keyboard is pressed again to resume
                if(currentEvent.type == sf::Event::KeyPressed){
                    if(currentEvent.key.code == sf::Keyboard::Pause)
                        _gameState = Playing;
                }
                
                break;
                    
            }

            case Playing:
            {
                std::cout << "gameLoop: Run the play case"<<std::endl;
                ShowPlay();
                
                // if close is pressed exit
                if(currentEvent.type == sf::Event::Closed)
                    _gameState = Exiting;
	  
                //if a key is pressed check if ...
                if(currentEvent.type == sf::Event::KeyPressed){
                    // ... we want to exit with Escape
                    if(currentEvent.key.code == sf::Keyboard::Escape)
                        _gameState = ShowingMenu;
                    // .. we want to pause with "Pause Untbr"
                    if(currentEvent.key.code == sf::Keyboard::Pause)
                        _gameState = Paused;
                }
                
                if(currentEvent.type == sf::Event::LostFocus)
                    _gameState = Paused;
                    
                break;

            }
            
        }
    }
}
