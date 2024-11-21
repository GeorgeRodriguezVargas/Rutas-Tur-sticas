#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.h"
#include "TouristRoute.h"
#include "RoutesManager.h"
#include "LinkedList.h"
#include "Node.h"
#include "TouristPoint.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Window"); //Crear una ventana

    //objects used
    GraphicsManager graphic; 
    RoutesManager routesList;

    //SFML Objects
    sf::Color color;
    sf::Event event;

    //Colors 
    sf::Color lightGray = graphic.hexToColor("#d8d8ce");
    sf::Color darkGray = graphic.hexToColor("#747474");
    sf::Color blue = graphic.hexToColor("#5e17eb"); 

    //Text elements
    sf::Text firstTextBox = graphic.bodyText(20, "Agregar Ruta", lightGray, 71, 40);
    sf::Text secondTextBox = graphic.bodyText(20, "Agregar Punto", lightGray, 71, 96);
    sf::Text exploreText = graphic.bodyText(16, "Rutas", darkGray, 58, 148);
    sf::Text addToListText = graphic.bodyText(16, "Añadir", darkGray, 282, 148);
    sf::Text deleteText = graphic.bodyText(16, "Editar", darkGray, 282, 148);
    sf::Text editingModeText = graphic.bodyText(14, "Editar", darkGray, 318, 10);

    //Different flags to handle event
    bool routeButton = false;
    bool pointButton = false;
    bool routeListButton = false;
    bool addRouteButton = false;
    bool pointAddedButton = false;

    bool isAddRouteName = false;
    bool isAddPointName = false;
    bool isColorSelected = false;
    bool isCoordsSelected = false;
    bool isPointAdded = false;

    bool mouseOverButton = false;
    bool errorAlert = false;
    bool isRouteSelected = false;
    bool isEditingMode = false;
    bool routeSelected = false;
    
    //Auxiliaries
    string savedText = "";
    TouristRoute* newRoute = nullptr;
    TouristPoint* newPoint = nullptr;
    TouristRoute* selectedRoute = nullptr; //To select a route from the routeList.

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            //Close window event.
            if (event.type == sf::Event::Closed) {
                window.close();
            }


            //change the color of the text on the buttons.
            if (graphic.mouseOver(event, window, 61, 33, 282, 43, mouseOverButton) && !routeButton) {
                firstTextBox.setFillColor(blue);
            }
            else {firstTextBox.setFillColor(lightGray); }

            if (graphic.mouseOver(event, window, 61, 89, 282, 43, mouseOverButton) && !pointButton) {
                secondTextBox.setFillColor(blue);
            }
            else { secondTextBox.setFillColor(lightGray); }

            if (graphic.mouseOver(event, window, 58, 148, 55, 20, mouseOverButton)) {
                    exploreText.setFillColor(blue);
            }
            else { exploreText.setFillColor(darkGray); }

          
            //If a point has been added, the route can be saved.
            if (isPointAdded) {
                if (graphic.mouseOver(event, window, 282, 148, 55, 20, mouseOverButton)) {
                    addToListText.setFillColor(blue);
                }
                else { addToListText.setFillColor(darkGray); }
            }
            
            //Add Tourist Route.
            if (graphic.buttonEvent(event, window, 61, 33, 282, 43, routeButton) && !isAddRouteName) {
                firstTextBox.setString("");
                string current = graphic.inputText(event, savedText);
                firstTextBox.setString(current + "_"); 
                 
                if (!savedText.empty()) {
                    newRoute = new TouristRoute(savedText);
                    firstTextBox.setString(savedText); //Keeps the route name on the menu.
                    savedText.clear();
                    isAddRouteName = true; //Enable add Tourist point.
                }
            }
            
            //Add Tourist Point.
            if (graphic.buttonEvent(event, window, 61, 89, 282, 43, pointButton)) {
                if (isAddRouteName) { //Can only be added if there is a route.
                    secondTextBox.setString("");
                    string current = graphic.inputText(event, savedText);
                    secondTextBox.setString(current + "_"); 

                    if (!savedText.empty()) {
                        newPoint = new TouristPoint(savedText);
                        secondTextBox.setString(savedText);
                        savedText.clear();

                        pointButton = false; //Keeps the point name on the menu.
                        isAddPointName = true; //Enable select color.
                    }
                }
                else { errorAlert = true; } 
            }

            //allows select the position of the Tourist point correctly.
            if (isColorSelected && !isCoordsSelected) {
                isCoordsSelected = true; //Enable setCoordinates.
            }

            //Add Route to routeList.
            if (graphic.buttonEvent(event, window, 282, 148, 55, 20, pointAddedButton) && isPointAdded) {
                firstTextBox.setString("Agregar Ruta"); //Reset menu text.
                routesList.addTouristRoute(newRoute);

                //Reset everything again.
                isPointAdded = false;
                pointAddedButton = false;
                isAddRouteName = false;
                addRouteButton = false;
                routeButton = false;
            }

            //Edit mode.
            if (graphic.buttonEvent(event, window, 58, 148, 55, 20, routeListButton)) {
                if (!routeSelected) {
                    selectedRoute = routesList.selectRoute(event, window, graphic); 

                    if (selectedRoute != nullptr) {
                        routeSelected = true;  
                    }
                }
            }
            else {
                selectedRoute = nullptr;
                routeSelected = false;
            }
        }
        //Basic SFML functions.
        window.clear(sf::Color::White);
        window.draw(graphic.getBackgroundSprite());

       
        //Show error if route name not entered.
        if (errorAlert) {
            bool isOkClicked = false;
            if (graphic.buttonEvent(event, window, 754, 306, 57, 21, isOkClicked)) {
                errorAlert = false;
                pointButton = false;
            }
            else { graphic.displayError(window, lightGray, "Ingrese el nombre de la ruta"); }
        }


        //Logic to add Tourist Point. 
        if (!isColorSelected && isAddPointName) {
            color = graphic.colorPalette(window, event, isColorSelected);
            newPoint->setColor(color);
        }
        if (isCoordsSelected) {
            //Select coordenates.
            if (!newPoint->getCoordinatesAssigned()) {
                newPoint->setCoordinates(event, window);
            }
            else { //Enable to add another Tourist Point.
                secondTextBox.setString("Agregar Punto"); //Reset menu text.
                isPointAdded = true;
                newRoute->setTouristPoint(newPoint);
                
                //Reset everything again.
                isAddPointName = false;         
                isColorSelected = false;
                isCoordsSelected = false;
            }   
        }
        if (isPointAdded) {
            window.draw(addToListText);
            newRoute->showRoutePoints(window, graphic); //Trace the route.
        }

       
        //Show routesList information.
        if (routesList.getRoutesCollection()->getHead() != nullptr && routeListButton) {
            if (selectedRoute != nullptr) {
                selectedRoute->showRoutePoints(window, graphic);  
                isRouteSelected = true;
            }
            else {
                routesList.showRouteListMap(window, graphic);  
            }
        }
        

        //Button messages
        window.draw(firstTextBox);
        window.draw(secondTextBox);
        window.draw(exploreText);
       
        
       //Display all
        window.display(); 
    }
    return 0;
}