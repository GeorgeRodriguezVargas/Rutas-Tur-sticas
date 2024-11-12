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

    GraphicsManager graphic; //Objeto para manejar la parte gráfica
    LinkedList<TouristRoute> routesList; //Lista de rutas

    //Colors 
    sf::Color lightGray = graphic.hexToColor("#d8d8ce");
    sf::Color darkGray = graphic.hexToColor("#747474");
    sf::Color blue = graphic.hexToColor("#5e17eb"); 
   

    //Flags to handle event
    bool isAddRouteClicked = false;
    bool isAddPointClicked = false;

    bool isAddedRoute = false;
    bool isAddedPoint = false;

    bool mouseOverRoute = false;
    bool mouseOverPoint = false;
    bool errorAlert = false;

    bool isColorSelected = false;


    int x = 369;
    int width = 16;
    int height = 16;
    sf::Color color;


  
    TouristPoint punto;
    punto.setColor(blue);
    punto.setName("Nombre");

    //Text elements
    sf::Text insertRoute = graphic.bodyText(20, "Agregar Ruta", lightGray, 71, 40);
    sf::Text insertPoint = graphic.bodyText(20, "Agregar Punto", lightGray, 71, 96);


    string savedText = ""; // Nombre del nuevo objeto Ruta

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            //Close window event
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //Cambia el color del texto en el menú
            if (graphic.mouseOver(event, window, 61, 33, 282, 43, mouseOverRoute) && !isAddRouteClicked) {
                insertRoute.setFillColor(blue);
            }
            else {insertRoute.setFillColor(lightGray); }

            if (graphic.mouseOver(event, window, 61, 89, 282, 43, mouseOverPoint) && !isAddPointClicked) {
                insertPoint.setFillColor(blue);
            }
            else { insertPoint.setFillColor(lightGray); }

            //Cuadro de texto para añadir nombre de ruta
            if (graphic.buttonEvent(event, window, 61, 33, 282, 43, isAddRouteClicked) && !isAddedRoute) {
                insertRoute.setString("");

                string current = graphic.inputText(event, savedText);
                insertRoute.setString(current + "_"); // Actualizar el texto mostrado
                 
                if (!savedText.empty()) {
                    TouristRoute* newRoute = new TouristRoute(savedText);
                    routesList.addToEnd(newRoute);
                    routesList.DisplayInfo();
                    cout << "Ruta agregada: " << savedText << endl;
                   //savedText.clear();
                    insertRoute.setString(savedText);
                    savedText.clear();
                    isAddedRoute = true;
                }
            }

            //Cuadro de texto para añadir nombre de punto
            if (graphic.buttonEvent(event, window, 61, 89, 282, 43, isAddPointClicked)) {

                if (isAddedRoute) {
                    insertPoint.setString("");

                    string current = graphic.inputText(event, savedText);
                    insertPoint.setString(current + "_"); // Actualizar el texto mostrado

                    if (!savedText.empty()) {
                        cout << "Punto agregado: " << savedText << endl;
                        savedText.clear();
                        insertPoint.setString("Agregar Punto");
                        isAddPointClicked = false;
                        isAddedPoint = true;
                    }
                }
                else { errorAlert = true; }
            }

            if (!isColorSelected && isAddedPoint) {
              color = graphic.colorPalette(window, event, isColorSelected);
                
            }
               

              
              
              
              

          
        }
        window.clear(sf::Color::White);// Limpiar la ventana
        window.draw(graphic.getBackgroundSprite());// Dibujar el fondo
       
        window.draw(insertRoute);
        window.draw(insertPoint);
       
        
        if (errorAlert) {
            bool isOkClicked = false;
            if (graphic.buttonEvent(event, window, 754, 306, 57, 21, isOkClicked)) {
                errorAlert = false;
                isAddPointClicked = false;
            }
            else { graphic.displayError(window, lightGray, "Ingrese el nombre de la ruta"); }
        }

        if (!isColorSelected && isAddedPoint) {
            graphic.drawRectangle(window, blue, x, 53, width, height);
            graphic.drawRectangle(window, blue, x, 72, width, height);
            graphic.drawRectangle(window, blue, x, 91, width, height);
            graphic.drawRectangle(window, blue, x, 110, width, height);
            graphic.drawRectangle(window, blue, x, 129, width, height);
           
            
        }
        
        if (isColorSelected) {
            graphic.drawRectangle(window, color, x, 129, width, height);
        }







        window.display(); // Mostrar lo que se ha dibujado
    }
    return 0;
}