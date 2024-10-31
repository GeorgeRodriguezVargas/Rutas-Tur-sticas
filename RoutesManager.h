#pragma once
using namespace std;
#include <iostream>
#include "LinkedList.h"
#include "TouristRoute.h"

class RoutesManager
{
private:
	LinkedList<TouristRoute>* routesList;
	
public:
	RoutesManager();
	
	void setRoute(TouristRoute& route);

	~RoutesManager();
};

