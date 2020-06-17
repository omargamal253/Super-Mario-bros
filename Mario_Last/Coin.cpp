#include "Coin.h"

Coin::Coin(float coin_X , float coin_Y ,int order  )
{
    loadcoin( order ) ;
     coin_hide = 0 ;
     coin_sprite.setPosition(coin_X , coin_Y  ) ;
     coin_sprite.setTextureRect(sf::IntRect( x * 27.17  ,0 ,  27.17,29) )  ;
}

void Coin::coin_animation(int order) {
     if(order == 3)
        {
            if(coin_hide ==0)
            {
                x++ ;
                if (x==6)
                    x =0 ;
                countC++ ;
                if(countC%4 ==0 )
                 coin_sprite.setTextureRect(sf::IntRect(  x * 25.83  ,0 ,  25.83 , 29 ) )  ;
                if(countC==32)
                 countC =0 ;
             }
         }
      else
        {
             if(coin_hide ==0)
               {
                   x++ ;
                   if (x==6)
                    x =0 ;
                   countC++ ;
                   if(countC%4 ==0 )
                    coin_sprite.setTextureRect(sf::IntRect(  x * 27.17  ,0 ,  27.17,29 ) )  ;
                   if(countC==32)
                    countC =0 ;
                }

        }

}
/* sf::Sprite Coin::sprite() {
    return coin_sprite ;
 }
/*********************************************************************************************/
void Coin::loadcoin(int coinType ){

   if(coinType== 1)
    {
        if (!coin_texture.loadFromFile("toppng.com-click-for-full-sized-image-coins-mario-coin-sprite-sheet-811x590Copy.png"))
          {
           cout<< " coin_texture not fouaaaaand texture" << endl ;
          }
    }
   else if (coinType== 2)
   {
        if (!coin_texture.loadFromFile("coinBlue.png"))
         {
          cout<< " coin_texture not fouaaaaand texture" << endl ;

         }
   }
    else if (coinType== 3)
   {

        if (!coin_texture.loadFromFile("coin.png"))
         {
          cout<< " coin_texture not fouaaaaand texture" << endl ;

         }
    }

   coin_sprite.setTexture( coin_texture ) ;


}
bool Coin::coin_ate(sf::Sprite mario ) {
   if( mario.getGlobalBounds().intersects(coin_sprite.getGlobalBounds() ) ) {

          coin_hide = 1 ;
          coin_sprite.move(0 ,1000);
   if(!buffer_coin.loadFromFile("smb_coin.wav"))
   {
    cout<<"Not Found"<<endl;
   }
   sound_coin.setBuffer(buffer_coin);
   sound_coin.play();
      return true  ;
      }else return false ;
}

Coin::~Coin()
{
    //dtor
}
