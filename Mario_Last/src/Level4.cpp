
#include "Level4.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>  // for string streams
#include <string>
using namespace std  ;
#include "../Ghoust.h"
#include "../Coin.h"
#include"../Win.h"
#include"../page2.h"
#include"../menu.h"
#include "../fire.h"
void Level4::loadFiles(){

  window.create(sf::VideoMode(800, 600), "Super Mario");




         if (!texture.loadFromFile("smb_mario_sheet3last.png"))
{
   cout<< " not fouaaaaand texture" << endl ;
}
if (!mario_die_texture.loadFromFile("8c57e1d242cac95436cf6d26babf709f.png"))
{
   cout<< " mario_die_texture not fouaaaaand texture" << endl ;
}
if (!gameOver_texture.loadFromFile("MarioMaker_GameOver.png"))
{
   cout<< " gameOver_texture not fouaaaaand texture" << endl ;
}


if (!font.loadFromFile("MAGNETOB.ttf"))
{
 cout<< " font not found "<< endl ;
}

       view.setCenter(sf::Vector2f(300, 300));

view.setSize(sf::Vector2f(1000.f, 600.f));

    //   window.setFramerateLimit(15) ;

   mario.setTexture(texture) ;




       mario.setTextureRect(sf::IntRect(220 , 0, 27.5 ,60)) ;
      /////////////
  mario.setPosition(150 , 300) ;

   //to function loadscore

    if (!coin_texture2.loadFromFile("coinBlue-removebg-preview.png"))
{
cout<< " coin_texture not fouaaaaand texture" << endl ;
}
  if (!ghoust_texture2.loadFromFile("images_ghoust.png"))
{
 cout<< " coin_texture not fouaaaaand texture" << endl ;
}

coin_sprite2.setTexture( coin_texture2 ) ;
coin_sprite2.setTextureRect(sf::IntRect(  0 * 27.17  ,0 ,  27.17,29 ) )  ;

ghoust_sprite2.setTexture( ghoust_texture2 ) ;
ghoust_sprite2.setTextureRect(sf::IntRect(  0  ,0 ,  43.5 ,33 ) )  ;

    text_score.setFont(font) ;
    text_score.setCharacterSize(30) ;
    text_score.setFillColor(sf::Color(4,9,55 ));



    text_score2.setFont(font) ;
    text_score2.setCharacterSize(30) ;
    text_score2.setFillColor(sf::Color(4,9,55 ));


    texttimer.setFont(font) ;
    texttimer.setCharacterSize(30) ;
    texttimer.setFillColor(sf::Color(4,9,55 ));


    textTime.setFont(font) ;
    textTime.setCharacterSize(30) ;
    textTime.setFillColor(sf::Color(160,0,0 ));

    textTime.setString("Time") ;

    if (!finsh_textture.loadFromFile("finsh.png"))
{
   cout<< " finsh_textture not fouaaaaand " << endl ;
}
finsh_sprite.setTexture(finsh_textture) ;
finsh_sprite.setPosition(6700,95) ;
}
void Level4::loadMap(){
    if (!texturesun.loadFromFile("images__.png"))
{
   cout<< " not fouaaaaand texture" << endl ;
}
if (!textureGround.loadFromFile("pygame_flattened.png"))
{
   cout<< " not fouaaaaand texture" << endl ;
}

 int map2[4][20]={           3,0,3,0,3,0, 0,0,0,0,0,0,4,0,0,0,0,0,0,0,
                             0,0,0,0,0,0, 0,4,4,0,0,4,0,4,0,0,0,0,0,0,
                             0,2,4,2,4,0, 2,0,0,0,4,0,0,0,4,0,0,0,0,0,
                             1,0,1,1,0,1, 0,0,0,1,0,0,0,0,0,1,1,0,0,0,

                       };
                       for(int i=0 ;i<4 ;i++){
                        for(int j=0 ; j<20 ;j++){
                            if(map2[i][j]==1){
                                map1[i][j].setTexture(textureGround);
                                   map1[i][j].setTextureRect(sf::IntRect(0 ,360, 600 ,115)) ;
                            }
                            else if(map2[i][j]==2){
                                map1[i][j].setTexture(textureGround);
                                  map1[i][j].setTextureRect(sf::IntRect(0 ,360, 200 ,50)) ;

                            }
                             else if(map2[i][j]==4){
                                map1[i][j].setTexture(textureGround);
                                  map1[i][j].setTextureRect(sf::IntRect(0 ,360, 100 ,50)) ;

                            }
                            else if(map2[i][j]==3){
                                map1[i][j].setTexture(texturesun);
                            }

                        }
                       }

map1[3][0].setPosition(0 , 495) ;

map1[2][1].setPosition(600, 350) ;
map1[3][2].setPosition(800 , 495) ;
map1[3][3].setPosition(1400 , 495) ;
map1[2][3].setPosition(1400 , 340) ;

map1[3][5].setPosition(2200 , 495) ;
map1[2][6].setPosition(2800 , 330) ;

map1[1][7].setPosition(3130 , 260) ;
map1[1][8].setPosition(3350 , 210) ;


map1[2][2].setPosition(2050 , 350) ;

map1[2][4].setPosition(5750 +500 , 350) ;
//
map1[3][9].setPosition(3550, 495) ;

map1[2][10].setPosition(4900 -600, 350) ;

map1[1][11].setPosition(5200-650 , 310) ;
map1[0][12].setPosition(5500-700 , 260) ;
map1[1][13].setPosition(5800-700 , 310) ;
map1[2][14].setPosition(6100-700, 350) ;

map1[3][15].setPosition(5750-100 , 495) ;
map1[3][16].setPosition(5750+600-100 , 495) ;





//sun
map1[0][0].setPosition(100 , 50) ;
map1[0][2].setPosition(900 , 50) ;
map1[0][4].setPosition(1600 , 50) ;

                  for(int i=0 ;i<4 ;i++){
                        for(int j=0 ; j<20 ;j++){
                            if(map2[i][j]==1|| map2[i][j]==2 || map2[i][j]==3 || map2[i][j]==4){
                               window.draw( map1[i][j] ) ;
                            }


                        }
                       }

}

