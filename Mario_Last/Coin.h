#ifndef COIN_H
#define COIN_H

#include "Level2.h"
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <string>
using namespace std  ;


class Coin
{
    public:
     sf::Texture coin_texture ;
     sf::Sprite  coin_sprite ;
     int x =0   , countC =0 ;
     bool  coin_hide  ;
        sf::SoundBuffer buffer_coin;
        sf::Sound sound_coin;

    public:
        Coin(float coin_X , float coin_Y , int order );
        void  loadcoin(int order ) ;
        void coin_animation(int order) ;
        sf::Sprite sprite() ;
        bool coin_ate(sf::Sprite mario ) ;
        virtual ~Coin();

};

#endif // COIN_H
