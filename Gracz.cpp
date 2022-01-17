#include "Gracz.h"

Gracz::Gracz(sf::Texture* tekstura, sf::Vector2u liczbaKlatek, float switchTime, float szybkosc) :
	animacja(tekstura, liczbaKlatek, switchTime)
{
	this->szybkosc = szybkosc;
	wiersz = 0;
	czyPrawy = true;
	
	cialo.setSize(sf::Vector2f(16, 16));
	cialo.setTexture(tekstura);
	cialo.setPosition(16, 16.5* 16);
}

void Gracz::Update(float deltaTime)
{
	sf::Vector2f ruch(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		szybkosc = 160;
		ruch.x -= szybkosc * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		szybkosc = 160;
		ruch.x += szybkosc * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		szybkosc = 160;
		ruch.y -= szybkosc * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		szybkosc = 160;
		ruch.y += szybkosc * deltaTime;
	}

	if (ruch.x == 0.0f) 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			wiersz = 2;
		if (isHit)
			wiersz = 3;
		else
			wiersz = 0;
	}

	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			wiersz = 2;
		else
			wiersz = 1;
		if (isHit)
			wiersz = 4;

		if (ruch.x > 0.0f)
			czyPrawy = true;
		else
			czyPrawy = false;
	}
	animacja.Update(wiersz, deltaTime * 3, czyPrawy);
	cialo.setTextureRect(animacja.uvRect);
	cialo.move(ruch);

}

void Gracz::Draw(sf::RenderWindow& window)
{
	window.draw(cialo);
}

void Gracz::Kolizja_sciana(sf::RectangleShape sciana)
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
			this->szybkosc= 0.f;
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
