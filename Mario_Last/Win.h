#ifndef WIN_H
#define WIN_H
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include"Level2.h"
using namespace std;

class Win
{
    public:
        Win();
        sf::SoundBuffer buffer_win;
        sf::Sound sound_win;
        bool winGame(sf::Sprite,int ground,sf::RenderWindow&,int&,int);
        /** Default destructor */
        virtual ~Win();

    protected:

    private:
};

#endif // WIN_H
