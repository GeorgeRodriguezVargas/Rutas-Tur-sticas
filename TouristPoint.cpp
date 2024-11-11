#include "TouristPoint.h"
TouristPoint::TouristPoint() {
	x, y = 0;
	name = "";
	color = sf::Color::Transparent;
}

TouristPoint::TouristPoint(float x, float y, string name, sf::Color color) {
	this->x = x;
	this->y = y;
	this->name = name;
	this->color = color;
}

void TouristPoint::setX(float x) { this->x = x; }
void TouristPoint::setY(float y) { this->y = y; }
void TouristPoint::setName(string name) { this->name = name; }
void TouristPoint::setColor(sf::Color color) { this->color = color; }

float TouristPoint::getX() { return x; }
float TouristPoint::getY() { return y; }
string TouristPoint::getName() { return name; }
sf::Color TouristPoint::getColor() { return color; }

void TouristPoint::setCoordinates(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // botón izquierdo del mouse

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);// Obtener las coordenadas del clic

        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);// Convertir las coordenadas

		this->x = worldPos.x;
		this->y = worldPos.y;
    }
}

//Graphic represention of point.
void TouristPoint::drawTouristPoint(sf::RenderWindow& window) { //This method to draw a circle is not built in GraphicManager because I dont't
	sf::CircleShape circle(7);                                  //think it's necessary to add a graphicalM object just for a method (optimization).
	circle.setOrigin(7, 7);                                     
	circle.setPosition(x, y);
	circle.setFillColor(color);
	window.draw(circle);
}

