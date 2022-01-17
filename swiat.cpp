#include "SFML/Graphics.hpp"
#include "kafelki.h"
#include "swiat.h"
#include <vector>


Swiat::Swiat() {
	wSiatki = 16;
	setReset();
}

void Swiat::setReset() {
	posWyjscie = sf::Vector2i(1, 0);
	posPlayer = sf::Vector2i(wSiatki - 1, wSiatki - 1);
	setPosEnemy();
	setKafelki();
}

void Swiat::setPosEnemy() {
	posEnemy.clear();
	posEnemy.push_back(sf::Vector2i(0, 2));
	posEnemy.push_back(sf::Vector2i(6, 12));
	posEnemy.push_back(sf::Vector2i(7, 2)); 
}

void Swiat::setKafelki() {
	kafelki.clear();
	std::vector<Kafelek*> pWiersz;
	pWiersz.push_back(new Kafelek("map.png", 0, 0, 0, 0, true, false));

}