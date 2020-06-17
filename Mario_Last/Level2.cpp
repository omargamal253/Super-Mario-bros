#include "Level2.h"
#include"page2.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>  // for string streams
#include <string>
#include <SFML/Window.hpp>
using namespace std  ;
#include "Ghoust.h"
#include "Coin.h"
#include"Win.h"
#include"pageMain.h"
#include"new.h"
#include "fire.h"

#include <vector>
void Level2::loadFiles()
{

    window1.create(sf::VideoMode(800, 600), "My window");



/*                if(!buffer.loadfromfile("m.wav")){
                    cout<<"error";
                }
                sound.setBuufer(buffer);
                sound.play();*/



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
     if(!winPage_p.loadFromFile("MarioMaker_GameOver.png"))
    {
        cout<<"win page not founded";
    }
    view.setCenter(sf::Vector2f(300, 300));
    view.setSize(sf::Vector2f(800.f, 600.f));
    //   window.setFramerateLimit(15) ;
    mario.setTexture(texture) ;
    mario.setTextureRect(sf::IntRect(220, 0, 27.5,57)) ;
    /////////////
    mario.setPosition(150, 300) ;

    //to function loadscore

    if (!coin_texture2.loadFromFile("toppng.com-click-for-full-sized-image-coins-mario-coin-sprite-sheet-811x590Copy.png"))
    {
        cout<< " coin_texture not fouaaaaand texture" << endl ;
    }
    if (!ghoust_texture2.loadFromFile("images_ghoust.png"))
    {
        cout<< " coin_texture not fouaaaaand texture" << endl ;
    }

    coin_sprite2.setTexture( coin_texture2 ) ;
    coin_sprite2.setTextureRect(sf::IntRect(  0 * 27.17,0,  27.17,29 ) )  ;

    ghoust_sprite2.setTexture( ghoust_texture2 ) ;
    ghoust_sprite2.setTextureRect(sf::IntRect(  0,0,  43.5,33 ) )  ;

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
}
void Level2::loadMap()
{
    if (!texturesun.loadFromFile("cloud.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!textureGround.loadFromFile("ground.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!ground2.loadFromFile("ground2.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!groundheigh.loadFromFile("ground.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!star.loadFromFile("star.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!sky.loadFromFile("sky.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!moon.loadFromFile("moon.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!tree.loadFromFile("tree.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!box.loadFromFile("box.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!fire.loadFromFile("fire.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!balata.loadFromFile("balata.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!box2.loadFromFile("box2.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!wood.loadFromFile("wood.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!water.loadFromFile("water.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!small.loadFromFile("small.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!tube.loadFromFile("tube.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if (!player.loadFromFile("player.png"))
    {
        cout << " not fouaaaaand texture" << endl;
    }
    if(!endGame.loadFromFile("end.png"))
    {
        cout<<"endgame picture not found";
    }
    int map2[6][30] = { 3 ,6 ,4 ,3 ,4 ,6 ,3 ,6 ,4 ,6 ,5 ,6 ,3 ,4 ,4 ,3 ,6 ,3 ,6 ,3 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                        0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
                        3 ,10,3 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,19,
                        0 ,0 ,0 ,0 ,13,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,12,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,17,2 ,2 ,
                        13,13,7 ,15,2 ,7 ,17,0 ,15,15,15,2 ,2 ,0 ,15,0 ,13,7 ,2 ,0 ,0 ,17,0 ,0 ,8 ,0 ,2 ,2 ,2 ,2 ,
                        1 ,1 ,14,1 ,0 ,1 ,1 ,1 ,14,1 ,11,0 ,0 ,1 ,1 ,14,1 ,1 ,0 ,0 ,1 ,1 ,14,1 ,1 ,1 ,10,1 ,1 ,1 ,

                      };
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (map2[i][j] == 1)
            {
                map1[i][j].setTexture(textureGround);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 206, 110));
            }
            else if (map2[i][j] == 2)
            {
                map1[i][j].setTexture(groundheigh);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 206, 40));
            }
            else if (map2[i][j] == 3)
            {
                map1[i][j].setTexture(texturesun);
            }
            else if (map2[i][j] == 4)
            {
                map1[i][j].setTexture(sky);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 534, 125));
            }
            else if (map2[i][j] == 5)
            {
                map1[i][j].setTexture(moon);
            }
            else if (map2[i][j] == 6)
            {
                map1[i][j].setTexture(star);
            }
            else if (map2[i][j] == 7)
            {
                map1[i][j].setTexture(tree);
            }
            else if (map2[i][j] == 8)
            {
                map1[i][j].setTexture(box);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 62, 62));
            }
            else if (map2[i][j] == 9)
            {
                map1[i][j].setTexture(ground2);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 223, 100));
            }
            else if (map2[i][j] == 10)
            {
                map1[i][j].setTexture(fire);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 147, 100));
            }
            else if (map2[i][j] == 11)
            {
                map1[i][j].setTexture(balata);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 79, 110));
            }
            else if (map2[i][j] == 12)
            {
                map1[i][j].setTexture(box2);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 32, 32));
            }
            else if (map2[i][j] == 13)
            {
                map1[i][j].setTexture(wood);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 115, 70));
            }
            else if (map2[i][j] == 14)
            {
                map1[i][j].setTexture(water);
                map1[i][j].setTextureRect(sf::IntRect(0, 0, 368, 100));
            }
            else if (map2[i][j] == 15)
            {
                map1[i][j].setTexture(small);
            }
            else if (map2[i][j] == 17)
            {
                map1[i][j].setTexture(tube);
            }
            else if (map2[i][j] == 18)
            {
                map1[i][j].setTexture(player);
            }
            else if (map2[i][j] == 19)
            {
                map1[i][j].setTexture(endGame);
            }
        }
        //sky
        map1[0][0].setPosition(100, 50);
        map1[0][1].setPosition(300, 30);
        map1[0][2].setPosition(500, 50);
        map1[0][3].setPosition(1100, 100);
        map1[0][4].setPosition(1300, 20);
        map1[0][5].setPosition(2000, 30);
        map1[0][6].setPosition(2100, 70);
        map1[0][7].setPosition(2200, 50);
        map1[0][8].setPosition(2400, 70);
        map1[0][9].setPosition(3000, 50);
        map1[0][10].setPosition(3200, 80);
        map1[0][11].setPosition(3400, 30);
        map1[0][12].setPosition(3600, 40);
        map1[0][13].setPosition(3900, 30);
        map1[0][14].setPosition(4600, 30);
        map1[0][15].setPosition(5300, 30);
        map1[0][16].setPosition(5500, 80);
        map1[0][17].setPosition(5600, 50);
        map1[0][18].setPosition(5700, 40);
        map1[0][19].setPosition(5900, 30);
        map1[0][20].setPosition(5900, 50);
        map1[0][21].setPosition(6500, 50);
        map1[0][22].setPosition(7200, 50);
        /***************************************************************************************************/
        map1[2][0].setPosition(100, 50);
        map1[2][2].setPosition(900, 50);
        map1[2][7].setPosition(1800, 50);
        map1[2][1].setPosition(3853 + 500 + 506 + 320 + 230 + 250, 560);
        map1[2][29].setPosition(7500,45);

        /**************************************************************************************************/
        map1[3][4].setPosition(206+206+350+206+50+50, 310);
        map1[3][5].setPosition(206+206+350+206+50+80+400, 320);
        map1[3][13].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+150,300);
        map1[3][19].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290,290);
        map1[3][27].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+5*206+80,300);
        map1[3][28].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+5*206+150+206,380);
        map1[3][29].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+5*206+150+206+206,380);
        /*******************************************************************************************************/
        //up
        map1[4][0].setPosition(50, 430);
        map1[4][1].setPosition(50+101, 430);
        map1[4][2].setPosition(50+101+115, 318);
        map1[4][3].setPosition(206+206+150, 380);
        map1[4][4].setPosition(206+206+350+206+50, 380);
        map1[4][5].setPosition(206+206+350+206+50+206+30+20, 320);
        map1[4][6].setPosition(206+206+350+206+50+206+206+350, 400);
        map1[4][8].setPosition(206+206+350+206+50+206+206+400+30+206+50+20,380);
        map1[4][9].setPosition(206+206+350+206+50+206+206+400+30+206+50+80+20,380);
        map1[4][10].setPosition(206+206+350+206+50+206+206+400+30+206+50+80+80+20,380);
        map1[4][11].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+130,380);
        map1[4][12].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+130+206,380);
        map1[4][14].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+250,380);
        map1[4][16].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+30,430);
        map1[4][17].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206,318);
        map1[4][18].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290,380);
        map1[4][21].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206,400);
        map1[4][24].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206,400);
        map1[4][26].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+2*206+150,380);
        map1[4][27].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+3*206+150,380);
        map1[4][28].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+4*206+150,380);
        map1[4][29].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206+5*206+150,380);

        /***********************************************************************************************************/
        //ground
        map1[5][0].setPosition(0, 490);
        map1[5][1].setPosition(206, 490);
        map1[5][2].setPosition( map1[5][1].getPosition().x +206, 530);
        map1[5][3].setPosition(206+206+350, 490);
        map1[5][5].setPosition(206+206+350+206+50+206+30, 490);
        map1[5][6].setPosition(206+206+350+206+50+206+206+30, 490);
        map1[5][7].setPosition(206+206+350+206+50+206+206+30+206,490);
        map1[5][8].setPosition(206+206+350+206+50+206+206+206+30+386, 530);
        map1[5][9].setPosition(206+206+350+206+50+206+206+206+30+206, 490);
        map1[5][10].setPosition(206+206+350+206+50+206+206+206+30+206+386+150, 490);
        map1[5][13].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+130+206+206+80, 490);
        map1[5][14].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+150, 490);
        map1[5][15].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+150+206, 520);
        map1[5][16].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330, 490);
        map1[5][17].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206, 490);
        map1[5][20].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+2069+330+206+290+290+206, 490);
        map1[5][21].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206, 490);
        map1[5][22].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206, 520);
        map1[5][23].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200, 490);
        map1[5][24].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206, 490);
        map1[5][25].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206, 490);
        map1[5][26].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+206, 520);
        map1[5][27].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206, 490);
        map1[5][28].setPosition(206+206+350+206+50+206+206+206+30+206+386+150+220+206+206+206+330+206+290+290+206+206+206+200+206+206+80+206+206, 490);
        map1[5][29].setPosition(map1[5][28].getPosition().x +206, 490);
        //map1[5][29].setPosition(map1[5][28].getPosition.x +206, 500);

         //map1[5][28].getPosition().x;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (map2[i][j] == 1 || map2[i][j] == 2 || map2[i][j] == 3||map2[i][j]==4||map2[i][j]==5||map2[i][j]==6||map2[i][j]==7||map2[i][j]==8||map2[i][j]==9||map2[i][j]==10||map2[i][j]==11||map2[i][j]==12||map2[i][j]==13||map2[i][j]==14||map2[i][j]==15||map2[i][j]==15
                    ||map2[i][j]==17||map2[i][j]==18||map2[i][j]==19)
                {
                    window1.draw(map1[i][j]);
                }
            }
        }
    }
}
Level2::Level2()
{

 vector<fireball> fireballV ;

   int active_window=2;
    velocity.x=0 ;
    velocity.y=0 ;
    coin_score = 0;
    t1 = sf::seconds(100.f);
    marioDie = 0 ;
    loadFiles() ;


//ghousts positions
vector <ghoust> g ;
    ghoust  g1 (800, 457 , 100) ;  g.push_back(g1) ;
    ghoust  g2 (1460,457 , 200) ;  g.push_back(g2) ;
    ghoust  g3 (3050,457 ,300) ;  g.push_back(g3) ;
    ghoust  g4 (6000,457, 300 ) ;   g.push_back(g4) ;
    ghoust  g5 (6050,457 , 500) ;   g.push_back(g5) ;
    ghoust  g6 (6700,347 , 300) ;  g.push_back(g6) ;
    ghoust  g7 (6100,457 ,400) ;   g.push_back(g7) ;
    ghoust  g8 (5200,457 ,300) ;  g.push_back(g8) ;
    ghoust  g9 (5250,457 , 500) ;  g.push_back(g9) ;
    ghoust  g10 (2530,345 , 400) ;   g.push_back(g10) ;
    ghoust  g11 (2580,345 , 100) ;  g.push_back(g11) ;


//coins positions


vector <Coin> c ;

    Coin c1(570, 345, 3) ;     c.push_back(c1);

    Coin c2( 1460,450, 3) ;  c.push_back(c2);
    Coin c3( 1510,450, 3);  c.push_back(c3);
    Coin c4( 1560,450, 3) ;  c.push_back(c4);
    Coin c5( 1610,450, 3) ;  c.push_back(c5);

    Coin c6( 1070,250, 3) ;   c.push_back(c6);
    Coin c7( 1110,250, 3);  c.push_back(c7);
    Coin c8( 1150,250, 3) ;  c.push_back(c8);

    Coin c9( 2145,345, 3 ) ;  c.push_back(c9);
    Coin c10(2225,345, 3 ) ;  c.push_back(c10);
    Coin c11(2305,345, 3 );  c.push_back(c11);

    Coin c12(2670,300, 3) ;  c.push_back(c12);
    Coin c13(2700,300, 3) ;  c.push_back(c13);
    Coin c14(2770,300, 3) ;  c.push_back(c14);
    Coin c15(2800,300, 3);  c.push_back(c15);

    Coin c16(2670,250, 3) ;  c.push_back(c16);
    Coin c17(2700,250, 3) ;  c.push_back(c17);
    Coin c18(2770,250, 3) ;  c.push_back(c18);
    Coin c19(2800,250, 3);  c.push_back(c19);

    Coin c20(3300,300, 3) ;  c.push_back(c20);

    Coin c21(4100,300, 3) ;  c.push_back(c21);
    Coin c22(4150,300, 3) ;  c.push_back(c22);
    Coin c23(4200,300, 3) ;  c.push_back(c23);


    Coin c24(4400,250, 3) ;  c.push_back(c24);
    Coin c25(4450,250, 3) ;  c.push_back(c25);
    Coin c26(4500,250, 3) ; c.push_back(c26);

    Coin c27(5610,400, 3) ; c.push_back(c27);
    Coin c28(5660,400, 3) ; c.push_back(c28);
    Coin c29(5610,350, 3) ; c.push_back(c29);
    Coin c30(5660,350, 3) ; c.push_back(c30);

    Coin c31(6730,300, 3) ; c.push_back(c31);
    Coin c32(6730,250, 3) ; c.push_back(c32);
    Coin c33(6730,200, 3) ; c.push_back(c33);

    Coin c34(6780,230, 3) ; c.push_back(c34);

    Coin c35(6830,250, 3) ; c.push_back(c35);

    Coin c36(6880,230, 3) ; c.push_back(c36);

    Coin c37(6930,300, 3) ; c.push_back(c37);
    Coin c38(6930,250, 3) ; c.push_back(c38);
    Coin c39(6930,200, 3) ; c.push_back(c39);

    Coin c40(6100,250, 3) ; c.push_back(c40);
    Coin c41(6150,250, 3) ; c.push_back(c41);
    Coin c42(6200,250, 3) ; c.push_back(c42);
    Coin c43(6250,250, 3) ; c.push_back(c43);
    Coin c44(6300,250, 3) ; c.push_back(c44);
    Coin c45(6350,250, 3) ; c.push_back(c45);

    Coin c46(4600,250, 3) ; c.push_back(c46);
    Coin c47(4650,220, 3) ; c.push_back(c47);
    Coin c48(4700,250, 3) ; c.push_back(c48);
    Coin c49(4750,300, 3) ; c.push_back(c49);
    Coin c50(4800,350, 3) ; c.push_back(c50);


    ///end game
    Win endgame;


//window opening
    while (window1.isOpen())
    {
        sf::Event event;

        for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
            {
                mario_died() ; marioDie = 1 ;
            }
         }

        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        if(mario.getPosition().y ==  groundHeight + 52 ||  mario.getPosition().y >= 552  )
        {
            mario.setPosition(mario.getPosition().x, 500 ) ;
            mario_died() ;
            marioDie = 1 ;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {

      for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
             {
                mario_died() ; marioDie = 1 ;
            }
         }
            if( marioDie == 0)
            {
                countL++ ;
                if(countL >10) countL =0 ;
                if(countL%2== 0)
                {
                    y=0 ;
                    x++ ;
                    if(x>5) x=1 ;
                    mario.setTextureRect(sf::IntRect(220-(x * 27.5 ), y * 60,  27.5,60)) ;
                }
                view.move(  -4,0) ;
                velocity.x= -movespeed ;
            }

          diraction_Of_fire =0 ;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {


         for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
             {
                mario_died() ; marioDie = 1 ;
            }
         }



            if( marioDie == 0)
            {
                countR++ ;
                if(countR >10) countR =0 ;
                if(countR%2== 0)
                {
                    y=0;
                    x++ ;
                    if(x>4) x=0 ;
                    mario.setTextureRect(sf::IntRect(220+(x * 27.5), y * 60,  27.5,60)) ;

                }


                view.move(  4,0) ;
                /* velocity of mario*/
               velocity.x= movespeed ;
            }

      diraction_Of_fire =1 ;


        }
        else velocity.x=0 ;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space  )  )
        {
            if(!buffer_jump.loadFromFile("smb_jump-super.wav"))
            {

                cout<<"Not found"<<endl;
            }
            sound_jump.setBuffer(buffer_jump);
            sound_jump.play();
            for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
            {
                mario_died() ; marioDie = 1 ;
            }

         }

         if( marioDie == 0)
            {
                y=1;
                x++ ;
                if(x>5) x=0 ;
                /* velocity of mario*/
                mario.setTextureRect(sf::IntRect(220+(x * 27.5), y * 60,  27.5,60)) ;

                if(  mario.getPosition().y < 240){

                velocity.y = -0.3 ;
                } else{

                velocity.y = -jumpSpeed ;
                }
            }
            velocity.y = -jumpSpeed ;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space  )  &&
                sf::Keyboard::isKeyPressed( sf::Keyboard::Left  )   )
        {
             for(int i =0 ;i< g.size() ; i++){
           if (g.at(i).mario_collision_die(mario , groundHeight) )
            {
               mario_died() ; marioDie = 1 ;
            }
         }

            if( marioDie == 0)
            {
                y=1;
                x++ ;
                if(x>5) x=1 ;
                mario.setTextureRect(sf::IntRect(220-(x * 27.5), y * 60,  27.5,60)) ;

                if(  mario.getPosition().y < 240){

                velocity.y = -0.3 ;
                }else{

                velocity.y = -jumpSpeed ;
                }
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
        else
        {

            mario.setPosition(mario.getPosition().x, groundHeight - 65) ;
            velocity.y=0 ;


        }

        mario.move(velocity.x, velocity.y) ;
        window1.setView(view) ;

        window1.clear(sf::Color(23, 66, 117, 1));

        loadMap() ;
        drawing() ;

        for(int i =0 ;i< g.size() ; i++){
         g.at(i).ghoust_moving() ; window1.draw(g.at(i).ghoust_sprite);
         }

           for(int i =0 ;i< g.size() ; i++){
         if( g.at(i).ghoust_collision_die(mario , groundHeight ) ) ghoust_score++  ;
         }


      for(int i=0 ;i<c.size() ;i++){
          c.at(i).coin_animation(3) ;
          if(c.at(i).coin_ate(mario))  coin_score++ ;
          else   window1.draw(c.at(i).coin_sprite);
        }

//end of game
        if(endgame.winGame(mario,groundHeight,window1,active_window,7710)&&marioDie==0)
        {
            //view.move(0,0);

            movespeed=0;
                     if(!buffer_win.loadFromFile("smb3_enter_level.wav"))
            {
                cout<<"Not Found"<<endl;
            }
            sound_win.setBuffer(buffer_win);
            sound_win.play();
        }

        load_Score(coin_score, ghoust_score) ;

        loadTimer() ;



                 for(int i=0 ;i<fireballV.size() ;i++){
                     for(int j=0 ;j<g.size() ;j++){
           if(fireballV.at(i).sprite().getGlobalBounds().intersects(g.at(j).sprite().getGlobalBounds())   )
           {
               g.at(j).ghoust_fireB= 1;  fireballV.at(i).fireUsed =1 ;

           }
                     }
                 }

              for(int j=0 ;j<g.size() ;j++){
                if ( g.at(j).ghoust_fireB )
                {   g.at(j).ghoust_die() ;

                }
              }

                for(int i=0 ;i<fireballV.size() ;i++){

                   window1.draw( fireballV.at(i).sprite() );
                   if( fireballV.at(i).fireout(mario)) fireballV.erase(fireballV.begin()+i) ;
                }


        window1.display();
    }

}
void Level2::drawing()
{
    window1.draw(mario);

    if(marioDie== 1)
    {
        gameOver_sprite.setTexture(gameOver_texture) ;
        gameOver_sprite.setTextureRect( sf::IntRect( 0,80,800,250 ) ) ;
        gameOver_sprite.setPosition( view.getCenter().x -400, view.getCenter().y -190 ) ;
        window1.draw(gameOver_sprite) ;
    }
}
bool  Level2::collision(int order)
 {
     if(map1[5][0].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][1].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][3].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][5].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][6].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][7].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][9].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][10].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][13].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][14].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][16].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][17].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][20].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][21].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][23].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][24].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][25].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][27].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][28].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
        map1[5][29].getGlobalBounds().intersects(mario.getGlobalBounds())
        )
        {
                 groundHeight = map1[5][0].getPosition().y+10;
                 return true;
        }
        else if(map1[4][3].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
                map1[4][4].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
                map1[4][8].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
                map1[4][9].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
                map1[4][10].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][11].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][12].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][14].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][18].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][26].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][27].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][28].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[4][29].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[3][28].getGlobalBounds().intersects(mario.getGlobalBounds())||
                map1[3][29].getGlobalBounds().intersects(mario.getGlobalBounds())
                )
        {
            groundHeight = 390;

                 return true ;
        }
        else if(map1[3][19].getGlobalBounds().intersects(mario.getGlobalBounds()))
        {
            groundHeight = 300;

            return true ;
        }
   else
    {
        if(marioDie == 1 ) groundHeight = 500 ;
        else  groundHeight = 650 ;
    }
}

