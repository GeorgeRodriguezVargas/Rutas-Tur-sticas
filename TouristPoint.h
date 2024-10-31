#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class TouristPoint
{
private:
	int x, y; //Coordenadas
	string name;
	sf::Color color;

public:
	TouristPoint();
	TouristPoint(int x, int y, string name);

	void setX(int x);
	void setY(int y);
	void setName(string name);

	int getX();
	int getY();
	string getName();
};