Level4::Level4()
{



 vector<fireball> fireballV ;

/*
 vector<fireball> ::iterator it ;
  fireball  *f = new fireball() ;

fireballV.push_back(*f) ;
//fireballV.at(0).fireBall_moving()
  //it= fireballV.begin() ;
*/


           int active_window;
           velocity.x=0 ;
           velocity.y=0 ;
           coin_score = 0;
           t1 = sf::seconds(100.f);

  vector <ghoust> g ;

       ghoust   g1(100 ,462 ,300) ; g.push_back(g1) ;
       ghoust  g2 (800 ,462,300) ; g.push_back(g2) ;
       ghoust  g3 (1300 ,462,300) ; g.push_back(g3) ;
       ghoust  g4 (850 ,462,300) ; g.push_back(g4) ;
       ghoust  g5 (1350 ,462,300) ; g.push_back(g5) ;

       ghoust  g6 (1350+300 ,462 ,300) ; g.push_back(g6) ;
       ghoust  g7 (1300+250 ,462,300) ; g.push_back(g7) ;

       ghoust  g8 (1350+1000 ,462,300) ; g.push_back(g8) ;
       ghoust  g9 (1300+1100 ,462,300) ; g.push_back(g9) ;

       ghoust  g10 (1350+1000+400 ,300 ,150) ; g.push_back(g10) ;
       ghoust  g11 (1300+2400 ,462,300) ; g.push_back(g11) ;


    loadFiles() ;

vector <Coin> c ;

    Coin c1( 200 ,462 , 2 ) ;  c.push_back(c1);
     Coin c2( 250 ,462 , 2) ; c.push_back(c2);
      Coin c3( 300 ,462 , 2 ); c.push_back(c3);
       Coin c4( 350 ,462 , 2) ; c.push_back(c4);

         Coin c5( 620 ,315 , 2 ) ; c.push_back(c5);
     Coin c6( 670 ,315 , 2) ; c.push_back(c6);
      Coin c7( 720 ,315 , 2 ); c.push_back(c7);
       Coin c8( 770 ,315 , 2) ; c.push_back(c8);

         Coin c9( 900 ,462 , 2 ) ; c.push_back(c9);
     Coin c10( 950 ,462  , 2) ; c.push_back(c10);
      Coin c11( 1000 ,462  , 2 ); c.push_back(c11);
       Coin c12( 1050 ,462  , 2) ; c.push_back(c12);

         Coin c13( 900 ,430 , 2 ) ; c.push_back(c13);
     Coin c14( 950 ,430  , 2) ; c.push_back(c14);
      Coin c15( 1000 ,430  , 2 ); c.push_back(c15);
       Coin c16( 1050 ,430  , 2) ; c.push_back(c16);

       Coin c17( 1400 ,300 , 2) ; c.push_back(c17);
     Coin c18( 1450 ,300  , 2) ; c.push_back(c18);
      Coin c19( 1500 ,300  , 2 ); c.push_back(c19);
       Coin c20( 1550 ,300  , 2) ; c.push_back(c20);

       Coin c21( 2050 ,310  , 2) ; c.push_back(c21);
       Coin c22( 2100 ,310  , 2) ; c.push_back(c22);

       Coin c23( 2800 , 295 , 2 ) ; c.push_back(c23);
       Coin c24( 2850 , 295 , 2 ) ; c.push_back(c24);
       Coin c25( 2900 , 295 , 2 ) ; c.push_back(c25);
       Coin c26( 2950 , 295 , 2 ) ; c.push_back(c26);

       Coin c27( 3800 , 460 , 2 ) ; c.push_back(c27);
       Coin c28( 3850 , 460 , 2 ) ; c.push_back(c28);
       Coin c29( 3900 , 460 , 2 ) ; c.push_back(c29);
       Coin c30( 3950 , 460 , 2 ) ; c.push_back(c30);

       Coin c31( 3800 , 426 , 2 ) ; c.push_back(c31);
       Coin c32( 3850 , 426 , 2 ) ; c.push_back(c32);
       Coin c33( 3900 , 426 , 2 ) ; c.push_back(c33);
       Coin c34( 3950 , 426 , 2 ) ; c.push_back(c34);

       marioDie = 0 ;


     while (window.isOpen())
    {

           sf::Event event;

         for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
            {
                mario_died() ; marioDie = 1 ;
            }
         }
/*
        if ( g1.mario_collision_die(mario , groundHeight) ||
              g2.mario_collision_die(mario , groundHeight) ||
             g3.mario_collision_die(mario , groundHeight) ||
             g4.mario_collision_die(mario , groundHeight) )
            {
              mario_died() ; marioDie = 1 ;
            }
   */
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(mario.getPosition().y ==  groundHeight - 65 &&  mario.getPosition().y > 565  ) {
                mario.setPosition(mario.getPosition().x , 500 ) ;
            mario_died() ;
        marioDie = 1 ;
        }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

            for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
             {
                mario_died() ; marioDie = 1 ;
            }
         }
         /*
        if ( g1.mario_collision_die(mario , groundHeight) ||
              g2.mario_collision_die(mario , groundHeight) ||
             g3.mario_collision_die(mario , groundHeight) ||
             g4.mario_collision_die(mario , groundHeight)  )
            {
              mario_died() ; marioDie = 1 ;
            }
*/
               if( marioDie == 0 && finsh ==0){
               countL++ ;  if(countL >10) countL =0 ;
               if(countL%2== 0){
                y=0 ;
                   x++ ; if(x>5) x=1 ;
                    mario.setTextureRect(sf::IntRect(220-(x * 27.5 ) , y * 60 ,  27.5 ,60)) ;
               }
                view.move(  -4 ,0) ;  velocity.x= -movespeed ;
               }

          diraction_Of_fire =0 ;
      }

     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

       for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
             {
                mario_died() ; marioDie = 1 ;
            }
         }
