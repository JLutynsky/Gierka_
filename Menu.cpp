#include "Menu.h"

Menu::Menu(float width, float height)
{	
	if (!font.loadFromFile("font/font.ttf"))
	{
		return;
	}
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Poziom LATWY");
	menu[0].setScale(0.1, 0.1);
	menu[0].setPosition(sf::Vector2f(width / 3, height / (wybory + 1) * 1));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Poziom TURDNY");
	menu[1].setScale(0.1, 0.1);
	menu[1].setPosition(sf::Vector2f(width / 3, height / (wybory + 1) * 2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Ostatnie wyniki");
	menu[2].setScale(0.1, 0.1);
	menu[2].setPosition(sf::Vector2f(width / 3, height / (wybory + 1) * 3));
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Wyjdz z gry");
	menu[3].setScale(0.1, 0.1);
	menu[3].setPosition(sf::Vector2f(width / 3, height / (wybory + 1) * 4));

	for (int i = 0; i < wybory; i++)
		menu[i].setCharacterSize(100);
}


void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < wybory; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::przesunG()
{
	if (selectedItem >= 0 && selectedItem < wybory)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = wybory - 1;
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}


}

void Menu::przesunD()
{
	if (selectedItem >= 0 && selectedItem < wybory)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= wybory)
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}

}