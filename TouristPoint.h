#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.h"
using namespace std;

class TouristPoint
{
private:
	float x, y; //Coordenadas
	string name;
	sf::Color color;
	bool coordinatesAssigned;
	bool isPressed; 

public:
	TouristPoint();
	TouristPoint(string name);

	//Setters.
	void setX(float x);
	void setY(float y);
	void setName(string name);
	void setColor(sf::Color);
	void setCoordinatesAssigned(bool state);

	//Getters.
	float getX();
	float getY();
	string getName();
	sf::Color getColor();
	bool getCoordinatesAssigned();
	bool getIsPressed();

	//Methods.
	bool checkIfClicked(sf::Event event, sf::RenderWindow& window);

	void cubicSplineInterpolation(TouristPoint points[], int num_points, sf::RenderWindow& window, int num_points_per_segment = 10);

	void setCoordinates(sf::Event event, sf::RenderWindow& window);

	void drawTouristPoint(sf::RenderWindow& window, GraphicsManager& graphic);
};