/*
            if ( g1.mario_collision_die(mario , groundHeight) ||
              g2.mario_collision_die(mario , groundHeight) ||
             g3.mario_collision_die(mario , groundHeight) ||
                 g4.mario_collision_die(mario , groundHeight) )
            {
              mario_died() ; marioDie = 1 ;
            }
*/
              if( marioDie == 0 && finsh ==0){
            countR++ ;  if(countR >10) countR =0 ;
      if(countR%2== 0){
              y=0;
                x++ ; if(x>4) x=0 ;
                    mario.setTextureRect(sf::IntRect(220+(x * 27.5) , y * 60 ,  27.5 ,60)) ;

                  }


                 view.move(  4 ,0) ; velocity.x= movespeed ;
              }

      diraction_Of_fire =1 ;
    }
     else velocity.x=0 ;



if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space  )  ){

     for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
            {
                mario_died() ; marioDie = 1 ;
            }
         }
            /*if ( g1.mario_collision_die(mario , groundHeight) ||
              g2.mario_collision_die(mario , groundHeight) ||
             g3.mario_collision_die(mario , groundHeight) ||
                 g4.mario_collision_die(mario , groundHeight)  )
            {
              mario_died() ; marioDie = 1 ;
            }*/

                if( marioDie == 0 && finsh ==0){
              //   y=1;
            // x++ ; if(x>5) x=0 ;
    //  mario.setTextureRect(sf::IntRect(220+(x * 27.5) , y * 60 ,  27.5 ,60)) ;

                    /*if(  mario.getPosition().y < 240){

                 velocity.y = -0.3 ;
                } else{

                   velocity.y = -jumpSpeed ;
                  }
                  */

                velocity.y = -jumpSpeed ;
                }
}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space  )  &&
          sf::Keyboard::isKeyPressed( sf::Keyboard::Left  )   ){
           for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
            {
               mario_died() ; marioDie = 1 ;
            }
         }
          /*
           if ( g1.mario_collision_die(mario , groundHeight) ||
              g2.mario_collision_die(mario , groundHeight) ||
             g3.mario_collision_die(mario , groundHeight) ||
                g4.mario_collision_die(mario , groundHeight) )
            {
              mario_died() ; marioDie = 1 ;
            } */
              if( marioDie == 0 && finsh ==0 ){
              //   y=1;
            // x++ ; if(x>5) x=1 ;
                  //  mario.setTextureRect(sf::IntRect(220-(x * 27.5) , y * 60 ,  27.5 ,60)) ;

                  velocity.y = -jumpSpeed ;
              }


}


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C  )  ){
              count_fire++ ;
              if(count_fire%6==0){
                fireball  *f = new fireball( diraction_Of_fire) ;

                 fireballV.push_back(*f) ;
              }
                }

                for(int i=0 ;i<fireballV.size() ;i++){
                    fireballV.at(i).fireBall_moving(mario  ) ;
                }

                    collision(1) ;

        if(mario.getPosition().y + 65 <groundHeight || velocity.y <0 )
            {

              velocity.y+=gravity ;
            }
        else {

              mario.setPosition(mario.getPosition().x , groundHeight - 65) ;
             velocity.y=0 ;


        }

         mario.move(velocity.x , velocity.y) ;
          window.setView(view) ;

       window.clear(sf::Color(51,153,204,0.1 ));
          window.draw(finsh_sprite) ;
         loadMap() ;
          drawing() ;
   for(int i =0 ;i< g.size() ; i++){
         g.at(i).ghoust_moving() ; window.draw(g.at(i).ghoust_sprite);
         }
