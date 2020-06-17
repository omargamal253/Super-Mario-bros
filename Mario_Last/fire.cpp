#include "fire.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std  ;
fireball::fireball(bool diraction_Of_fire)
{
    diraction = diraction_Of_fire ;
    x =-1 ;
    if (!fireball_texture.loadFromFile("fireBall_animation2.png"))
    {
        cout<< " fireball_texture not found" << endl ;
    }
    fireball_sprite.setTexture(fireball_texture) ;
    fireball_sprite.setTextureRect(sf::IntRect(84,0,  44,23 )) ;

}
void fireball::fireBall_moving(sf::Sprite mario  )
{
    if(!fireout(mario))
    {
        if (x == -1)
            fireball_sprite.setPosition(mario.getPosition().x, mario.getPosition().y +25  ) ;
        x++ ;
//  fireball_sprite.setTextureRect(sf::IntRect(x* 100  ,0 ,  100 ,43 )) ;
        // if(x>2) x=0 ;
        if( diraction== 1 )
            fireball_sprite.move( 10, 0 ) ;
        else
            fireball_sprite.move( -10, 0 ) ;
    }
    else
        fireball_sprite.setPosition( mario.getPosition().x +600, 200) ;
        if(!buffer_fire.loadFromFile("smb3_fireball.wav"))
        {
            cout<<"Not Found"<<endl;
        }
        sound_fire.setBuffer(buffer_fire);
        sound_fire.play();
}
bool  fireball::fireout(sf::Sprite mario )
{

    return  ( fireUsed == 1 || fireball_sprite.getPosition().x >= mario.getPosition().x +600) ;
}
sf::Sprite fireball::sprite()
{
    return fireball_sprite ;
}




fireball::~fireball()
{
    //dtor
}
