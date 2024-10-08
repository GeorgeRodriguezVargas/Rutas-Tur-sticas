#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.h"


using namespace std;

int main() {
    GraphicsManager graphic;
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ventana con imagen de fondo");

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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            if (graphic.buttonEvent(event, window, 67, 65, 235, 35)) {
                drawRectangleFlag = true;
            }
            if (drawRectangleFlag) {
                text.setString(graphic.inputText(event, font) + "_"); // Actualizar el texto mostrado
            }

            if (graphic.buttonEvent(event, window, 58, 170, 50, 17)) {
               showRoutes = true;
            }

        }

     
        window.clear(sf::Color::White);   // Limpiar la ventana
        window.draw(backgroundSprite);
       
        if (drawRectangleFlag) {
            graphic.drawRectangle(window, color1);

        }

        window.draw(text ); // Dibujar el texto
        
        window.display(); // Mostrar lo que se ha dibujado
    }

    return 0;
}