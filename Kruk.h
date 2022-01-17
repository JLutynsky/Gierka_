#pragma once
#include <SFML/Graphics.hpp>
#include "Animacja.h"
#include "Kolizja.h"
#include "Gracz.h"
#include "Pocisk.h"


class Kruk
{
public:
	Kruk(sf::Texture* tekstura, sf::Vector2u liczbaKlatek, float switchTime, float szybkosc);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void setPos(int posX, int posY);
	void setSpeed(float szybkoscKruka);

	sf::Vector2f GetPosition() { return cialo.getPosition(); }
	Kolizja getKolizja() { return Kolizja(cialo); }
	void Kolizja_sciana(sf::RectangleShape sciana);
	void Kolizja_kruk(Kruk innyKruk);
	bool Kolizja_pocisk(Pocisk strzal);
	bool Kolizja_gracz(Gracz player);
	bool dead(bool isDead);

	sf::Vector2f ganianyPos;
	sf::Vector2f playerDistanceVect;

private:
	sf::RectangleShape cialo;
	Animacja animacja;
	unsigned int wiersz;
	float playerDistance;
	float generedKrukSpeed, szybkosc;
	float kruk_speed;
	bool czyPrawy;


};

