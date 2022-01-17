#include "Animacja.h"

Animacja::Animacja(sf::Texture* tekstura, sf::Vector2u liczbaKlatek, float switchTime)
{
	this->liczbaKlatek = liczbaKlatek;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	terazKlatka.x = 0;

	uvRect.width = tekstura->getSize().x / float(liczbaKlatek.x);
	uvRect.height = tekstura->getSize().y / float(liczbaKlatek.y);
}

void Animacja::Update(int wiersz, float deltaTime, bool prawy)
{
	terazKlatka.y = wiersz;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		terazKlatka.x++;

		if (terazKlatka.x >= liczbaKlatek.x)
			terazKlatka.x = 0;
	}
	
	uvRect.top = terazKlatka.y * uvRect.height;

	if (prawy) 
	{
		uvRect.left = terazKlatka.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else 
	{
		uvRect.left = (terazKlatka.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
