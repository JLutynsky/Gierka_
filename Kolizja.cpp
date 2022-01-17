#include "Kolizja.h"

Kolizja::Kolizja(sf::RectangleShape& cialo) :
	cialo(cialo)
{
	
}

bool Kolizja::checkKolizja(Kolizja& other, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfsize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	
	float intersectX = abs(deltaX) - (otherHalfsize.x - thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfsize.y - thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) 
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX < intersectY) 
		{
			if (deltaX < 0)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY < 0)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f ,intersectY * push);
			}
		}
		
		return true;
	}
	
	return false;
}
