#include "TouristRoute.h"

int TouristRoute::increaseY = 0;

TouristRoute::TouristRoute() { 
	name = " "; 
	x = 0;
	y = 0;
	increaseY ++;
    pointsList = new LinkedList<TouristPoint>(); 
}

TouristRoute::TouristRoute(string name) { 
	this->name = name; 
	x = 200;
	y = 200 + (increaseY * 10);
	increaseY ++;
	pointsList = new LinkedList<TouristPoint>();
}

void TouristRoute::setName(string name) { this->name = name; }
void TouristRoute::setX(int x) { this->x = x; }
void TouristRoute::setY(int y) { this->y = y; }
void TouristRoute::setTouristPoint(TouristPoint* point) { pointsList->addToEnd(point); }

string TouristRoute::getName() { return name; }
int TouristRoute::getX() { return x; }
int TouristRoute::getY() { return y; }

TouristRoute::~TouristRoute() {
	delete pointsList;
}
