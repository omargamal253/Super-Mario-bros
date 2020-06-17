
#define LEVEL2_H


#include <SFML/Graphics.hpp>
#ifndef PAGE2MAIN_H
#define PAGE2MAIN_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;

class Level2
{
public:
    int active_window;
    sf::Texture endGame;
       sf::SoundBuffer buffer_jump;
           sf::Sound sound_jump;
	sf::RenderWindow window1;
	sf::Sprite map1[6][30];
	sf::Texture groundheigh;
	sf::Texture texturesun;
	sf::Texture textureGround;
	sf::Texture ground2;
	sf::Texture star;
	sf::Texture sky;
	sf::Texture moon;
	sf::Texture tree;
	sf::Texture box;
	sf::Texture fire;
	sf::Texture balata;
	sf::Texture box2;
	   sf::SoundBuffer buffer_win;
        sf::Sound sound_win;
	sf::Texture wood;
	sf::Texture water;
	sf::Texture small;
	sf::Texture tube;
	sf::Texture player;
    sf::Texture texture;
    sf::Texture textureHigh_Ground;
    sf::Texture mario_die_texture;
    sf::Texture gameOver_texture;
    sf::Texture winPage_p;
    sf:: Sprite winpage;
	sf::View view;
    int a =0 ;
     bool b =0 ;
    int x=0 , y=0 ;
    const float gravity =0.3;
    int groundHeight = 500 ;
    float movespeed= 4 , jumpSpeed= 7.f ;
    bool marioDie = 0 ;
    sf::Sprite mario ;
    sf::Sprite sun ;
    sf::Sprite gameOver_sprite ;
    sf::Sprite tile ;
    sf::Sprite tile2 ;
    int countL =-1, countR =-1;
    sf::Vector2f velocity ;
    sf::Text text_score ;
    sf::Text text_score2;
    sf::Font font;
    int coin_score = 0 ;
    int ghoust_score = 0 ;
    string geek ;
    string geek2 ;
    sf::Texture coin_texture2 ;
    sf::Sprite  coin_sprite2 ;
    sf::Texture ghoust_texture2 ;
    sf::Sprite  ghoust_sprite2 ;
    sf::Time t1 ;
    sf::Clock clock;
    sf::Time elapsed1 ;
    sf::Text texttimer;
    sf::Text timer ;
    string geek3 ;
    sf::Text textTime ;
              int  count_fire =0 ;
          bool diraction_Of_fire =1 ;



public:
	Level2();


	virtual ~Level2();
    void loadFiles() ;
    void drawing() ;
    void loadMap();
    bool ghoust_collision_mario() ;
    bool  collision(int order) ;
    bool mario_died() ;
    void loadTimer() ;
      //  void draw_coin(Coin c );
    void load_Score ( int , int) ;

protected:

private:
};

#endif // PAGE2MAIN_H
