#include "RoutesManager.h"
RoutesManager::RoutesManager() {
	routesList = new LinkedList<TouristRoute>();
}

void RoutesManager::addTouristRoute(TouristRoute* route) { routesList->addToEnd(route); }

RoutesManager::~RoutesManager() {
	delete routesList;
}