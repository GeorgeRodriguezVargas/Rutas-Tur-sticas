#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>
#include "LinkedList.h"
#include "TouristPoint.h"
#include "GraphicsManager.h"


class TouristRoute
{
private:
	string name;
	int y; //Coordinate Y.
	static int increaseY; 
	LinkedList<TouristPoint>* pointsList;
	
public:
	TouristRoute();
	TouristRoute(string name);

	//Setters.
	void setName(string name);
	void setY(int y);
	void setTouristPoint(TouristPoint* point);

	//Getters.
	string getName();
	int getY();
	LinkedList<TouristPoint>* getPointsCollection();

	//Methods.
	void showRoutePoints(sf::RenderWindow& window, GraphicsManager& graphic);
	bool selectPoint(sf::Event event, sf::RenderWindow& window);
	
	~TouristRoute();
};

