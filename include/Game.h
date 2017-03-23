#ifndef GAME_H
#define GAME_H

#include "GenericFullHeader.h"


/** @file Game.h
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief definition of generall Game class
 */

//! possible game states
enum GameState_t{
      Uninitialized,
      ShowingSplash,
      Paused,
      ShowingMenu,
      Playing,
      Exiting
};

/** @brief generall game class
 * 
 *  @details 
 * Game class handling the sfml window and the basic game/menu structure
 * 
 * Example Usage:
 * @code
 *  #include "Game.h"
 *  int main(){
 *      sf::RenderWindow mainWindow;
 *      Game theGame(GameState_t(Uninitialized), mainWindow);
 *      theGame.Start();
 *      return 0;
 *  }
 * 
 * @endcode
 */

class Game
{
    public:
        //! constructor handling a game state and the sfml window
        Game(GameState_t state, sf::RenderWindow& window);

        //! empty destructor
        virtual ~Game();
        
        //! game starting function to be used in main function
        void Start(void);

    private:
        //! the game loop, heart of the program
        void GameLoop();

        //! functions handling the game states: starting window
        void ShowSplashScreen();
        //! functions handling the game states: main menu
        void ShowMenu();
        //! functions handling the game states: pause menu
        void ShowPause();
        //! functions handling the game states: play the game
        void ShowPlay();

        //! check for close event to exit the game
        bool IsExiting(); 

        //! the current game state
        GameState_t _gameState;
        
        //! the main sfml window
        sf::RenderWindow& _mainWindow;
        
        //GameObjectManager _gameObjectManager;

};

#endif // GAME_H
