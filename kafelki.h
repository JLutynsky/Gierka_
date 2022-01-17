#pragma once
#include "SFML/Graphics.hpp"

#ifndef KAFELKI_H
#define KAFELKI_H

class Kafelek {
public:
	sf::Vector2f pos;
	sf::Texture tekstura;
	sf::Sprite sprite;

	bool nieSciana;
	bool wyjscie;

	Kafelek(std::string, float, float, float, float, bool, bool);
	bool setUpSprite(std::string);

};

#endif KAFELKI_H