#include "TouristPoint.h"
TouristPoint::TouristPoint() {
	x, y = 0;
	name = "";
}

TouristPoint::TouristPoint(int x, int y, string name) {
	this->x = x;
	this->y = y;
	this->name = name;
}

void TouristPoint::setX(int x) { this->x = x; }
void TouristPoint::setY(int y) { this->y = y; }
void TouristPoint::setName(string name) { this->name = name; }

int TouristPoint::getX() { return x; }
int TouristPoint::getY() { return y; }
string TouristPoint::getName() { return name; }