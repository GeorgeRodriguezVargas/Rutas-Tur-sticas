#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class TouristPoint
{
private:
	float x, y; //Coordenadas
	string name;
	sf::Color color;

public:
	TouristPoint();
	TouristPoint(float x, float y, string name, sf::Color);

	void setX(float x);
	void setY(float y);
	void setName(string name);
	void setColor(sf::Color);

	float getX();
	float getY();
	string getName();
	sf::Color getColor();

	void setCoordinates(sf::Event event, sf::RenderWindow& window);

	void drawTouristPoint(sf::RenderWindow& window);
};

