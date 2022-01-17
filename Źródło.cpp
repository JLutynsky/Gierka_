//Gra jest o tematyce golebia. Sterowanie odbedzie sie za pomoca klawiszy wasd oraz celowanie za pomoca myszki.

#include "SFML/Graphics.hpp"
#include "mapa.h"
#include "tekstury.h"
#include "Animacja.h"
#include "Gracz.h"
#include "Kruk.h"
#include "Pocisk.h"
#include "Textbox.h"
#include "Menu.h"
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 
#include <vector>
#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char** argv) {
		sf::RenderWindow renderWindow(sf::VideoMode(512, 256), "Golomb", sf::Style::Fullscreen);
		Menu menu(512, 256);
		sf::View view2(sf::Vector2f(256, 128), sf::Vector2f(512, 256));
		renderWindow.setView(view2);
		sf::Event event;
		sf::Vector2u tempDim;
		int i;
		int liczbaKrukow = 10;
		int randX, randY;
		float randSpeed;
		bool czyStrzela, strzal;
		bool gameOver = false;
		int gameMode = 0;
		int waveNum = 1;
		int currentLevel;
		int difficulty;

		srand(time(NULL));

		sf::Texture graczTekstura;
		sf::Texture krukTekstura;
		sf::Font czcionka;

		graczTekstura.loadFromFile("sprity/golab2.png");
		krukTekstura.loadFromFile("sprity/kruk.png");
		czcionka.loadFromFile("font/font.ttf");

		Gracz gracz(&graczTekstura, sf::Vector2u(4,5), 0.3f, 160);
		//Kruk kruk(&krukTekstura, sf::Vector2u(4,3), 0.3f, 160);
		sf::Clock hitClock;
		
		std::vector<Kruk> wszystkie_kruki;
		std::vector<Pocisk> wszystkie_pociski;

	

		for (i = 0; i < liczbaKrukow; i++)
		{
			randX = 16 + rand() % ((64 - 32)*16);
			randY = 16 + rand() % (256 - 32);
			randSpeed = 10 + rand() % 50;

			Kruk spawnKruk(&krukTekstura, sf::Vector2u(4, 3), 0.3f, 80);
			spawnKruk.setPos(randX, randY);
			spawnKruk.setSpeed(randSpeed);

			wszystkie_kruki.push_back(spawnKruk);
		
		}

		Textbox licznikPunktow(sf::Vector2f(64, 16), sf::Vector2f(16, 16), "punkty: ", czcionka, 1, 1, 0, sf::Color::Yellow);
		Textbox licznikHP(sf::Vector2f(128, 16), sf::Vector2f(512-16-128, 16), "zdrowie: ", czcionka, 1, 1, 100, sf::Color::Red);
		Textbox pauzer(sf::Vector2f(64, 16), sf::Vector2f(16, 16), "PAUZA", czcionka, 0, 0, 3000, sf::Color::White);
		Textbox zasady(sf::Vector2f(64, 16), sf::Vector2f(16, 16), "ZASADY", czcionka, 1, 0, 3000, sf::Color::Red);
		Textbox zasadyContent(sf::Vector2f(256, 128), sf::Vector2f(16, 64), "Sterowanie:\nStrzalka w gore - ruch w gore\nStrzalka w dol - ruch w dol\nStrzalka w lewo - ruch w lewo\nStrzalka w prawo - ruch w prawo\nZ - strzal!\n P - Pauza\n\n\nZABIJ WSZYSTKIE KRUKI!!!!!", czcionka, 1, 0, 3000, sf::Color::Black);
		Textbox escaper(sf::Vector2f(512 - 32, 16), sf::Vector2f(16, 256 - 32), "Czy na pewno chcesz zakonczyc gre? Wcisnij 1, alby potwierdzic!", czcionka, 1, 0, 3000, sf::Color::Black);

		float deltaTime = 0.0f;
		sf::Clock zegar;

		while (renderWindow.isOpen())
		{
			deltaTime = zegar.restart().asSeconds();

			renderWindow.clear(sf::Color(50,50,50,255));
			
			if (wszystkie_kruki.size() == 0) {

				for (i = 0; i < liczbaKrukow; i++)
				{
					randX = 16 + rand() % ((64 - 32) * 16);
					randY = 16 + rand() % (256 - 32);
					randSpeed = 10 + rand() % 50;

					Kruk spawnKruk(&krukTekstura, sf::Vector2u(4, 3), 0.3f, 80);
					spawnKruk.setPos(randX, randY);
					spawnKruk.setSpeed(randSpeed);

					wszystkie_kruki.push_back(spawnKruk);

				}
			}

			if (licznikHP.getCounter() == 0)
			{
				std::fstream plik2;
				plik2.open("wyniki.txt", std::ios::out | std::ios::app);
				plik2 << licznikPunktow.getCounter() << std::endl;
				plik2.close();
				
				renderWindow.close();
			}

			while (renderWindow.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
					renderWindow.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						menu.przesunG();
					}
										
					if (event.key.code == sf::Keyboard::Down)
					{
						menu.przesunD();
					}
					if (gameMode == 0)
					{
						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 0)
						{
							gameMode = 1;
							currentLevel = 1;
						}
											
						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1)
						{
							gameMode = 1;
							currentLevel = 2;
						}
											
						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2)
						{
							gameMode = 2;
						}

						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3)
						{
							renderWindow.close();
						}
											
					}
									
										
				}			
			}
			if (gameMode == 2)
			{
				
				sf::Text teksty[10];

				for (i = 0; i < 10; i++)
				{
					teksty[i].setFont(czcionka);
					teksty[i].setCharacterSize(100);
					teksty[i].setScale(0.1, 0.1);
					teksty[i].setPosition(sf::Vector2f(64, 16 * i));
				}

				int j = 0;
				std::string line;

				std::ifstream plik1("wyniki.txt");
				if (plik1.is_open())
				{
					while (getline(plik1, line))
					{
						teksty[j].setString("Punkty: " + line);
						renderWindow.draw(teksty[j]);
						j++;
					}
					plik1.close();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					gameMode = 0;

			}
			if (gameMode == 1) {


				Mapa swiat;
				if (currentLevel == 1)
				{
					if (!swiat.load("sprity/map4.png", sf::Vector2u(16, 16), level1, 64, 32))
						return -1;
				}
				if (currentLevel == 2)
				{
					if (!swiat.load("sprity/map4.png", sf::Vector2u(16, 16), level2, 64, 32))
						return -1;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					pauzer.Draw(renderWindow);
				}
				else 
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
				{
					zasady.Draw(renderWindow);
					zasadyContent.Draw(renderWindow);

				}
				else
				{
					renderWindow.draw(swiat);
					for (int i = 0; i < swiat.kwadraciki.size(); i++)
					{
						gracz.Kolizja_sciana(swiat.kwadraciki[i]);
						//kruk.Kolizja_sciana(swiat.kwadraciki[i]);

						for (int j = 0; j < wszystkie_kruki.size(); j++) {
							wszystkie_kruki[j].Kolizja_sciana(swiat.kwadraciki[i]);
						}

						for (int j = 0; j < wszystkie_pociski.size(); j++) {
							if (wszystkie_pociski[j].kolizja_sciana(swiat.kwadraciki[i]))
							{
								wszystkie_pociski.erase(begin(wszystkie_pociski) + j);
							}
						}

					}



					//kruk.ganianyPos = gracz.GetPosition();
					//kruk.Update(deltaTime);
					//kruk.Draw(renderWindow);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						czyStrzela = true;
						strzal = true;
					}
					else
						strzal = false;


					if (czyStrzela == true && strzal == false) {
						Pocisk spawnPocisk(5, 3, gracz);

						if (gracz.czyPrawy)
							spawnPocisk.isRight = true;
						if (!gracz.czyPrawy)
							spawnPocisk.isRight = false;


						sf::Vector2f tempVector(gracz.GetPosition().x + 8, gracz.GetPosition().y + 8);
						spawnPocisk.setPos(sf::Vector2f(gracz.GetPosition().x + 8, gracz.GetPosition().y + 8));
						spawnPocisk.updateMouse(renderWindow, view2);
						spawnPocisk.setPociskSource(tempVector);
						wszystkie_pociski.push_back(spawnPocisk);
						czyStrzela = false;

						//printf("\nTEMP VECTOR = [%f] [%f]\n", tempVector.x, tempVector.y);
					}

					for (int i = 0; i < wszystkie_kruki.size(); i++)
					{
						for (int j = 0; j < wszystkie_kruki.size(); j++)
						{
							wszystkie_kruki[i].Kolizja_kruk(wszystkie_kruki[j]);
						}
					}
					for (int i = 0; i < wszystkie_kruki.size(); i++)
					{
						for (int j = 0; j < wszystkie_pociski.size(); j++)
						{
							if (wszystkie_kruki[i].Kolizja_pocisk(wszystkie_pociski[j]))
							{
								wszystkie_kruki.erase(begin(wszystkie_kruki) + i);
								wszystkie_pociski.erase(begin(wszystkie_pociski) + j);
								licznikPunktow.updateCounter(1, 2);
							}
						}
					}



					float hitSeconds = hitClock.getElapsedTime().asSeconds();


					for (int i = 0; i < wszystkie_kruki.size(); i++)
					{
						if (wszystkie_kruki[i].Kolizja_gracz(gracz) && !gracz.isHit)
						{
							licznikHP.updateCounter(10, 1);

							//hitClock.restart();

							gracz.isHit = true;

						}
						if (hitSeconds > 3)
						{
							gracz.isHit = false;
							hitClock.restart();
						}

					}

					for (int i = 0; i < wszystkie_kruki.size(); i++)
					{
						wszystkie_kruki[i].ganianyPos = gracz.GetPosition();
						wszystkie_kruki[i].Update(deltaTime);
						wszystkie_kruki[i].Draw(renderWindow);

					}

					for (int i = 0; i < wszystkie_pociski.size(); i++)
					{
						wszystkie_pociski[i].Draw(renderWindow);
						wszystkie_pociski[i].strzela();
					}
					gracz.Update(deltaTime);
					gracz.Draw(renderWindow);
					view2.setCenter(gracz.GetPosition());
					licznikPunktow.updateView(view2);
					licznikHP.updateView(view2);
					renderWindow.setView(view2);
					licznikPunktow.Draw(renderWindow);
					licznikHP.Draw(renderWindow);
					pauzer.updateView(view2);
					zasady.updateView(view2);
					zasadyContent.updateView(view2);
					escaper.updateView(view2);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						escaper.Draw(renderWindow);
						
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
						{
							std::fstream plik;
							plik.open("wyniki.txt", std::ios::out | std::ios::app);
							plik << licznikPunktow.getCounter() << std::endl;
							plik.close();


							renderWindow.close();
						}
					}

				}
			}
			if (gameMode == 0)
				menu.draw(renderWindow);
			renderWindow.display();
			

		}

}

