/* header containing all includes
 * */
#ifndef GENERIC_FULL_H
#define GENERIC_FULL_H

/** @file GenericFullHeader.h
 * @author Martin Wengenmayr
 * @date 23.03.2017
 * @brief summary of includes
 * 
 * @todo to be removed 
 * when dependencies are fully resolved in the source files
 */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

//window size (globally defined once)
#include "windowSize.h"

//helper classes: button
#include "Button.h"

// features and handling of the game itsself
#include "Game.h"
// features of the splash screen
#include "SplashScreen.h"
// features of the main menue
#include "MainMenu.h"
// features of the pause menue
#include "PauseScreen.h"


// standart includes
#include <iostream>
#include <map>
#include <list>

#endif //GENERIC_FULL_H