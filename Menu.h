#include <SFML/Graphics.hpp>
#include <iostream>

#define wybory 4


class Menu
{

private:
	sf::Font font;
	sf::Text menu[wybory];
	int selectedItem = 0;
	float menuW, menuH;

	

public:
	Menu(float width, float height);
	~Menu() {};
	void przesunG();
	void przesunD();
	int getSelectedItem() { return selectedItem; }
	sf::Vector2f getPos() { return sf::Vector2f(menuW, menuH); };
	void draw(sf::RenderWindow &window);
};






