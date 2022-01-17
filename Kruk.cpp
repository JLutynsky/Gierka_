#include "Kruk.h"
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h>
#include "Gracz.h"
#include <math.h>
#include <algorithm>
#include <iostream>


Kruk::Kruk(sf::Texture* tekstura, sf::Vector2u liczbaKlatek, float switchTime, float szybkosc) :
	animacja(tekstura, liczbaKlatek, switchTime)
{
	generedKrukSpeed = szybkosc;
	this->szybkosc = szybkosc;
	
	wiersz = 0;
	czyPrawy = true;
	


	cialo.setSize(sf::Vector2f(16, 16));
	cialo.setTexture(tekstura);
}

void Kruk::Update(float deltaTime)
{
	sf::Vector2f ruch(0.0f, 0.0f);

	szybkosc = kruk_speed;

	playerDistanceVect = ganianyPos - cialo.getPosition();
	playerDistance = sqrt(pow(playerDistanceVect.x, 2) + pow(playerDistanceVect.y, 2));

	int isMinusX = rand()%2;
	int isMinusY = rand()%2;

	float modX = 1+ rand() % 2;
	float modY = 1+ rand() % 2;

	if (playerDistance < 200) {

		if (cialo.getPosition().x < ganianyPos.x)
			ruch.x += szybkosc * deltaTime;
		if (cialo.getPosition().x > ganianyPos.x)
			ruch.x -= szybkosc * deltaTime;
		if (cialo.getPosition().y < ganianyPos.y)
			ruch.y += szybkosc * deltaTime;
		if (cialo.getPosition().y > ganianyPos.y)
			ruch.y -= szybkosc * deltaTime;
	}

		if (ruch.x >= 0.0f)
			czyPrawy = true;
		else
			czyPrawy = false;
		


		if (playerDistance < 64) {
			wiersz = 2;
			float newSpeed = std::min(kruk_speed * 1.01f, 100.f);
			setSpeed(newSpeed);
		}
		else {
			wiersz = 0;
			setSpeed(generedKrukSpeed);
		}

	animacja.Update(wiersz, deltaTime * 3, czyPrawy);
	cialo.setTextureRect(animacja.uvRect);
	cialo.move(ruch);

	


}

void Kruk::Draw(sf::RenderWindow& window)
{
	window.draw(cialo);
}

void Kruk::setPos(int posX, int posY)
{
	cialo.setPosition(posX, posY);
}

void Kruk::setSpeed(float szybkoscKruka)
{
	kruk_speed = szybkoscKruka;
}

void Kruk::Kolizja_sciana(sf::RectangleShape sciana)
{


	sf::FloatRect playerBounds = cialo.getGlobalBounds();
	sf::FloatRect wallBounds = sciana.getGlobalBounds();
	if (playerBounds.intersects(wallBounds))
	{
		if (playerBounds.left < wallBounds.left
			&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
		}

		if (playerBounds.left > wallBounds.left
			&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
			&& playerBounds.top < wallBounds.top + wallBounds.height
			&& playerBounds.top + playerBounds.height > wallBounds.top
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
		}


		if (playerBounds.top > wallBounds.top
			&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height + playerBounds.height - 3
			&& playerBounds.left < wallBounds.left + wallBounds.width
			&& playerBounds.left + playerBounds.width > wallBounds.left
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
		}


		if (playerBounds.top < wallBounds.top
			&& playerBounds.top < wallBounds.top - playerBounds.height + 3
			&& playerBounds.left < wallBounds.left + wallBounds.width
			&& playerBounds.left + playerBounds.width > wallBounds.left
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
		}

	}



}

void Kruk::Kolizja_kruk(Kruk innyKruk)
{

	sf::RectangleShape cialoInnegoKruka = innyKruk.cialo;


	sf::FloatRect playerBounds = cialo.getGlobalBounds();
	sf::FloatRect krukBounds = cialoInnegoKruka.getGlobalBounds();
	if (playerBounds.intersects(krukBounds))
	{
		if (playerBounds.left < krukBounds.left
			&& playerBounds.left + playerBounds.width < krukBounds.left + krukBounds.width
			&& playerBounds.top < krukBounds.top + krukBounds.height
			&& playerBounds.top + playerBounds.height > krukBounds.top
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(krukBounds.left - playerBounds.width, playerBounds.top);
		}
		
		if (playerBounds.left > krukBounds.left
			&& playerBounds.left + playerBounds.width > krukBounds.left + krukBounds.width
			&& playerBounds.top < krukBounds.top + krukBounds.height
			&& playerBounds.top + playerBounds.height > krukBounds.top
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(krukBounds.left + krukBounds.width, playerBounds.top);
		}


		if (playerBounds.top > krukBounds.top
			&& playerBounds.top + playerBounds.height > krukBounds.top + krukBounds.height + playerBounds.height - 3
			&& playerBounds.left < krukBounds.left + krukBounds.width
			&& playerBounds.left + playerBounds.width > krukBounds.left
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(playerBounds.left, krukBounds.top + krukBounds.height);
		}


		if (playerBounds.top < krukBounds.top
			&& playerBounds.top < krukBounds.top - playerBounds.height + 3
			&& playerBounds.left < krukBounds.left + krukBounds.width
			&& playerBounds.left + playerBounds.width > krukBounds.left
			)
		{
			this->szybkosc = 0.f;
			this->cialo.setPosition(playerBounds.left, krukBounds.top - playerBounds.height);
		}

	}


}

bool Kruk::Kolizja_pocisk(Pocisk strzal)
{

	{


		sf::FloatRect playerBounds = cialo.getGlobalBounds();
		sf::FloatRect krukBounds = strzal.pociskBounds();

		if (playerBounds.intersects(krukBounds))
		{
			std::cout << "git" << std::endl;

			return true;

		}
		else
			return false;


	}

}

bool Kruk::Kolizja_gracz(Gracz player)
{
	sf::FloatRect krukBounds = cialo.getGlobalBounds();
	sf::FloatRect playerBounds = player.graczBounds();

	if (krukBounds.intersects(playerBounds))
	{
		//std::cout << "hit" << std::endl;

		return true;

	}
	else
		return false;
}

bool Kruk::dead(bool isDead)
{
	sf::Clock zegarSmierci;
	zegarSmierci.restart();

	float czasSmierci = zegarSmierci.getElapsedTime().asSeconds();

	generedKrukSpeed = 0;

	if (isDead)
		return true;

	return false;
}