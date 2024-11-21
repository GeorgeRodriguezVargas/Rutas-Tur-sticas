#include "RoutesManager.h"
RoutesManager::RoutesManager() {
	routesCollection = new LinkedList<TouristRoute>();
}


void RoutesManager::addTouristRoute(TouristRoute* route) { 
	routesCollection->addToEnd(route);
	cout << route->getName() << " ha sido agregada a tu lista de rutas." << endl;
}


//Getters.
LinkedList<TouristRoute>* RoutesManager::getRoutesCollection() { return routesCollection; }


//visually displays a list of boxes with the added routes
void RoutesManager::showRouteListMenu(sf::RenderWindow& window, sf::Color color, GraphicsManager& graphic) {
	int auxY = 185; //name position.
	Node<TouristRoute>* temp = routesCollection->getHead();
	
	while (temp != nullptr) {
		int y = temp->getData()->getY(); //Each route has a position Y.

		graphic.getResource3().setPosition(5, y);
		sf::Text text = graphic.bodyText(19, temp->getData()->getName(), color, 35, auxY);
		window.draw(graphic.getResource3());
		window.draw(text);

		temp = temp->getNext();
		auxY += 35; //Increase name position.
	}
}


//Scroll through the routesCollection to show all points.
void RoutesManager::showRouteListMap(sf::RenderWindow& window, GraphicsManager& graphic){
	Node<TouristRoute>* temp = routesCollection->getHead();

	while (temp != nullptr) {
		temp->getData()->showRoutePoints(window, graphic);
		temp = temp->getNext();
	}
}


TouristRoute* RoutesManager::selectRoute(sf::Event event, sf::RenderWindow& window, GraphicsManager graphic){
	Node<TouristRoute>* temp = routesCollection->getHead();
	while (temp != nullptr) {
		
		if (temp->getData()->selectPoint(event, window)) {
			return temp->getData(); 
		}
		temp = temp->getNext();
	}
	return nullptr;
}


RoutesManager::~RoutesManager() {
	delete routesCollection;
}