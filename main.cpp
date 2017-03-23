
#include "GenericFullHeader.h"

int main()
{
    std::cout<<"starting Game\n";

    sf::RenderWindow mainWindow;

    // set the game state to Uninitialized (=0)
    GameState_t state(Uninitialized);

    //construct main class with 0=uninitilised and main window
    Game theGame(state, mainWindow);

    theGame.Start();

    return EXIT_SUCCESS;
}
