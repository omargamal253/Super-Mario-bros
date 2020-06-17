#include "option.h"
#include<iostream>
#include"Level1.h"
#include"Level2.h"
#include"Level3.h"

#include "Level4.h"
using namespace std;
option::option()
{
   sf::RenderWindow window(sf::VideoMode(1200, 675), "Super Mario");
	sf::Texture t;
	//sf::SoundBuffer buffer;
	//sf::Sound sound;
	//int zoomScale = 0;
	//bool canzoom = true;
	/*if (!buffer.loadFromFile("super_sound (online-audio-converter.com).wav"))
	{
		cout << "Not Play The Music" << endl;
	}
	sound.setBuffer(buffer);
	sound.play();
	*/
	if (!t.loadFromFile("super_New.png"))
	{
		cout << "Not Found Image" << endl;

	}
	sf::Sprite s;
	sf::View v1;
	sf::View v2;
	s.setTexture(t);
	s.setTextureRect(sf::IntRect(10, 10, 1200, 675));
	//s.setColor(sf::Color(150,150,150));
	option menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{


			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Continue button has been pressed" << std::endl;
						window.close();
                         Level1();
						break;
					case 1:
						window.close();
						Level2();
						break;

                    case 2:
                        window.close();
                      Level4();
					    break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}
		window.clear();
		window.draw(s);
		menu.draw(window);
		window.display();

	}
}

}
option::option(float width, float height){
if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "Error!!" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Level 1");
	menu[0].setPosition(sf::Vector2f(width / 7, height / (4 + 1) * 1));
	menu[0].setCharacterSize(55);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Level 2");
	menu[1].setPosition(sf::Vector2f(width / 7, height / (4 + 1) * 2));
	menu[1].setCharacterSize(55);

	/*
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Level 4");
	menu[2].setPosition(sf::Vector2f(width / 7, height / (MAX_NUMBER + 1) * 3));
	menu[2].setCharacterSize(55);
	*/


	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Level 3");
	menu[2].setPosition(sf::Vector2f(width / 7, height / (4 + 1) * 3));
	menu[2].setCharacterSize(55);

	selectedItemIndex = 0;
}

option::~option()
{
    //dtor
}
void option::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(menu[i]);
	}
}

void option::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(51, 0, 25));
	}
}

void option::MoveDown()
{
	if (selectedItemIndex + 1 <= 4 - 1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(25, 0, 51));
	}
}


