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
    GraphicsManager graphic;//Objeto para manejar la parte gráfica

    
    LinkedList<TouristRoute> routesList; // Lista de rutas

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ventana con imagen de fondo"); // Crear una ventana

    bool menuEvent = false;
    bool showRutes = false;
  
    sf::Color lightGrey = graphic.hexToColor("#f2f4f7"); // color del rectangulo
    sf::Color textColor = graphic.hexToColor("#8b8686"); // color del texto
    sf::Color blue = graphic.hexToColor("#5e17eb"); // color del texto
    sf::Color darkGrey = graphic.hexToColor("#646363"); // color del texto




    TouristPoint punto;
    punto.setColor(blue);
    punto.setName("Nombre");






    // Crear un objeto de texto para mostrar la entrada del teclado
    sf::Text text("", graphic.getMainFont(), 14); // 14 = tamaño
    text.setPosition(60, 50); // coordenadas x,y
    text.setFillColor(textColor);


    string savedText = ""; // Nombre del nuevo objeto Ruta

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (graphic.buttonEvent(event, window, 67, 65, 235, 35, menuEvent)) {

               
                string current = graphic.inputText(event, savedText);
                text.setString(current + "_"); // Actualizar el texto mostrado
                 
                if (!savedText.empty()) {

                    TouristRoute* newRoute = new TouristRoute(savedText);
                   
                   
                    routesList.addToEnd(newRoute);
                    routesList.DisplayInfo();
                
                    cout << "Ruta agregada: " << savedText << endl;

                    savedText.clear();
                }

            }
            if (graphic.buttonEvent(event, window, 67, 65, 50, 30, showRutes)) {
                showRutes = true;
                punto.setCoordinates(event, window);
               
            }


          
        }

        window.clear(sf::Color::White);// Limpiar la ventana
        window.draw(graphic.getBackgroundSprite());// Dibujar el fondo
       
       
        graphic.drawRectangle(window, darkGrey);
       

        if (menuEvent) {
            window.draw(text); // Dibujar el texto
        }
        if (showRutes) {
           
            punto.drawTouristPoint(window);
        }
     
        

        window.display(); // Mostrar lo que se ha dibujado
    }
    return 0;
}