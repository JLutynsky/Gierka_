#pragma once
#include <SFML/Graphics.hpp>

class Animacja
{
public:
	Animacja(sf::Texture* tekstura, sf::Vector2u liczbaKlatek, float switchTime);

	void Update(int wiersz, float deltaTime, bool prawy);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u liczbaKlatek;
	sf::Vector2u terazKlatka;

	float totalTime;
	float switchTime;


};