bool Level2::mario_died()
{
    if (marioDie==0){

        window1.close();
        page2(1200,675);

        return true;
}
}
void Level2::load_Score ( int coin_score, int ghoust_score )
{
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
    text_score.setPosition(view.getCenter().x +245, view.getCenter().y-225  ) ;
    window1.draw(text_score) ;
    text_score2.setPosition(view.getCenter().x +140, view.getCenter().y-225  ) ;
    window1.draw(text_score2) ;

    //  åäÇ ÔÛá ÇáÕæÑå Çá ÌäÈ ÇáÑÞã

    coin_sprite2.setPosition(view.getCenter().x +285, view.getCenter().y-220 ) ;
    ghoust_sprite2.setPosition(view.getCenter().x +175, view.getCenter().y-220 ) ;

    window1.draw(coin_sprite2) ;
    window1.draw(ghoust_sprite2) ;


}
void Level2::loadTimer()
{
    elapsed1 = clock.getElapsedTime();
    if( elapsed1.asSeconds() > 100.0f)
    {
        mario_died() ;
        marioDie = 1 ;
    }
    else
    {
        int a = (t1 - elapsed1).asSeconds() ;
        ostringstream strtimer;

        strtimer << a;
        geek3 = strtimer.str();
        texttimer.setString(geek3) ;

        texttimer.setPosition(view.getCenter().x -245, view.getCenter().y-225  ) ;

    }
    window1.draw(texttimer) ;

    textTime.setPosition(view.getCenter().x -340, view.getCenter().y-228  ) ;
    window1.draw(textTime);


}
Level2::~Level2()
{

}
