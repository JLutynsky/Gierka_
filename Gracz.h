#pragma once
#include <SFML/Graphics.hpp>
#include "Animacja.h"
#include "Kolizja.h"

class Gracz
{
public:
	Gracz(sf::Texture* tekstura, sf::Vector2u liczbaKlatek, float switchTime, float szybkosc);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return cialo.getPosition(); }
	Kolizja getKolizja() { return Kolizja(cialo); }
	void Kolizja_sciana(sf::RectangleShape sciana);
	sf::FloatRect graczBounds() { return cialo.getGlobalBounds(); };
	bool czyPrawy;
	bool isHit;

private:
	sf::RectangleShape cialo;
	Animacja animacja;
	unsigned int wiersz;
	float szybkosc;
	
};

