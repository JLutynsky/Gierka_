#pragma once
#include <SFML/Graphics.hpp>

class Kolizja
{
public:
	Kolizja(sf::RectangleShape& body);
	~Kolizja();

	void Move(float dx, float dy) { cialo.move(dx, dy); }

	bool checkKolizja(Kolizja& other, float push);
	sf::Vector2f GetPosition() { return cialo.getPosition(); }
	sf::Vector2f GetHalfSize() { return cialo.getSize() / 2.0f ; }

private:
	sf::RectangleShape& cialo;

};

