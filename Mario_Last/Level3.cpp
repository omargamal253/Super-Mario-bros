
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>  // for string streams
#include <string>
#include"Level3.h"
using namespace std;
#include "Ghoust.h"
//#include "Mashrom.h"
#include "Coin.h"
#include <SFML/Audio.hpp>
#include"Win.h"

void Level3::loadFiles()
{

	window.create(sf::VideoMode(800, 600), "My window");

       sf::SoundBuffer MARIO;
       if(!MARIO.loadFromFile("mario.wav")){
        cout<<"error";
       }
         sf::Sound sound;

         sound.setBuffer(MARIO);

         sound.play();

	if (!texture.loadFromFile("smb_mario_sheet3last.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!mario_die_texture.loadFromFile("8c57e1d242cac95436cf6d26babf709f.png"))
	{
		cout << " mario_die_texture not fouaaaaand texture" << endl;
	}
	if (!gameOver_texture.loadFromFile("MarioMaker_GameOver.png"))
	{
		cout << " gameOver_texture not fouaaaaand texture" << endl;
	}


	if (!font.loadFromFile("MAGNETOB.ttf"))
	{
		cout << " font not found " << endl;
	}

	//view.setCenter(sf::Vector2f(300, 300));
	view.setCenter(sf::Vector2f(300, 300));
	view.setSize(sf::Vector2f(800.f, 600.f));
	mario.setTexture(texture);
	mario.setTextureRect(sf::IntRect(220, 0, 27.5, 60));
//	mario.setPosition(100, 300);
mario.setPosition(100 , 300);

	if (!coin_texture2.loadFromFile("toppng.com-click-for-full-sized-image-coins-mario-coin-sprite-sheet-811x590Copy.png"))
	{
		cout << " coin_texture not fouaaaaand texture" << endl;
	}
	if (!ghoust_texture2.loadFromFile("images_ghoust.png"))
	{
		cout << " coin_texture not fouaaaaand texture" << endl;
	}

	coin_sprite2.setTexture(coin_texture2);
	coin_sprite2.setTextureRect(sf::IntRect(0 * 27.17, 0, 27.17, 29));

	ghoust_sprite2.setTexture(ghoust_texture2);
	ghoust_sprite2.setTextureRect(sf::IntRect(0, 0, 43.5, 33));



	text_score.setFont(font);
	text_score.setCharacterSize(30);
	text_score.setFillColor(sf::Color(4, 9, 55));



	text_score2.setFont(font);
	text_score2.setCharacterSize(30);
	text_score2.setFillColor(sf::Color(4, 9, 55));


	texttimer.setFont(font);
	texttimer.setCharacterSize(30);
	texttimer.setFillColor(sf::Color(4, 9, 55));


	textTime.setFont(font);
	textTime.setCharacterSize(30);
	textTime.setFillColor(sf::Color(160, 0, 0));

	textTime.setString("Time");






}
void Level3::loadMap()
{if (!ground1.loadFromFile("l3_1.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!texturesun.loadFromFile("toppng.com-super-mario-bros-super-mario-bros-cloud-1863x701.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!ground2.loadFromFile("l3_2.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!ground3.loadFromFile("l3_3.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!ground4.loadFromFile("l3_4.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}


	if (!elnahaya.loadFromFile("elnahaya.png"))
	{
		cout << " not fouaaaaand elnahaya" << endl;
	}


	int map2[4][20] = {
		3, 0, 3, 0, 3, 0, 3, 0, 3, 3, 3, 3, 0, 0, 0 , 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 6, 0, 2, 0, 1, 4, 6, 2, 1, 4, 2, 1, 1, 6, 1, 1, 1, 0,
		1, 0, 2, 0, 1, 2, 6, 7, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	};
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<20; j++)
		{
			if (map2[i][j] == 1)
			{

				map1[i][j].setTexture(ground1);
			//	map1[i][j].setTextureRect(sf::IntRect(0, 0, 150, 223));
			}
			else if (map2[i][j] == 2)
			{
				map1[i][j].setTexture(ground2);
				//map1[i][j].setTextureRect(sf::IntRect(0, 0, 96, 122));
			}
			else if (map2[i][j] == 3)
			{
				map1[i][j].setTexture(texturesun);
			}
			else if (map2[i][j] == 4)
			{
				map1[i][j].setTexture(ground4);
			}
			else if (map2[i][j] == 6)
			{
				map1[i][j].setTexture(ground3);
				//map1[i][j].setTextureRect(sf::IntRect(0, 0, 252, 114));
			}
			else if (map2[i][j] == 7)
			{
				map1[i][j].setTexture(elnahaya);
			}


		}
	}

	//ground
	map1[3][0].setPosition(0, 500); //1
	map1[3][2].setPosition(300, 430); //2
	map1[3][4].setPosition(600, 378);//1
 	map1[3][5].setPosition(900, 500);//2
	map1[3][6].setPosition(1300, 500);//3
	map1[3][9].setPosition(1320, 450 );//4
	map1[3][10].setPosition(1700, 379);//1
	map1[2][2].setPosition(2000, 500);//3
	map1[2][4].setPosition(2300, 430);//2
	map1[2][6].setPosition(2600, 378);//1
	map1[2][7].setPosition(2615, 328);//4
	map1[2][8].setPosition(2950, 500);//3
	map1[2][9].setPosition(3300, 430);//2
	map1[2][10].setPosition(3600, 378);//1
	map1[2][11].setPosition(4015, 380);//4
	map1[2][12].setPosition(4000, 430);//2
	map1[2][13].setPosition(4300, 500);//1
	map1[2][14].setPosition(4600, 378);//1
	map1[2][15].setPosition(5000, 500);//3
	map1[2][16].setPosition(5343, 378);//1
    map1[2][17].setPosition(5485, 378);//1
    map1[2][18].setPosition(5625.5, 378);//1


	//elnahaya
	map1[3][7].setPosition(5360, 38);
	//sa7ab
	map1[0][0].setPosition(100, 50);
	map1[0][2].setPosition(900, 50);
	map1[0][4].setPosition(1700, 50);
	map1[0][6].setPosition(2500, 50);
	map1[0][8].setPosition(3300, 50);
	map1[0][9].setPosition(4100, 50);
	map1[0][10].setPosition(4900, 50);//+800
	map1[0][11].setPosition(5700, 50);

	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<20; j++)
		{
			if (map2[i][j] == 1 || map2[i][j] == 2 || map2[i][j] == 3 || map2[i][j] == 4|| map2[i][j] == 6 || map2[i][j] == 7 )
			{
				window.draw(map1[i][j]);
			}


		}
	}

}
Level3::Level3()
{


    int active_window=3;
	velocity.x = 0;
	velocity.y = 0;
	coin_score = 0;
	t1 = sf::seconds(100.f);

	ghoust   g1(242, 400,200);//2
	ghoust  g2(855, 470,100);//2
	ghoust  g3(1600, 350,250);//1
	ghoust  g4(2300, 400,300);//2
	ghoust g5(2950,470,300);//3
	ghoust g6(3600,350,300);
	ghoust g7(4300,470,300);
	loadFiles();

	Coin c1(600, 342 ,1);
	Coin c2(650, 342, 1);
	Coin c3(700, 342, 1);

	Coin c4(1320, 400, 3);
	Coin c5(1360, 400, 3);
	Coin c6(1400, 400, 3);

	Coin c7(2000, 460, 1);
	Coin c8(2050, 460, 1);
	Coin c9(2100, 460, 1);

	Coin c10(2650, 290, 3);
	Coin c11(2650, 250, 3);
	Coin c12(2650, 210, 3);

	Coin c13(3300, 390, 1);
	Coin c14(3350, 390, 1);
	Coin c15(3400, 390, 1);

	Coin c16(4025, 350, 3);
	Coin c17(4025, 310, 3);
	Coin c18(4025, 270, 3);
	Coin c19(4075, 350, 3);
	Coin c20(4075, 310, 3);
	Coin c21(4075, 270, 3);

	Coin c22(4600, 340, 1);
	Coin c23(4600, 310, 1);
	Coin c24(4600, 280, 1);

    Coin c25(4635, 300, 1);
	Coin c26(4660, 320, 1);

	Coin c27(4690, 340, 1);
	Coin c28(4690, 310, 1);
	Coin c29(4690, 280, 1);

    Win endgame;

	marioDie = 0;


	while (window.isOpen())
	{

		sf::Event event;



		if (g1.mario_collision_die(mario, groundHeight) ||
			g2.mario_collision_die(mario, groundHeight) ||
			g3.mario_collision_die(mario, groundHeight) ||
            g4.mario_collision_die(mario, groundHeight) ||
			g5.mario_collision_die(mario, groundHeight) ||
			g6.mario_collision_die(mario, groundHeight) ||
			g7.mario_collision_die(mario, groundHeight))
		{
			mario_died();
			marioDie = 1;
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (mario.getPosition().y == groundHeight - 65 && mario.getPosition().y > 565)
		{
			mario.setPosition(mario.getPosition().x, 500);
			mario_died();
			marioDie = 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{


			if (g1.mario_collision_die(mario, groundHeight) ||
			g2.mario_collision_die(mario, groundHeight) ||
			g3.mario_collision_die(mario, groundHeight) ||
            g4.mario_collision_die(mario, groundHeight) ||
			g5.mario_collision_die(mario, groundHeight) ||
			g6.mario_collision_die(mario, groundHeight) ||
			g7.mario_collision_die(mario, groundHeight))
			{
				mario_died();
				marioDie = 1;
			}

			if (marioDie == 0)
			{
				countL++;
				if (countL >10)
					countL = 0;
				if (countL % 2 == 0)
				{
					y = 0;
					x++;
					if (x>5)
						x = 1;
					mario.setTextureRect(sf::IntRect(220 - (x * 27.5), y * 60, 27.5, 60));
				}
				view.move(-4, 0);
				velocity.x = -movespeed;
			}


		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{


			if (g1.mario_collision_die(mario, groundHeight) ||
			g2.mario_collision_die(mario, groundHeight) ||
			g3.mario_collision_die(mario, groundHeight) ||
            g4.mario_collision_die(mario, groundHeight) ||
			g5.mario_collision_die(mario, groundHeight) ||
			g6.mario_collision_die(mario, groundHeight) ||
			g7.mario_collision_die(mario, groundHeight))
			{
				mario_died();
				marioDie = 1;
			}

			if (marioDie == 0)
			{
				countR++;
				if (countR >10)
					countR = 0;
				if (countR % 2 == 0)
				{
					y = 0;
					x++;
					if (x>4)
						x = 0;
					mario.setTextureRect(sf::IntRect(220 + (x * 27.5), y * 60, 27.5, 60));

				}


				view.move(4, 0);
				velocity.x = movespeed;
			}

		}
		else
			velocity.x = 0;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{


			if (g1.mario_collision_die(mario, groundHeight) ||
			g2.mario_collision_die(mario, groundHeight) ||
			g3.mario_collision_die(mario, groundHeight) ||
            g4.mario_collision_die(mario, groundHeight) ||
			g5.mario_collision_die(mario, groundHeight) ||
			g6.mario_collision_die(mario, groundHeight) ||
			g7.mario_collision_die(mario, groundHeight))
			{
				mario_died();
				marioDie = 1;
			}

			if (marioDie == 0)
			{
				y = 1;
				x++;
				if (x>5)
					x = 0;
				mario.setTextureRect(sf::IntRect(220 + (x * 27.5), y * 60, 27.5, 60));


			}
			velocity.y = -jumpSpeed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{


			if (g1.mario_collision_die(mario, groundHeight) ||
			g2.mario_collision_die(mario, groundHeight) ||
			g3.mario_collision_die(mario, groundHeight) ||
            g4.mario_collision_die(mario, groundHeight) ||
			g5.mario_collision_die(mario, groundHeight) ||
			g6.mario_collision_die(mario, groundHeight) ||
			g7.mario_collision_die(mario, groundHeight))
			{
				mario_died();
				marioDie = 1;
			}
			if (marioDie == 0)
			{
				y = 1;
				x++;
				if (x>5)
					x = 1;
				mario.setTextureRect(sf::IntRect(220 - (x * 27.5), y * 60, 27.5, 60));

				velocity.y = -jumpSpeed;
			}


		}


		collision(1);

		if (mario.getPosition().y + 65 <groundHeight || velocity.y <0)
		{

			velocity.y += gravity;
		}
		else
		{

			mario.setPosition(mario.getPosition().x, groundHeight - 65);
			velocity.y = 0;


		}

		mario.move(velocity.x, velocity.y);
		window.setView(view);

		window.clear(sf::Color(145, 145, 255, 0));

		loadMap();
		drawing();

		g1.ghoust_moving();
		window.draw(g1.ghoust_sprite);
		g2.ghoust_moving();
		window.draw(g2.ghoust_sprite);
		g3.ghoust_moving();
		window.draw(g3.ghoust_sprite);
		g4.ghoust_moving();
		window.draw(g4.ghoust_sprite);
        g5.ghoust_moving();
		window.draw(g5.ghoust_sprite);
		g6.ghoust_moving();
		window.draw(g6.ghoust_sprite);
		g7.ghoust_moving();
		window.draw(g7.ghoust_sprite);

		if (g1.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g2.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g3.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g4.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
        if (g5.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g6.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g7.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;


		c1.coin_animation(1);
		if (c1.coin_ate(mario))
			coin_score++;
		else
			window.draw(c1.coin_sprite);

		c2.coin_animation(1);
		if (c2.coin_ate(mario))
			coin_score++;
		else
			window.draw(c2.coin_sprite);

		c3.coin_animation(1);
		if (c3.coin_ate(mario))
			coin_score++;
		else
			window.draw(c3.coin_sprite);

		c4.coin_animation(3);
		if (c4.coin_ate(mario))
			coin_score++;
		else
			window.draw(c4.coin_sprite);

		c5.coin_animation(3);
		if (c5.coin_ate(mario))
			coin_score++;
		else
			window.draw(c5.coin_sprite);

		c6.coin_animation(3);
		if (c6.coin_ate(mario))
			coin_score++;
		else
			window.draw(c6.coin_sprite);

		c7.coin_animation(1);
		if (c7.coin_ate(mario))
			coin_score++;
		else
			window.draw(c7.coin_sprite);

		c8.coin_animation(1);
		if (c8.coin_ate(mario))
			coin_score++;
		else
			window.draw(c8.coin_sprite);



		c9.coin_animation(1);
		if (c9.coin_ate(mario))
			coin_score++;
		else
			window.draw(c9.coin_sprite);


		c10.coin_animation(3);
		if (c10.coin_ate(mario))
			coin_score++;
		else
			window.draw(c10.coin_sprite);

		c11.coin_animation(3);
		if (c11.coin_ate(mario))
			coin_score++;
		else
			window.draw(c11.coin_sprite);

		c12.coin_animation(3);
		if (c12.coin_ate(mario))
			coin_score++;
		else
     		window.draw(c12.coin_sprite);

		c13.coin_animation(1);
		if (c13.coin_ate(mario))
			coin_score++;
		else
			window.draw(c13.coin_sprite);

		c14.coin_animation(1);
		if (c14.coin_ate(mario))
			coin_score++;
		else
			window.draw(c14.coin_sprite);

		c15.coin_animation(1);
		if (c15.coin_ate(mario))
			coin_score++;
		else
			window.draw(c15.coin_sprite);

		c16.coin_animation(3);
		if (c16.coin_ate(mario))
			coin_score++;
		else
			window.draw(c16.coin_sprite);


		c17.coin_animation(3);
		if (c17.coin_ate(mario))
			coin_score++;
		else
			window.draw(c17.coin_sprite);

		c18.coin_animation(3);
		if (c18.coin_ate(mario))
			coin_score++;
		else
			window.draw(c18.coin_sprite);

		c19.coin_animation(3);
		if (c19.coin_ate(mario))
			coin_score++;
		else
			window.draw(c19.coin_sprite);

		c20.coin_animation(3);
		if (c20.coin_ate(mario))
			coin_score++;
		else
			window.draw(c20.coin_sprite);
		c21.coin_animation(3);
		if (c21.coin_ate(mario))
			coin_score++;
		else
			window.draw(c21.coin_sprite);

		c22.coin_animation(1);
		if (c22.coin_ate(mario))
			coin_score++;
		else
            window.draw(c22.coin_sprite);

		c23.coin_animation(1);
		if (c23.coin_ate(mario))
			coin_score++;
		else
			window.draw(c23.coin_sprite);
		c24.coin_animation(1);
		if (c24.coin_ate(mario))
			coin_score++;
		else
			window.draw(c24.coin_sprite);
		c25.coin_animation(1);
		if (c25.coin_ate(mario))
			coin_score++;
		else
		 window.draw(c25.coin_sprite);
		c26.coin_animation(1);
		if (c26.coin_ate(mario))
			coin_score++;
		else
			window.draw(c26.coin_sprite);

		c27.coin_animation(1);
		if (c27.coin_ate(mario))
			coin_score++;
		else
			window.draw(c27.coin_sprite);


		c28.coin_animation(1);
		if (c28.coin_ate(mario))
			coin_score++;
		else
			window.draw(c28.coin_sprite);

		c29.coin_animation(1);
		if (c29.coin_ate(mario))
			coin_score++;
		else

			window.draw(c29.coin_sprite);

			 if(endgame.winGame(mario,groundHeight,window,active_window,5360 +100)&&marioDie==0)
        {
            //view.move(0,0);
            movespeed=0;
        }

		load_Score(coin_score, ghoust_score);



		loadTimer();
		window.display();
	}

}


void Level3::drawing()
{

	window.draw(mario);

	if (marioDie == 1)
	{
		gameOver_sprite.setTexture(gameOver_texture);
		gameOver_sprite.setTextureRect(sf::IntRect(0, 80, 800, 250));
		gameOver_sprite.setPosition(view.getCenter().x - 400, view.getCenter().y - 190);
		window.draw(gameOver_sprite);
	}
}
bool  Level3::collision(int order)
{



	if (map1[3][0].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 56 < map1[3][0].getGlobalBounds().top)
	{
		groundHeight = map1[3][0].getGlobalBounds().top + 5;

		return true;

	}

	  if (map1[3][2].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y  +55< map1[3][2].getGlobalBounds().top)
	{

		groundHeight = map1[3][2].getGlobalBounds().top + 1700;

		return true;

	}

	else if (map1[3][4].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 60 < map1[3][4].getGlobalBounds().top)
	{

		groundHeight = map1[3][4].getGlobalBounds().top + 15;
		return true;

	}
	else if (map1[3][5].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[3][5].getGlobalBounds().top)
	{

		groundHeight = map1[3][5].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[3][6].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[3][6].getGlobalBounds().top)
	{

		groundHeight = map1[3][6].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[3][9].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[3][9].getGlobalBounds().top)
	{

		groundHeight = map1[3][9].getGlobalBounds().top + 5;
		return true;

	}
	else  if (map1[3][10].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[3][10].getGlobalBounds().top)
	{

		groundHeight = map1[3][10].getGlobalBounds().top + 5;

		return true;

	}
	else if (map1[2][2].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][2].getGlobalBounds().top)
	{

		groundHeight = map1[2][2].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][4].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][4].getGlobalBounds().top)
	{

		groundHeight = map1[2][4].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][6].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][6].getGlobalBounds().top)
	{

		groundHeight = map1[2][6].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][7].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][7].getGlobalBounds().top)
	{

		groundHeight = map1[2][7].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][8].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][8].getGlobalBounds().top)
	{

		groundHeight = map1[2][8].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][9].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][9].getGlobalBounds().top)
	{

		groundHeight = map1[2][9].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][10].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][10].getGlobalBounds().top)
	{

		groundHeight = map1[2][10].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][11].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][11].getGlobalBounds().top)
	{

		groundHeight = map1[2][11].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][12].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][12].getGlobalBounds().top)
	{

		groundHeight = map1[2][12].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][13].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][13].getGlobalBounds().top)
	{

		groundHeight = map1[2][13].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][14].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][14].getGlobalBounds().top)
	{

		groundHeight = map1[2][14].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][15].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][15].getGlobalBounds().top)
	{

		groundHeight = map1[2][15].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[2][16].getGlobalBounds().intersects(mario.getGlobalBounds()) &&
		mario.getPosition().y + 55 < map1[2][16].getGlobalBounds().top)
	{

		groundHeight = map1[2][16].getGlobalBounds().top + 5;
		return true;

	}

	else if (map1[3][0].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][2].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][4].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][5].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][6].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][9].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][10].getGlobalBounds().intersects(mario.getGlobalBounds())
		)
	{
		groundHeight = 500;
		return false;

	}
	else
	{
		if (marioDie == 1)
			groundHeight = 500;
		else
			groundHeight = 650;
	}


}
bool Level3::mario_died()
{



	mario.setTexture(mario_die_texture);
	mario.setTextureRect(sf::IntRect(0, 0, 30, 62));
	window.draw(mario);

	return 1;
}
void Level3::load_Score(int coin_score, int ghoust_score)
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

	text_score.setString(geek);

	text_score2.setString(geek2);

	text_score.setPosition(view.getCenter().x + 245, view.getCenter().y - 225);
	window.draw(text_score);
	text_score2.setPosition(view.getCenter().x + 140, view.getCenter().y - 225);
	window.draw(text_score2);


	//  åäÇ ÔÛá ÇáÕæÑå Çá ÌäÈ ÇáÑÞã


	coin_sprite2.setPosition(view.getCenter().x + 285, view.getCenter().y - 220);
	ghoust_sprite2.setPosition(view.getCenter().x + 175, view.getCenter().y - 220);


	window.draw(coin_sprite2);
	window.draw(ghoust_sprite2);

}
void Level3::loadTimer()
{
	elapsed1 = clock.getElapsedTime();
	if (elapsed1.asSeconds() > 100.0f)
	{
		mario_died();
		marioDie = 1;
	}
	else
	{
		int a = (t1 - elapsed1).asSeconds();
		ostringstream strtimer;

		strtimer << a;
		geek3 = strtimer.str();
		texttimer.setString(geek3);

		texttimer.setPosition(view.getCenter().x - 245, view.getCenter().y - 225);

	}
	window.draw(texttimer);

	textTime.setPosition(view.getCenter().x - 340, view.getCenter().y - 228);
	window.draw(textTime);

}
Level3::~Level3()
{
}
