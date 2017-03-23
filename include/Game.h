#ifndef GAME_H
#define GAME_H

#include "GenericFullHeader.h"

enum GameState_t{
      Uninitialized,
      ShowingSplash,
      Paused,
      ShowingMenu,
      Playing,
      Exiting};

class Game
{
    public:
        //constructor
        Game(GameState_t state, sf::RenderWindow& window);

        //destructor
        virtual ~Game();
        
        // start the game from main
        void Start(void);

    private:
        // heart of the game: the game loop
        void GameLoop();

        // run the game states
        void ShowSplashScreen();
        void ShowMenu();
        void ShowPause();
        void ShowPlay();

        // check for close event
        bool IsExiting(); 
        //{ (_gameState == Exiting) ? true : false; }

        GameState_t _gameState;
        sf::RenderWindow& _mainWindow;
        
        //GameObjectManager _gameObjectManager;

};

#endif // GAME_H
