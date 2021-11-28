//Gra jest o tematyce golebia. Sterowanie odbedzie sie za pomoca klawiszy wasd oraz celowanie za pomoca myszki.

#include "SFML/Graphics.hpp"

int main(int argc, char** argv) {
		sf::RenderWindow renderWindow(sf::VideoMode(384, 216), "Tytul");
		sf::Event event;

		sf::Texture golabT;
		golabT.loadFromFile("sprity/golab.png");

		sf::IntRect klatka(0, 0, 16, 16);
		sf::Sprite golab(golabT, klatka);

		sf::Clock zegar;
		int dir = 1;

		while (renderWindow.isOpen())
		{
			while (renderWindow.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
					renderWindow.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				renderWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				golab.move(0.4, 0);
				dir = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				golab.move(-0.4, 0);
				dir = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				golab.move(0, 0.4);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				golab.move(0, -0.4);
			}

			if (zegar.getElapsedTime().asMilliseconds() > 200.0f )
			{
				switch (dir)
				{
				case 1:
					klatka.top = 0;
				case -1:
					klatka.top = 16;
				}
				
				if (klatka.left == 48)
					klatka.left = 0;
				else
					klatka.left += 16;

				golab.setTextureRect(klatka);
				zegar.restart();
			}

			renderWindow.clear(sf::Color::White);
			renderWindow.draw(golab);
			renderWindow.display();

		}
}