/*
         g1.ghoust_moving() ; window.draw(g1.ghoust_sprite);
         g2.ghoust_moving() ; window.draw(g2.ghoust_sprite);
         g3.ghoust_moving() ; window.draw(g3.ghoust_sprite);
         g4.ghoust_moving() ; window.draw(g4.ghoust_sprite); */

           for(int i =0 ;i< g.size() ; i++){
         if( g.at(i).ghoust_collision_die(mario , groundHeight ) ) ghoust_score++  ;
         }
   /*    if( g1.ghoust_collision_die(mario , groundHeight ) ) ghoust_score++  ;
       if(  g2.ghoust_collision_die(mario , groundHeight  ) ) ghoust_score++ ;
       if( g3.ghoust_collision_die(mario , groundHeight ) ) ghoust_score++ ;
        if( g4.ghoust_collision_die(mario , groundHeight ) ) ghoust_score++ ;

*/
        for(int i=0 ;i<c.size() ;i++){
          c.at(i).coin_animation(2) ;
          if(c.at(i).coin_ate(mario))  coin_score++ ;
          else   window.draw(c.at(i).coin_sprite);
        }

/*
    c1.coin_animation(1) ; if(c1.coin_ate(mario))  coin_score++ ; else window.draw(c1.coin_sprite);

    c2.coin_animation(1) ; if(c2.coin_ate(mario))  coin_score++ ; else window.draw(c2.coin_sprite);

        c3.coin_animation(1) ; if(c3.coin_ate(mario))  coin_score++ ; else window.draw(c3.coin_sprite);

     c4.coin_animation(1) ;if(c4.coin_ate(mario))  coin_score++ ; else window.draw(c4.coin_sprite);

      c5.coin_animation(2) ; if(c5.coin_ate(mario))  coin_score++ ; else window.draw(c5.coin_sprite);

      c6.coin_animation(2) ; if(c6.coin_ate(mario))  coin_score++ ; else window.draw(c6.coin_sprite);

    c7.coin_animation(2) ; if(c7.coin_ate(mario))  coin_score++ ; else window.draw(c7.coin_sprite);

    c8.coin_animation(2) ; if(c8.coin_ate(mario))  coin_score++ ;  else window.draw(c8.coin_sprite);



  c9.coin_animation(3) ; if(c9.coin_ate(mario))  coin_score++ ; else window.draw(c9.coin_sprite);


  c10.coin_animation(3) ; if(c10.coin_ate(mario))  coin_score++ ; else window.draw(c10.coin_sprite);

  c11.coin_animation(3) ; if(c11.coin_ate(mario))  coin_score++ ; else window.draw(c11.coin_sprite);

  c12.coin_animation(3) ; if(c12.coin_ate(mario))  coin_score++ ; else window.draw(c12.coin_sprite);

   c13.coin_animation(3) ; if(c13.coin_ate(mario))  coin_score++ ; else window.draw(c13.coin_sprite);

    c14.coin_animation(3) ; if(c14.coin_ate(mario))  coin_score++ ; else window.draw(c14.coin_sprite);
   c15.coin_animation(3) ; if(c15.coin_ate(mario))  coin_score++ ; else window.draw(c15.coin_sprite);
    c16.coin_animation(3) ; if(c16.coin_ate(mario))  coin_score++ ; else window.draw(c16.coin_sprite);


    c17.coin_animation(1) ; if(c17.coin_ate(mario))  coin_score++ ; else window.draw(c17.coin_sprite);

    c18.coin_animation(1) ; if(c18.coin_ate(mario))  coin_score++ ; else window.draw(c18.coin_sprite);

        c19.coin_animation(1) ; if(c19.coin_ate(mario))  coin_score++ ; else window.draw(c19.coin_sprite);

     c20.coin_animation(1) ;if(c20.coin_ate(mario))  coin_score++ ; else window.draw(c20.coin_sprite);

*/          load_Score(coin_score , ghoust_score) ;

          loadTimer() ;
              g1.ghoust_die();


                 for(int i=0 ;i<fireballV.size() ;i++){
                     for(int j=0 ;j<g.size() ;j++){
           if(fireballV.at(i).sprite().getGlobalBounds().intersects(g.at(j).sprite().getGlobalBounds())   )
           {
               g.at(j).ghoust_fireB= 1;  fireballV.at(i).fireUsed =1 ;
               //fireballV.erase(fireballV.begin()) ;
           }
                     }
                 }

              for(int j=0 ;j<g.size() ;j++){
                if ( g.at(j).ghoust_fireB )
                {   g.at(j).ghoust_die() ;

                  /* if(g.at(j).ghoust_die()) {
                      ghoust_score++ ;
                      g.erase(g.begin()+j) ;
                   }*/
                }
              }

                for(int i=0 ;i<fireballV.size() ;i++){

                   window.draw( fireballV.at(i).sprite() );
                   if( fireballV.at(i).fireout(mario)) fireballV.erase(fireballV.begin()+i) ;
                }
       window.display();
    }

 }


