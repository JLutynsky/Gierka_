#include "Textbox.h"
#include <iostream>
#include <stdlib.h>

Textbox::Textbox(sf::Vector2f wymiary, sf::Vector2f pozycja, std::string tytul, sf::Font font, bool bar, bool showCounter, int counterBegin, sf::Color barColor)
{
	
	box.setSize(wymiary);
	pos = pozycja;
	updateView(widok);
	
	this->bar = bar;
	this->counterBegin = counterBegin;
	this->showCounter = showCounter;
	napis = tytul;
	counter = counterBegin;
	updateCounter(0, counterBegin);

	czcionka = font;
	text.setFont(czcionka);

	if (showCounter)
		text.setString(napis + stringCounter);
	else
		text.setString(napis);
	
	text.setCharacterSize(70);
	text.setFillColor(sf::Color::White);
	text.setScale(0.1, 0.1);

	box.setFillColor(sf::Color::Black);

	if (bar)
	{
		barCounter.setPosition(box.getPosition());
		barCounter.setSize(box.getSize());
		barCounter.setFillColor(barColor);
	}


}

void Textbox::updateView(sf::View view)
{
	widok = view;

	sf::Vector2f rogEkranu(view.getCenter().x - view.getSize().x/2 , view.getCenter().y - view.getSize().y /2);
	sf::Vector2f NewPos = rogEkranu + pos;
	box.setPosition(NewPos);

	if(bar)
		barCounter.setPosition(NewPos);

	int a = box.getSize().x;
	int b = box.getSize().y;
	int d = text.getCharacterSize();

	text.setPosition(NewPos + sf::Vector2f(3,3));


}

void Textbox::updateCounter(int wartosc, int akcja)
{
	if (akcja == 0)
		counter = wartosc;
	if (akcja == 1)
		counter -= wartosc;
	if (akcja == 2)
		counter += wartosc;
	
	counter = std::max(0, counter);

	stringCounter = std::to_string(counter);

	if(showCounter)
		text.setString(napis + stringCounter);

	if (bar)
	{
		barCounter.setSize(sf::Vector2f(box.getSize().x * counter / counterBegin, box.getSize().y));
	}
}



void Textbox::Draw(sf::RenderWindow& window)
{
	window.draw(box);
	if (bar)
		window.draw(barCounter);
	window.draw(text);
}
