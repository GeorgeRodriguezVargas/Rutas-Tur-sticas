#pragma once
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
#include "LinkedList.h"
#include "TouristRoute.h"

class RoutesManager
{
private:
	LinkedList<TouristRoute>* routesCollection;

public:
	RoutesManager();
	
	//Methods.
	void addTouristRoute(TouristRoute* route);
	void showRouteListMenu(sf::RenderWindow& window, sf::Color color, GraphicsManager& graphic);
	void showRouteListMap(sf::RenderWindow& window, GraphicsManager& graphic);
	TouristRoute* selectRoute(sf::Event event, sf::RenderWindow& window, GraphicsManager graphic);
	
	LinkedList<TouristRoute>* getRoutesCollection();

	~RoutesManager();
};

