#ifndef LEVEL1_H
#define LEVEL1_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include<SFML/Audio.hpp>
#include<SFML/System/Time.hpp>
using namespace std;

class Level1
{
    public:
        int a = 0;
	bool b = 0;
	int x = 0, y = 0;
	const double gravity = 0.4;
	int groundHeight = 500;
	float movespeed = 6, jumpSpeed = 9.f;
	bool marioDie = 0;
	sf::SoundBuffer buffer_jump;
	sf::Sound sound_jump;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Texture texturesun;
	sf::Texture textureGround;
	sf::Texture textureHigh_Ground;
	sf::Texture mario_die_texture;
	sf::Texture gameOver_texture;
	sf::Texture groundheigh;
	sf::Texture gabal;
	sf::Texture elnahaya;
	sf::Texture box;
	sf::Texture balata;
	sf::View view;
	//sf::Sprite gabal;
	sf::Sprite mario;
	sf::Sprite sun;
	sf::Sprite gameOver_sprite;
	sf::Sprite tile;
	sf::Sprite tile2;
	sf::Sprite map1[4][20];
	int countL = -1, countR = -1;
	sf::Vector2f velocity;
	sf::Text text_score;
	sf::Text text_score2;
	sf::Font font;
	int coin_score = 0;
	int ghoust_score = 0;


	string geek;
	string geek2;

	sf::Texture coin_texture2;
	sf::Sprite  coin_sprite2;

	sf::Texture mashrom_texture2;
	sf::Sprite  mashrom_sprite2;

	sf::Texture ghoust_texture2;
	sf::Sprite  ghoust_sprite2;
	sf::Time t1;
	sf::Clock clock;
	sf::Time elapsed1;
	sf::Text texttimer;
	sf::Text timer;
	string geek3;
	sf::Text textTime;
    sf::Time time;



public:
	void loadFiles();
	void drawing();
	void loadMap();
	bool ghoust_collision_mario();
	bool collision(int order);
	bool mario_died();
	void loadTimer();
	void load_Score(int, int);
    Level1();
        /** Default destructor */
    virtual ~Level1();

    protected:

    private:
};

#endif // LEVEL1_H
