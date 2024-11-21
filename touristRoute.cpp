#include "TouristRoute.h"

//Position to print on screen.
int TouristRoute::increaseY = 0;


TouristRoute::TouristRoute() { 
	name = " "; 
	y = 0;
	increaseY ++;
    pointsList = new LinkedList<TouristPoint>(); 
}


TouristRoute::TouristRoute(string name) { 
	this->name = name; 
	y =  180 + (increaseY * 35);
	increaseY ++;
	pointsList = new LinkedList<TouristPoint>();
}


//Setters.
void TouristRoute::setName(string name) { this->name = name; }
void TouristRoute::setY(int y) { this->y = y; }
void TouristRoute::setTouristPoint(TouristPoint* point) { pointsList->addToEnd(point); }


//Getters.
string TouristRoute::getName() { return name; }
int TouristRoute::getY() { return y; }
LinkedList<TouristPoint>* TouristRoute::getPointsCollection() { return nullptr; }


//Methods.
void TouristRoute::showRoutePoints(sf::RenderWindow& window, GraphicsManager& graphic) {
	Node<TouristPoint>* temp = pointsList->getHead();
	while (temp != nullptr) {
		temp->getData()->drawTouristPoint(window, graphic);
		temp = temp->getNext();
	}
}


bool TouristRoute::selectPoint(sf::Event event, sf::RenderWindow& window){
	Node<TouristPoint>* temp = pointsList->getHead();
	while (temp != nullptr) {


		if (temp->getData()->checkIfClicked(event, window)) {
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}


TouristRoute::~TouristRoute() {
	delete pointsList;
}