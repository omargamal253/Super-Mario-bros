#include "menu.h"
#include<iostream>
#include"Level1.h"
#include"option.h"
using namespace std;
Menu::Menu(){
    sf::RenderWindow window(sf::VideoMode(1200, 675), "Super Mario");
	sf::Texture t;
	if(!music_frist.openFromFile("m.wav"))
    {

        cout<<"Not Found"<<endl;
    }
    sound.setBuffer(buffer_frist);
    //sound.play();
	music_frist.setLoop(true);
	music_frist.play();

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
	if (!t.loadFromFile("super_Mario_ver2.png"))
	{
		cout << "Not Found Image" << endl;

	}
	sf::Sprite s;
	sf::View v1;
	sf::View v2;
	s.setTexture(t);
	s.setTextureRect(sf::IntRect(10, 10, 1200, 675));
	//s.setColor(sf::Color(150,150,150));
	Menu menu(window.getSize().x, window.getSize().y);

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
						std::cout << "Save button has been pressed" << std::endl;
						window.close();
						option();
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
			/*if (canzoom)
			{


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{
					zoomScale++;
					s.setScale(zoomScale, zoomScale);
					canzoom = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{
					zoomScale--;
					s.setScale(zoomScale, zoomScale);
					canzoom = false;
				}
			}
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
			{

				canzoom = true;
			}
		}*/

		window.clear();
		window.draw(s);
		menu.draw(window);
		window.display();
	}
}

}
Menu::Menu(float width, float height)
{
    if (!f.loadFromFile("Arial.ttf"))
	{
		cout << "Not Found the Font" << endl;
	}
	if (!font.loadFromFile("brotherDeluxe1350____2011.ttf"))
	{
		cout << "Error!! not found font2" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("play");
	menu[0].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER + 1) * 1));
	menu[0].setCharacterSize(45);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("OPtions");
	menu[1].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER + 1) * 2));
	menu[1].setCharacterSize(45);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString(" Exit");
	menu[2].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER + 1) * 3));
	menu[2].setCharacterSize(45);




	selectedItemIndex = 0;
}
void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(51, 0, 25));
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 <= MAX_NUMBER - 1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(25, 0, 51));
	}
}

Menu::~Menu()
{
    //dtor
}

