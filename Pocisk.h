#pragma once

#include <SFML/Graphics.hpp>
#include "Animacja.h"
#include "Kolizja.h"
#include "Gracz.h"


class Pocisk
{
public:
	Pocisk(int pociskSpeed, int pociskSize, Gracz& player);
	void Draw(sf::RenderWindow& window);

	void strzela();
	void updateMouse(sf::RenderWindow& window, sf::View& widok);
	void setPos(sf::Vector2f newPos);
	void setPociskSource(sf::Vector2f newPos);
	float getDirY() { return dirY; };
	sf::FloatRect pociskBounds() { return kula.getGlobalBounds(); };

	bool kolizja_sciana(sf::RectangleShape sciana);
	
	sf::Vector2f playerCenter;
	sf::Vector2f pociskSource;
	sf::Vector2f mousePos;

	bool isRight;

private:
	sf::RectangleShape kula;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;



	int PociskSpeed;
	float dirY;
	double a;
	double b;



};

