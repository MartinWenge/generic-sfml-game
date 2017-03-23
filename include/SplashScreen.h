#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "GenericFullHeader.h"

/** @file SplashScreen.h
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief definition of SplashScreen class
 */

//! Class showing the start screen
class SplashScreen
{
    public:
        //! default constructor
        SplashScreen();
        //! default destructor
        virtual ~SplashScreen();

        //! function running in the game loop if game state is ShowingSplash
        void Show(sf::RenderWindow& window);
};

#endif // SPLASHSCREEN_H