void Level4::drawing(){
window.draw(mario);

   if(marioDie== 1){
       gameOver_sprite.setTexture(gameOver_texture) ;
    gameOver_sprite.setTextureRect( sf::IntRect( 0 ,80  ,800  ,250 ) ) ;
    gameOver_sprite.setPosition( view.getCenter().x -400, view.getCenter().y -190 ) ;
    window.draw(gameOver_sprite) ;
   }

}
bool  Level4::collision(int order) {



if( map1[2][1].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
           mario.getPosition().y +50 < map1[2][1].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][1].getGlobalBounds().top +5 ;

              return true ;

    }
    else if( map1[2][3].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[2][3].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][3].getGlobalBounds().top +5 ;
              return true ;

    }
        else if( map1[2][2].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[2][2].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][2].getGlobalBounds().top +5 ;
              return true ;

    }
    else if( map1[2][4].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[2][4].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][4].getGlobalBounds().top +5 ;
              return true ;

    }
     else if( map1[1][7].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[1][7].getGlobalBounds().top  )
     {

                 groundHeight = map1[1][7].getGlobalBounds().top +5 ;
              return true ;

    }
     else if( map1[1][8].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[1][8].getGlobalBounds().top  )
     {

                 groundHeight = map1[1][8].getGlobalBounds().top +5 ;
              return true ;

    }
 else if( map1[2][6].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[2][6].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][6].getGlobalBounds().top +5 ;
              return true ;

    }
    else if( map1[2][10].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[2][10].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][10].getGlobalBounds().top +5 ;
              return true ;

     }
     else if( map1[1][11].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[1][11].getGlobalBounds().top  )
     {

                 groundHeight = map1[1][11].getGlobalBounds().top +5 ;
              return true ;

     }
      else if( map1[0][12].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[0][12].getGlobalBounds().top  )
     {

                 groundHeight = map1[0][12].getGlobalBounds().top +5 ;
              return true ;

     }
      else if( map1[1][13].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[1][13].getGlobalBounds().top  )
     {

                 groundHeight = map1[1][13].getGlobalBounds().top +5 ;
              return true ;

     }

      else if( map1[2][14].getGlobalBounds().intersects(mario.getGlobalBounds())  &&
             mario.getPosition().y +50 < map1[2][14].getGlobalBounds().top  )
     {

                 groundHeight = map1[2][14].getGlobalBounds().top +5 ;
              return true ;

     }

  else if ( map1[3][0].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
            map1[3][2].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
            map1[3][3].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
            map1[3][5].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
            map1[3][9].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
            map1[3][15].getGlobalBounds().intersects(mario.getGlobalBounds())||
            map1[3][16].getGlobalBounds().intersects(mario.getGlobalBounds())
            )
  {
        groundHeight = 500 ;

      return false ;

  }
  else if (finsh_sprite.getGlobalBounds().intersects(mario.getGlobalBounds())){
    groundHeight = 450 ;
    finsh =1 ;

    Menu m  ;
    window.close() ;
   }

  else  {
      if(marioDie == 1 ) groundHeight = 500 ;
      else  groundHeight = 650 ;
  }


}

