
#ifndef GHOUST_H
#define GHOUST_H
#include "Level2.h"
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <string>
using namespace std  ;



class ghoust
{
     public:
       int x =0  ;
       float ghos_x , ghos_y ;
       bool move_direaction =1 ;
       float ghosMove_X , ghosMove_y ;
       sf::Texture ghoust_texture ;
       sf::Sprite  ghoust_sprite ;
       int countR=0 ;
       bool die = 0 ;
       sf::SoundBuffer buffer_ghoust;
       sf::Sound sound_ghoust;
       sf::SoundBuffer buffer_mario_die;
       sf::Sound sound_mario_die;
      sf::Texture  ghoust_fire ;    bool ghoust_fireB  ;

      int xf =0 , yf=0 ; int countf =0 ;
      int space ;

    public:

        ghoust(float ghos_x ,float ghos_y  , int s);
        bool ghoust_collision_die(sf::Sprite mario , int  ) ;
        bool mario_collision_die(sf::Sprite mario , int  ) ;
        void ghoust_moving() ;
        void ghoustMoving();
            bool ghoust_die();

        sf::Sprite sprite() ;
        void loadghoust();
        virtual ~ghoust();
};

#endif // GHOUST_H


