#include "TouristPoint.h"

TouristPoint::TouristPoint() {
	x, y = 0;
	name = "";
	color = sf::Color::Transparent;
	coordinatesAssigned = false;
	isPressed = false; 
}


TouristPoint::TouristPoint(string name) {
	this->name = name;
	x, y = 0;
	color = sf::Color::Transparent;
	coordinatesAssigned = false;
	isPressed = false; 
}


//Setters.
void TouristPoint::setX(float x) { this->x = x; }
void TouristPoint::setY(float y) { this->y = y; }
void TouristPoint::setName(string name) { this->name = name; }
void TouristPoint::setColor(sf::Color color) { this->color = color; }
void TouristPoint::setCoordinatesAssigned(bool state) { this->coordinatesAssigned = state; }


//Getters.
float TouristPoint::getX() { return x; }
float TouristPoint::getY() { return y; }
string TouristPoint::getName() { return name; }
sf::Color TouristPoint::getColor() { return color; }
bool TouristPoint::getCoordinatesAssigned() { return coordinatesAssigned; }
bool TouristPoint::getIsPressed() { return isPressed; }

//Tourist point clicked on the map.
bool TouristPoint::checkIfClicked(sf::Event event, sf::RenderWindow& window) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

		float distance = std::sqrt(std::pow(worldPos.x - x, 2) + std::pow(worldPos.y - y, 2));
		if (distance <= 7.0f) { 
			isPressed = true;
			return true;
		}
	}
	isPressed = false;
	return false;
}


//Receives as parameters the selected coordinates to place the point.
void TouristPoint::setCoordinates(sf::Event event, sf::RenderWindow& window) {

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { 
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

		this->x = worldPos.x;
		this->y = worldPos.y;
		coordinatesAssigned = true;
    }
}


//Graphic represention of point.
void TouristPoint::drawTouristPoint(sf::RenderWindow& window, GraphicsManager& graphic) { //This method to draw a circle is not built in GraphicManager because I dont't
	sf::CircleShape circle(7);                                                            //think it's necessary to add a graphicalM object just for a method (optimization).
	sf::Text text = graphic.bodyText(15, name, sf::Color::White, x + 5, y);
	circle.setOrigin(7, 7);                                     
	circle.setPosition(x, y);
	circle.setFillColor(color);

	window.draw(text);
	window.draw(circle);
}

