#include "Level1.h"
#include <SFML/Graphics.hpp>
#include "pageMain.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>  // for string streams
#include <string>
using namespace std;
#include "Ghoust.h"
#include"page2.h"
#include "Coin.h"
#include"Win.h"
#include<vector>

void Level1::loadFiles()
{
    window.create(sf::VideoMode(800, 600), "My window");


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

	view.setCenter(sf::Vector2f(300, 300));
	view.setSize(sf::Vector2f(800.f, 600.f));
	mario.setTexture(texture);
	mario.setTextureRect(sf::IntRect(220, 0, 27.5, 60));
	mario.setPosition(150, 300);

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
void Level1::loadMap()
{
    if (!textureGround.loadFromFile("groundphoto.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!texturesun.loadFromFile("toppng.com-super-mario-bros-super-mario-bros-cloud-1863x701.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!groundheigh.loadFromFile("groundphoto2.png"))
	{
		cout << " not fouaaaaand texture" << endl;
	}
	if (!gabal.loadFromFile("gabal.png"))
	{
		cout << " not fouaaaaand gabal" << endl;
	}
	if (!elnahaya.loadFromFile("end11.png"))
	{
		cout << " not fouaaaaand elnahaya" << endl;
	}


	int map2[4][20] = {
		3, 0, 3, 0, 3, 0, 3, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 2, 2, 2,
		0, 2, 2, 0, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 0, 2,
		0, 2, 6, 0, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0,
		1, 0, 1, 0, 1, 1, 1, 7, 8, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,


	};
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<20; j++)
		{
			if (map2[i][j] == 1)
			{
				map1[i][j].setTexture(textureGround);
				map1[i][j].setTextureRect(sf::IntRect(0, 0, 958, 181));
			}
			else if (map2[i][j] == 2)
			{
				map1[i][j].setTexture(groundheigh);
				map1[i][j].setTextureRect(sf::IntRect(0, 0, 62, 62));
			}
			else if (map2[i][j] == 3)
			{
				map1[i][j].setTexture(texturesun);
			}
			else if (map2[i][j] == 6)
			{
				map1[i][j].setTexture(gabal);
				map1[i][j].setTextureRect(sf::IntRect(0, 0, 252, 114));
			}
			else if (map2[i][j] == 7)
			{
				map1[i][j].setTexture(elnahaya);
			}

		}
	}

	//ground
	map1[3][0].setPosition(0, 500);
	map1[3][2].setPosition(958 + 362, 500);
	map1[3][4].setPosition(958 + 362 + 958 + 200, 500);
	map1[3][5].setPosition(958 + 362 + 958 + 200 + 1500, 500);
	map1[3][6].setPosition(958 + 362 + 958 + 200 + 1500 + 1300, 500);
	map1[3][9].setPosition(958 + 362 + 958 + 200 + 1500 + 1300 + 1300, 500);
	map1[3][10].setPosition(958 + 362 + 958 + 200 + 1500 + 1300 + 1300 + 1300, 500);
	//elnahaya
	map1[3][7].setPosition(958 + 362 + 958 + 200 + 1500 + 1300 + 1300 + 1700, 170);
	// gabal
	map1[2][2].setPosition(70, 391);
	map1[2][4].setPosition(600, 391);
	map1[2][6].setPosition(1400, 391);
	map1[2][7].setPosition(1900, 391);
	map1[2][8].setPosition(2600, 391);
	map1[2][9].setPosition(3100, 391);
	map1[2][10].setPosition(4100, 391);
	map1[2][11].setPosition(4600, 391); //+500
	map1[2][12].setPosition(5400, 391);
	map1[2][13].setPosition(5900, 391);
	map1[2][14].setPosition(6700, 391);
	map1[2][15].setPosition(7200, 391);//+800
	map1[2][16].setPosition(7950, 391);

	//sa7ab
	map1[0][0].setPosition(100, 50);
	map1[0][2].setPosition(900, 50);
	map1[0][4].setPosition(1700, 50);
	map1[0][6].setPosition(2500, 50);
	map1[0][8].setPosition(3300, 50);
	map1[0][9].setPosition(4100, 50);
	map1[0][10].setPosition(4900, 50);//+800
	map1[0][11].setPosition(5600, 50);
	map1[0][12].setPosition(6400, 50);
	map1[0][13].setPosition(7200, 50);
	map1[0][14].setPosition(8000, 50);
	map1[0][14].setPosition(8300, 50);


	//  balata
	map1[2][1].setPosition(362, 350);
	map1[1][1].setPosition(362 + 62 + 62, 350);
	map1[1][2].setPosition(956 + 100, 330);
	map1[1][4].setPosition(956 + 162, 330);
	map1[1][9].setPosition(3580, 360);
	map1[1][10].setPosition(3780, 360);
	map1[1][11].setPosition(5100, 355);
	map1[1][16].setPosition(5700, 350);
	map1[1][17].setPosition(5762, 350);
	map1[1][19].setPosition(6400, 350);
	map1[0][17].setPosition(6900, 330);
	map1[0][18].setPosition(7100, 205);
	map1[0][19].setPosition(7700, 335);
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<20; j++)
		{
			if (map2[i][j] == 1 || map2[i][j] == 2 || map2[i][j] == 3 ||  map2[i][j] == 6 || map2[i][j] == 7)
			{
				window.draw(map1[i][j]);
			}


		}
	}
}
Level1::Level1()
{
    int active_window = 1;
	velocity.x = 0;
	velocity.y = 0;
	coin_score = 0;
	t1 = sf::seconds(100.f);
vector<ghoust>g;
	ghoust   g1(100, 470,100);  g.push_back(g1);
	ghoust  g2(1400, 470,100); g.push_back(g2);
	ghoust  g3(2580, 470,100);   g.push_back(g3);
	ghoust  g4(5400, 470,100); g.push_back(g4);
	loadFiles();

vector <Coin> c;
	Coin c1(200, 462, 1);  c.push_back(c1);
	Coin c2(250, 462, 1);  c.push_back(c2);
	Coin c3(300, 462, 1);  c.push_back(c3);
	Coin c4(350, 462, 1);  c.push_back(c4);

	Coin c5(375, 300, 3);  c.push_back(c5);
	Coin c6(375, 270, 3);   c.push_back(c6);
	Coin c7(375, 240, 3);  c.push_back(c7);
	Coin c8(498, 300, 3);  c.push_back(c8);
	Coin c9(498, 270, 3);  c.push_back(c9);
	Coin c10(498, 240, 3);  c.push_back(c10);

	Coin c11(1060, 280, 3);  c.push_back(c11);
	Coin c12(1110, 280, 3);  c.push_back(c12);
	Coin c13(1160, 280, 3);  c.push_back(c13);

	Coin c14(1700, 430, 1); c.push_back(c14);
	Coin c15(1750, 430, 1);  c.push_back(c15);
	Coin c16(1800, 430, 1);  c.push_back(c16);
	Coin c17(1850, 430, 1); c.push_back(c17);
	Coin c18(1700, 465, 1); c.push_back(c18);
	Coin c19(1750, 465, 1); c.push_back(c19);
	Coin c20(1800, 465, 1); c.push_back(c20);
	Coin c21(1850, 465, 1); c.push_back(c21);
	Coin c22(2650, 350, 1); c.push_back(c22);
	Coin c23(2700, 350, 1); c.push_back(c23);
	Coin c24(2750, 350, 1); c.push_back(c24);
	Coin c25(2800, 350, 1); c.push_back(c25);

	Coin c26(5110, 270, 1); c.push_back(c26);
	Coin c27(5110, 220, 1); c.push_back(c27);
	Coin c28(5110, 170, 1); c.push_back(c28);

	Coin c29(5700, 280, 1); c.push_back(c29);
	Coin c30(5750, 280, 1); c.push_back(c30);
	Coin c31(5800, 280, 1); c.push_back(c31);
	Coin c32(5700, 245, 1); c.push_back(c32);
	Coin c33(5750, 245, 1); c.push_back(c33);
	Coin c34(5800, 245, 1); c.push_back(c34);

	Coin c35(6910, 280, 1); c.push_back(c35);
	Coin c36(6910, 240, 1); c.push_back(c36);
	Coin c37(7110, 170, 1); c.push_back(c37);
	Coin c38(7110, 135, 1); c.push_back(c38);

	Coin c39(8000, 430, 1); c.push_back(c39);
	Coin c40(8050, 430, 1); c.push_back(c40);
	Coin c41(8100, 430, 1); c.push_back(c41);
	Coin c42(8150, 430, 1); c.push_back(c42);
	Coin c43(8000, 465, 1); c.push_back(c43);
	Coin c44(8050, 465, 1); c.push_back(c44);
	Coin c45(8100, 465, 1); c.push_back(c45);
	Coin c46(8150, 465, 1); c.push_back(c46);

	Win endgame;

//	Mashrom m1(1100, 140);
	marioDie = 0;


	while (window.isOpen())
	{

		sf::Event event;



		if (g1.mario_collision_die(mario, groundHeight) ||
			g2.mario_collision_die(mario, groundHeight) ||
			g3.mario_collision_die(mario, groundHeight) ||
			g4.mario_collision_die(mario, groundHeight))
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
				g4.mario_collision_die(mario, groundHeight))
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
				view.move(-movespeed, 0);
				velocity.x = -movespeed;
			}


		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{


			if (g1.mario_collision_die(mario, groundHeight) ||
				g2.mario_collision_die(mario, groundHeight) ||
				g3.mario_collision_die(mario, groundHeight) ||
				g4.mario_collision_die(mario, groundHeight))
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


				view.move(movespeed, 0);
				velocity.x = movespeed;
			}

		}
		else
			velocity.x = 0;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
                 if(!buffer_jump.loadFromFile("smb_jump-super.wav"))
            {

                cout<<"Not found"<<endl;
            }
            sound_jump.setBuffer(buffer_jump);
            sound_jump.play();

			if (g1.mario_collision_die(mario, groundHeight) ||
				g2.mario_collision_die(mario, groundHeight) ||
				g3.mario_collision_die(mario, groundHeight) ||
				g4.mario_collision_die(mario, groundHeight))
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
				g4.mario_collision_die(mario, groundHeight))
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

		window.clear(sf::Color(51, 153, 204, 0.1));

		loadMap();
		drawing();

		g1.ghoust_moving() ;
		window.draw(g1.ghoust_sprite);
		g2.ghoust_moving() ;
		window.draw(g2.ghoust_sprite);
		g3.ghoust_moving() ;
		window.draw(g3.ghoust_sprite);
		g4.ghoust_moving() ;
		window.draw(g4.ghoust_sprite);


		if (g1.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g2.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g3.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;
		if (g4.ghoust_collision_die(mario, groundHeight))
			ghoust_score++;


		c1.coin_animation(1);
		if (c1.coin_ate(mario))coin_score++;
		else window.draw(c1.coin_sprite);

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

		c4.coin_animation(1);
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

		c7.coin_animation(3);
		if (c7.coin_ate(mario))
			coin_score++;
		else
			window.draw(c7.coin_sprite);

		c8.coin_animation(3);
		if (c8.coin_ate(mario))coin_score++;
		else window.draw(c8.coin_sprite);



		c9.coin_animation(3);
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

		c13.coin_animation(3);
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
		c16.coin_animation(1);
		if (c16.coin_ate(mario))
			coin_score++;
		else
			window.draw(c16.coin_sprite);


		c17.coin_animation(1);
		if (c17.coin_ate(mario))
			coin_score++;
		else
			window.draw(c17.coin_sprite);

		c18.coin_animation(1);
		if (c18.coin_ate(mario))
			coin_score++;
		else
			window.draw(c18.coin_sprite);

		c19.coin_animation(1);
		if (c19.coin_ate(mario))
			coin_score++;
		else
			window.draw(c19.coin_sprite);

		c20.coin_animation(1);
		if (c20.coin_ate(mario))
			coin_score++;
		else
			window.draw(c20.coin_sprite);
		c21.coin_animation(1);
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
		c30.coin_animation(1);
		if (c30.coin_ate(mario))
			coin_score++;
		else
			window.draw(c30.coin_sprite);
		c31.coin_animation(1);
		if (c31.coin_ate(mario))
			coin_score++;
		else
			window.draw(c31.coin_sprite);

		c32.coin_animation(1);
		if (c32.coin_ate(mario))
			coin_score++;
		else
			window.draw(c32.coin_sprite);
		c33.coin_animation(1);
		if (c33.coin_ate(mario))
			coin_score++;
		else
			window.draw(c33.coin_sprite);
		c34.coin_animation(1);
		if (c34.coin_ate(mario))
			coin_score++;
		else
			window.draw(c34.coin_sprite);

		c35.coin_animation(1);
		if (c35.coin_ate(mario))
			coin_score++;
		else
			window.draw(c35.coin_sprite);
		c36.coin_animation(1);
		if (c36.coin_ate(mario))
			coin_score++;
		else
			window.draw(c36.coin_sprite);

		c37.coin_animation(1);
		if (c37.coin_ate(mario))
			coin_score++;
		else
			window.draw(c37.coin_sprite);
		c38.coin_animation(1);
		if (c38.coin_ate(mario))
			coin_score++;
		else
			window.draw(c38.coin_sprite);
		c39.coin_animation(1);
		if (c39.coin_ate(mario))
			coin_score++;
		else
			window.draw(c39.coin_sprite);
		c40.coin_animation(1);
		if (c40.coin_ate(mario))
			coin_score++;
		else
			window.draw(c40.coin_sprite);
		c41.coin_animation(1);
		if (c41.coin_ate(mario))
			coin_score++;
		else
			window.draw(c41.coin_sprite);
		c42.coin_animation(1);
		if (c42.coin_ate(mario))
			coin_score++;
		else
			window.draw(c42.coin_sprite);
		c43.coin_animation(1);
		if (c43.coin_ate(mario))
			coin_score++;
		else
			window.draw(c43.coin_sprite);
		c44.coin_animation(1);
		if (c44.coin_ate(mario))
			coin_score++;
		else
			window.draw(c44.coin_sprite);
		c45.coin_animation(1);
		if (c45.coin_ate(mario))
			coin_score++;
		else
			window.draw(c45.coin_sprite);
		c46.coin_animation(1);
		if (c46.coin_ate(mario))
			coin_score++;
		else
			window.draw(c46.coin_sprite);

		if (endgame.winGame(mario, groundHeight, window, active_window, 958 + 362 + 958 + 200 + 1500 + 1300 + 1300 + 1700+200))
        {
            movespeed=0;

        }

		load_Score(coin_score, ghoust_score);

		loadTimer();
		window.display();
	}
}
void Level1::drawing()
{
    window.draw(mario);
}
bool Level1::collision(int order)
{
    if (map1[2][1].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[2][1].getGlobalBounds().top + 5;

		return true;

	}
	else if (map1[1][1].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[1][1].getGlobalBounds().top + 5;

		return true;

	}
	else  if (map1[1][2].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[1][2].getGlobalBounds().top + 5;

		return true;

	}

	else if (map1[1][4].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[1][4].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[1][9].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[1][9].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[1][10].getGlobalBounds().intersects(mario.getGlobalBounds()))
	{

		groundHeight = map1[1][10].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[1][11].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[1][11].getGlobalBounds().top + 5;
		return true;

	}
	else  if (map1[1][16].getGlobalBounds().intersects(mario.getGlobalBounds()))
	{

		groundHeight = map1[1][16].getGlobalBounds().top + 5;

		return true;

	}
	else if (map1[1][17].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[1][17].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[1][19].getGlobalBounds().intersects(mario.getGlobalBounds()))
	{

		groundHeight = map1[1][19].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[0][17].getGlobalBounds().intersects(mario.getGlobalBounds()) )
	{

		groundHeight = map1[0][17].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[0][18].getGlobalBounds().intersects(mario.getGlobalBounds()))
	{

		groundHeight = map1[0][18].getGlobalBounds().top + 5;
		return true;

	}
	else if (map1[0][19].getGlobalBounds().intersects(mario.getGlobalBounds()))
	{

		groundHeight = map1[0][19].getGlobalBounds().top + 5;
		return true;

	}


	else if (
		map1[3][0].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][2].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][4].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][5].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][6].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][9].getGlobalBounds().intersects(mario.getGlobalBounds()) ||
		map1[3][10].getGlobalBounds().intersects(mario.getGlobalBounds())
		)
	{
		groundHeight = 505;
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
bool Level1::mario_died()
{
   if (marioDie==0){

        window.close();
        page2(1200,675);

        return true;

}
}
void Level1::load_Score(int coin_score, int ghoust_score)
{
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


	coin_sprite2.setPosition(view.getCenter().x + 285, view.getCenter().y - 220);
	ghoust_sprite2.setPosition(view.getCenter().x + 175, view.getCenter().y - 220);


	window.draw(coin_sprite2);
	window.draw(ghoust_sprite2);
}
void Level1::loadTimer()
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
	sf::Clock clock;
//	clock.restart();
  //   time=clock.getElapsedTime();
  /*
	if (marioDie==1){
	//    if (time.asSeconds()==5){
        window.close();
        page2();

	    }
	//}*/
}


Level1::~Level1()
{
    //dtor
}
