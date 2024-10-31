#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.h"
#include "TouristRoute.h"
#include "RoutesManager.h"
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
    GraphicsManager graphic;//Objeto para manejar la parte gráfica
    LinkedList<TouristRoute> routesList; // Lista de rutas

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ventana con imagen de fondo"); // Crear una ventana

    // cargar la fuente para dibujar el texto
    sf::Font font;
    if (!font.loadFromFile("C:/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Fonts/RobotoMono-Regular.ttf")) {
        std::cerr << "No se pudo cargar la fuente." << std::endl;
        return -1;
    }

    // Cargar el fondo desde un archivo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/background.png")) {
        std::cerr << "Error al cargar la imagen de fondo" << std::endl;
        return -1;
    }

 
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    bool drawRectangleFlag = false;
    bool showRoutes = false;
    sf::Color color1 = graphic.hexToColor("#f2f4f7"); // color del rectangulo
    sf::Color color2 = graphic.hexToColor("#8b8686"); // color del texto

    // Crear un objeto de texto para mostrar la entrada del teclado
    sf::Text text("", font, 14); // 14 = tamaño
    text.setPosition(80, 75); // coordenadas x,y
    text.setFillColor(color2);


    string savedText; // Nombre del nuevo objeto Ruta

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (graphic.buttonEvent(event, window, 67, 65, 235, 35, drawRectangleFlag)) {

                string current = graphic.inputText(event, font, savedText);
                text.setString(current + "_"); // Actualizar el texto mostrado
                 
                if (!savedText.empty()) {

                    TouristRoute* newRoute = new TouristRoute(savedText);
                   
                    routesList.addToEnd(newRoute);
                    routesList.DisplayInfo();

                    cout << "Ruta agregada: " << savedText << endl;

                    savedText.clear();
                }

            }

            if (graphic.buttonEvent(event, window, 58, 170, 50, 17, showRoutes));
        }

        window.clear(sf::Color::White);// Limpiar la ventana
        window.draw(backgroundSprite);// Dibujar el fondo
       
        if (drawRectangleFlag) {
            graphic.drawRectangle(window, color1, 80, 75, 180, 15);
            window.draw(text); // Dibujar el texto
        }

        if (showRoutes) {
            graphic.drawRectangle(window, color1, 11, 230, 270, 30);
            // Crear un objeto de texto para mostrar la entrada del teclado
            sf::Text text2("Aqui se ven y modifican las rutas", font, 14); // 14 = tamaño
            text2.setPosition(14, 235); // coordenadas x,y
            text2.setFillColor(color2);
            window.draw(text2); // Dibujar el texto
        }

        window.display(); // Mostrar lo que se ha dibujado
    }
    return 0;
}