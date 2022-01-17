#pragma once
#include "SFML/Graphics.hpp"
#include "kafelki.h"
#include <vector>

#ifndef SWIAT_H
#define SWIAT_H

class Swiat {
	sf::Vector2i posWyjscie;
	sf::Vector2i posPlayer;
	std::vector<sf::Vector2i> posEnemy;

	void setReset();
	void setPosEnemy();
	void setKafelki();

public:
	std::vector< std::vector<Kafelek*> > kafelki;
	int wSiatki;
	Swiat();
};

#endif