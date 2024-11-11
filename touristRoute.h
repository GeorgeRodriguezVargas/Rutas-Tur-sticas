#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>
#include "LinkedList.h"
#include "TouristPoint.h"


class TouristRoute
{
private:
	string name;
	int x, y; //Coordenadas
	static int increaseY;
	LinkedList<TouristPoint>* pointsList;
	

public:
	TouristRoute();
	TouristRoute(string name);

	void setName(string name);
	void setX(int x);
	void setY(int y);
	void setTouristPoint(TouristPoint* point);

	string getName();
	int getX();
	int getY();

	

	~TouristRoute();
};

