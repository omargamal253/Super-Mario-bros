#include "Ghoust.h"
#include"menu.h"
#include "Level2.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std  ;

ghoust::ghoust(float ghos_X,float ghos_Y, int s )
{
    loadghoust() ;
    ghos_x =ghos_X, ghos_y = ghos_Y ;
    ghoust_sprite.setPosition(ghos_X, ghos_Y  ) ;
    ghoust_sprite.setTextureRect(sf::IntRect( x * 43.5,0,  43.5,33) )  ;
    ghosMove_X= ghos_X  ;
    ghosMove_y = ghos_Y   ;


    if (!ghoust_fire.loadFromFile("fireAnimation.png"))
    {
        cout<< " images_ghoust not fouaaaaand texture" << endl ;
    }

    ghoust_fireB  =0 ;
    space = s ;
}

void ghoust::ghoust_moving(   )
{
    if(die == 0)
    {
        if(ghosMove_X == ghos_x + space)
            move_direaction =0 ;
        if( ghosMove_X  == ghos_x )
            move_direaction =1 ;
        if(move_direaction ==1)
        {
            countR++ ;
            if(countR ==16)
                countR =0 ;
            if(countR%8== 0)
            {
                ghoust_sprite.setTextureRect(sf::IntRect( x * 43.5,0,  43.5,33) )  ;
                x++ ;
                if( x==2 )
                    x =0 ;
            }
            ghosMove_X +=  4  ;
            ghoust_sprite.setPosition(  ghosMove_X, ghos_y  ) ;

        }
        else
        {

            ghosMove_X -=  4  ;
            ghoust_sprite.setPosition(  ghosMove_X, ghos_y  ) ;
            countR++ ;
            if(countR ==16)
                countR =0 ;
            if(countR%8== 0)
            {
                ghoust_sprite.setTextureRect(sf::IntRect(x * 43.5,0,  43.5,33)) ;
                x++ ;
                if( x==2 )
                    x =0 ;
            }
        }

    }


}
sf::Sprite ghoust::sprite()
{
    return ghoust_sprite ;
}
bool ghoust::ghoust_collision_die(sf::Sprite mario, int  ground)
{

    if (  ghoust_sprite.getGlobalBounds().intersects(mario.getGlobalBounds()) &&
            mario.getPosition().y <  ground - (65 +20)      )
    {

        //cout<<mario.getPosition().y <<endl ;
            if(!buffer_ghoust.loadFromFile(("smb3_tail.wav")))
        {

            cout<<"Not Found"<<endl;
        }

        sound_ghoust.setBuffer(buffer_ghoust);
        sound_ghoust.play();

        ghoust_sprite.setTextureRect(sf::IntRect(2 * 43.5,10,  43.5,16)) ;

        ghoust_sprite.setPosition( ghosMove_X, ghos_y +34 ) ;
        die = 1 ;

        return 1 ;
    }
    else
        return 0 ;
}

bool ghoust::mario_collision_die(sf::Sprite mario, int ground )
{


    if(  ghoust_sprite.getGlobalBounds().intersects(mario.getGlobalBounds()) &&
            ( mario.getPosition().y ==   ground - 65  ) && die == 0    )
    {

   	   if(!buffer_mario_die.loadFromFile("smb_mariodie.wav"))
    {

        cout<<"Not found"<<endl;
    }


    sound_mario_die.setBuffer(buffer_mario_die);
    sound_mario_die.play();

//    m.music_frist.stop();
        return true  ;
    }

    else
        return false  ;

}

void ghoust::loadghoust()
{
    if (!ghoust_texture.loadFromFile("images_ghoust.png"))
    {
        cout<< " images_ghoust not fouaaaaand texture" << endl ;
    }
    ghoust_sprite.setTexture( ghoust_texture ) ;


}


bool ghoust::ghoust_die()
{
    // sf::Clock clock ;
    //sf::Time t1 = clock.getElapsedTime();
    die = 1 ;
    ghoust_sprite.setTexture( ghoust_fire ) ;
    //ghoust_sprite.setPosition(ghoust_sprite.getPosition().x , ghos_y - 10 ) ;
    if(ghoust_fireB==1)
    {
        countf++ ;
        if(countf%4==0)
        {

            ghoust_sprite.setTextureRect(sf::IntRect(xf*62.5, yf*62.5, 62.5, 62.5)) ;
            xf++ ;
            if(xf>3)
            {
                xf=0 ;
                yf++ ;
            }
            if(yf>3)
            {
                ghoust_sprite.move(0,500) ;

                return true ;
            }
            else
            {
                ghoust_sprite.setPosition(ghoust_sprite.getPosition().x, ghos_y - 20 ) ;
                return false ;
            }

        }

    }
    // }


}



ghoust::~ghoust()
{
    //dtor
}
