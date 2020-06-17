#include "page2.h"
#include<iostream>
#include"menu.h"
#include"Level1.h"
//#include"Page_Final.h"
#include"option.h"
using namespace std;


page2::page2(float width, float height){

sf::RenderWindow window(sf::VideoMode(1200, 675), "Super Mario");
	sf::Texture t;
  Menu menuu(window.getSize().x, window.getSize().y);
  //page2 menuu(1200,675);
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

	if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "Error!!" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Restart");
	menu[0].setPosition(sf::Vector2f(width / 1.4, height / (MAX_NUMBER + 1) * 1));
	menu[0].setCharacterSize(55);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 1.4, height / (MAX_NUMBER + 1) * 2));
	menu[1].setCharacterSize(55);


	selectedItemIndex = 0;
	if (!t.loadFromFile("super_Mario_ver3.png"))
	{
		cout << "Not Found Image" << endl;

	}
	sf::Sprite s;
	sf::View v1;
	sf::View v2;
	s.setTexture(t);
	s.setTextureRect(sf::IntRect(10, 10, 1200, 675));
	//s.setColor(sf::Color(150,150,150));


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
					menuu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menuu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menuu.GetPressedItem())
					{
					case 0:
						std::cout << "Continue button has been pressed" << std::endl;
						window.close();
						Level1();
                          //Main_Page();
                         // page2();
						//Page_Final();
						break;
					case 1:
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
		}
		   if(!buffer_over.loadFromFile("smb_mariodie.wav"))
    {

        cout<<"Not found"<<endl;
    }
      menuu.music_frist.setVolume(10);
    sound_over.play();
		window.clear();
		window.draw(s);
		menuu.draw(window);
		window.display();
		/*
		 if(!buffer_over.loadFromFile("smb_gameover.wav"))
      {

         cout<<"Error"<<endl;
      }
   //   menu.buffer.detachSound(&sound)
  //    menu.sound_frist.pause();
        sound.setBuffer(buffer_over);
        sound.play();
	}*/
}

/*page2::page2(float width, float height)
{
	if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "Error!!" << endl;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Resta23rt");
	menu[0].setPosition(sf::Vector2f(width / 1.4, height / (MAX_NUMBER + 1) * 1));
	menu[0].setCharacterSize(55);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 1.4, height / (MAX_NUMBER + 1) * 2));
	menu[1].setCharacterSize(55);


	selectedItemIndex = 0;
}
*/

}
void page2::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		window.draw(menu[i]);
	}
}

void page2::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color(51, 0, 25));
	}
}

void page2::MoveDown()
{
	if (selectedItemIndex + 1 <= MAX_NUMBER - 1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(25, 0, 51));
	}
}

page2::~page2()
{

}
