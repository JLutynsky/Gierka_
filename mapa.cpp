#include "mapa.h"
#include "tekstury.h"
#include <vector>

bool Mapa::load(const std::string& arkusz, sf::Vector2u rKafelka, const int* kafelki, unsigned int szerokosc, unsigned int wysokosc)
{
    if(!m_tileset.loadFromFile(arkusz))
        return false;

    std::vector <int> sciana;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(szerokosc * wysokosc * 4);

    for(unsigned int i = 0; i < szerokosc; ++i)
        for (unsigned int j = 0; j < wysokosc; ++j)
        {
            int indeks = kafelki[i + j * szerokosc];

            int tu = indeks % (m_tileset.getSize().x / rKafelka.x);
            int tv = indeks / (m_tileset.getSize().x / rKafelka.x);

            sf::Vertex* quad = &m_vertices[(i + j * szerokosc) * 4];

            quad[0].position = sf::Vector2f(i * rKafelka.x, j * rKafelka.y);
            quad[1].position = sf::Vector2f((i + 1) * rKafelka.x, j * rKafelka.y);
            quad[2].position = sf::Vector2f((i + 1) * rKafelka.x, (j + 1) * rKafelka.y);
            quad[3].position = sf::Vector2f(i * rKafelka.x, (j + 1) * rKafelka.y);

            quad[0].texCoords = sf::Vector2f(tu * rKafelka.x, tv * rKafelka.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * rKafelka.x, tv * rKafelka.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * rKafelka.x, (tv + 1) * rKafelka.y);
            quad[3].texCoords = sf::Vector2f(tu * rKafelka.x, (tv + 1) * rKafelka.y);

            
            
            

            if (indeks == wall || indeks == tree || indeks == monk)
            {
                sf::RectangleShape nowaSciana;
                nowaSciana.setSize(sf::Vector2f(rKafelka));
                nowaSciana.setFillColor(sf::Color::Transparent);
                nowaSciana.setPosition(sf::Vector2f(i * rKafelka.x, j * rKafelka.y));

                kwadraciki.push_back(nowaSciana);
            }

        }


    return true;
}

void Mapa::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices, states);

    for (int i = 0; i < kwadraciki.size(); i++)
    {
        target.draw(kwadraciki[i], states);
    }

}


