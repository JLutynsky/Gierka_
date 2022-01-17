#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Textbox
{
public:

	Textbox(sf::Vector2f wymiary, sf::Vector2f pozycja, std::string tytul, sf::Font font, bool bar, bool showCounter, int counterBegin, sf::Color barColor);

	void updateView(sf::View view);
	void updateCounter(int wartosc, int akcja); // 0 wyzeruj, 1 odejmij, 2 dodaj

	int getCounter() { return counter; };

	void Draw(sf::RenderWindow& window);

	sf::Text text;

private:

	bool bar;
	bool showCounter;
	
	std::string napis;
	int counter, counterBegin;
	std::string stringCounter;
	sf::RectangleShape barCounter;

	sf::Font czcionka;
	sf::View widok;
	sf::RectangleShape box;
	sf::Vector2f pos;
};

