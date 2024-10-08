#include "GraphicsManager.h"
using namespace std;
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
#include <iostream>

string GraphicsManager::inputText(sf::Event event, sf::Font& font) {
   
    static string inputText;
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) { // Solo caracteres ASCII
            if (event.text.unicode == '\b') { // Manejo de backspace
                if (!inputText.empty()) {
                    inputText.pop_back(); // Eliminar el último carácter
                }
            }
            else if (event.text.unicode == '\r') { // Manejo de Enter
                cout << "Texto ingresado: " << inputText << std::endl; // Imprimir en la consola
                inputText = " ";
            }
            else {
                inputText += static_cast<char>(event.text.unicode) ; // Agregar el nuevo carácter
               
            }
           
        }
    }
    return inputText;
}


bool GraphicsManager::buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height) {
    sf::FloatRect button = sf::FloatRect(x, y, width, height); // Posición y tamaño 

    // botón izquierdo del mouse
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        // Obtener las coordenadas del clic
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // Convertir las coordenadas 
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

        // Verificar si el clic está dentro del área del botón 
        if (button.contains(worldPos)) {
            cout << " Click!" << endl;
            return true;
        }
    }
    
    return false;
}

void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color) {

    sf::RectangleShape region(sf::Vector2f(180, 15));  // Tamaño de la región
    region.setPosition(80, 75);                       // Posición de la región
    region.setFillColor(color);              // Color de la región

    // Dibujar la región
    window.draw(region);
}

sf::Color GraphicsManager::hexToColor(const std::string& hex) { //Convertir un color hex a RGB
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}