#pragma once
#include <SFML/Graphics.hpp>

#ifndef MAPA_H
#define MAPA_H

class Mapa : public sf::Drawable, public sf::Transformable 
{
public:
	bool load(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);
	std::vector<sf::RectangleShape> kwadraciki;
private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

#endif