bool Level4::mario_died(){



    if (marioDie==0){

        window.close();
        page2(1200,675);

        return true;


}
}
void Level4::load_Score ( int coin_score , int ghoust_score ) {
    //  åäÇ åäÚÑÝ ÇáÏäíÇ ÈÊÇÚÊ  Çá  font   ãÊäÓÇÔ ÈÞÇ  :)

    // declaring output string stream

    // Sending a number as a stream into output
   // if(ghoust_score> 1 ) ghoust_score = 1 ;
    // string
     ostringstream str1;
                ostringstream str2;

    str1 << coin_score;
         str2 << ghoust_score;
    // the str() coverts number into string

     geek = str1.str();
    geek2 = str2.str();

    text_score.setString(geek) ;

    text_score2.setString(geek2) ;

     text_score.setPosition(view.getCenter().x +245 , view.getCenter().y-225  ) ;
    window.draw(text_score) ;
    text_score2.setPosition(view.getCenter().x +140 , view.getCenter().y-225  ) ;
    window.draw(text_score2) ;


    //  åäÇ ÔÛá ÇáÕæÑå Çá ÌäÈ ÇáÑÞã


coin_sprite2.setPosition(view.getCenter().x +285 , view.getCenter().y-220 ) ;
ghoust_sprite2.setPosition(view.getCenter().x +175 , view.getCenter().y-220 ) ;


window.draw(coin_sprite2) ;
window.draw(ghoust_sprite2) ;


}
void Level4::loadTimer() {
  elapsed1 = clock.getElapsedTime();
      if( elapsed1.asSeconds() > 100.0f)
         {
             mario_died() ; marioDie = 1 ;
         }else{
       int a = (t1 - elapsed1).asSeconds() ;
          ostringstream strtimer;

    strtimer << a;
         geek3 = strtimer.str();
         texttimer.setString(geek3) ;

         texttimer.setPosition(view.getCenter().x -245 , view.getCenter().y-225  ) ;

         }
           window.draw(texttimer) ;

   textTime.setPosition(view.getCenter().x -340 , view.getCenter().y-228  ) ;
    window.draw(textTime);


}


Level4::~Level4(){

}
