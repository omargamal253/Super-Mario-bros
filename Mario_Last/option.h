#ifndef OPTION_H
#define OPTION_H
#define MAX_NUMBER 3
#include <SFML/Graphics.hpp>
class option
{
    public:
        /** Default constructor */
        option();
        option(float width, float height);
        /** Default destructor */
        virtual ~option();

    void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Font f;
	sf::Text menu[4];
};

#endif // OPTION_H
