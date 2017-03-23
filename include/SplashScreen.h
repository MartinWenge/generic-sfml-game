#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "GenericFullHeader.h"

class SplashScreen
{
    public:
        SplashScreen();
        virtual ~SplashScreen();

        void Show(sf::RenderWindow& window);
};

#endif // SPLASHSCREEN_H
