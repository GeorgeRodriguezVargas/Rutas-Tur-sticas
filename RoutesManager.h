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
	
	void addTouristRoute(TouristRoute* route);
	
	~RoutesManager();

};

