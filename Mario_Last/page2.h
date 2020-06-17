#pragma once
#include "SFML/Graphics.hpp"
#include<SFML/Audio.hpp>
#define MAX_NUMBER 2
class page2
{
public:
    page2();
	page2(float width, float height);
	~page2();
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
    sf::SoundBuffer buffer_over;
    sf::Sound sound_over;
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Font f;
	sf::Text menu[MAX_NUMBER];
};
