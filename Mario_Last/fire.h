#ifndef FIREBALL_H
#define FIREBALL_H
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
using namespace std  ;

class fireball
{
       public:
           int x ;
           sf::Texture fireball_texture ;
           sf::Sprite fireball_sprite ;
          bool diraction ;
          bool fireUsed =0 ;
          sf::SoundBuffer buffer_fire;
          sf::Sound sound_fire;
    public:

        fireball(bool diraction_Of_fire);
        virtual ~fireball();
         bool  fireout(sf::Sprite mario ) ;
        void fireBall_moving(sf::Sprite mario );
        sf::Sprite sprite();

    protected:

    private:
};

#endif // FIREBALL_H
