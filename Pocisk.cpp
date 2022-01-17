#include "Pocisk.h"
#include "Gracz.h"

#include <math.h>

Pocisk::Pocisk(int pociskSpeed, int pociskSize, Gracz& player)
{
	kula.setSize(sf::Vector2f(pociskSize,pociskSize));
	kula.setFillColor(sf::Color::Black);
	//kula.setPosition(playerCenter);
	PociskSpeed = pociskSpeed;
	//printf("Player Center = [%f][%f]\n", playerCenter.x, playerCenter.y);
	//printf("pociskSource = [%f][%f]\n", pociskSource.x, pociskSource.y);
}

void Pocisk::strzela()
{	
	if(isRight)
		kula.move(PociskSpeed * 0.3f, 0);
	else
		kula.move(-PociskSpeed * 0.3f , 0);
}

void Pocisk::updateMouse(sf::RenderWindow& window, sf::View& widok)
{

	/*if (playerCenter.x < sf::Mouse::getPosition().x)
		a = abs(playerCenter.x - sf::Mouse::getPosition().x);
	if (playerCenter.x > sf::Mouse::getPosition().x)
		a = -abs(playerCenter.x - sf::Mouse::getPosition().x);
	if (playerCenter.y < sf::Mouse::getPosition().y)
		b = abs(playerCenter.y - sf::Mouse::getPosition().y);
	if (playerCenter.y > sf::Mouse::getPosition().y)
		b = -abs(playerCenter.y - sf::Mouse::getPosition().y);*/
	
	//dirY = (b * PociskSpeed) / a;
	pociskSource = sf::Vector2f(widok.getCenter());
	mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePos - pociskSource;
	float temp = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirNorm = aimDir / temp;

	//printf("[%f][%f]\n", aimDirNorm.x, aimDirNorm.y);



}

void Pocisk::setPos(sf::Vector2f newPos)
{
	kula.setPosition(newPos);
	//pociskSource = newPos;
}

void Pocisk::setPociskSource(sf::Vector2f newPos)
{
	pociskSource = newPos;
}

bool Pocisk::kolizja_sciana(sf::RectangleShape sciana)
{
	
	sf::FloatRect pociskBounds = kula.getGlobalBounds();
	sf::FloatRect scianaBounds = sciana.getGlobalBounds();

	if (pociskBounds.intersects(scianaBounds))
		{
			return true;
		}
		else
			return false;


	
}

void Pocisk::Draw(sf::RenderWindow& window) {
	window.draw(kula);
}