#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#define MAX_NUMBER 3
class Menu
{
    public:
        Menu ();
        Menu(float width, float height);
        void draw(sf::RenderWindow &window);
	    void MoveUp();
	    void MoveDown();
	    int GetPressedItem() { return selectedItemIndex; }
        /** Default destructor */
        virtual ~Menu();

    protected:

    public:
        int selectedItemIndex;
         sf::Music music_frist;
          sf::SoundBuffer buffer_frist;
         sf::Sound sound;
      sf::Font font;
      sf::Font f;
	    sf::Text menu[MAX_NUMBER];

};

#endif // MENU_H
