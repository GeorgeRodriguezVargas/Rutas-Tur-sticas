#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.h"


using namespace std;

int main() {
    GraphicsManager graphic;
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ventana con imagen de fondo");

    // Crear un objeto de fuente para dibujar el texto
    sf::Font font;
    if (!font.loadFromFile("C:/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Fonts/Quicksand-VariableFont_wght.ttf")) {
        std::cerr << "No se pudo cargar la fuente." << std::endl;
        return -1;
    }

    // Cargar la textura desde un archivo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/background.png")) {
        std::cerr << "Error al cargar la imagen de fondo" << std::endl;
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    string name = "12345"; 
    bool drawRectangleFlag = false;
    sf::Color color = graphic.hexToColor("#f2f4f7"); // color hexadecimal


   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            if (graphic.buttonEvent(event, window)) {
                drawRectangleFlag = true;
            }
          
            graphic.inputText(event);
            
        }
       
        sf::Text text;
        text.setFont(font);              // Establecer la fuente
        text.setString(name);  // Establecer el texto que se va a mostrar
        text.setCharacterSize(30);       // Tamaño del texto
        text.setFillColor(sf::Color::Blue); // Color del texto
        text.setPosition(500, 150);      // Posición del texto en la ventana

       
        
        // Limpiar la ventana
        window.clear();

        // Dibujar la imagen de fondo
        window.draw(backgroundSprite);

        // Escribir el texto en la ventana
        window.draw(text);

        if (drawRectangleFlag) {
            graphic.drawRectangle(window, color);
        }
        

        // Mostrar los cambios
        window.display();
    }

   

    return 0;
}

