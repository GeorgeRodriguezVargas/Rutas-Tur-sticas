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
                    inputText.pop_back(); // Eliminar el �ltimo car�cter
                }
            }
            else if (event.text.unicode == '\r') { // Manejo de Enter
                cout << "Texto ingresado: " << inputText << std::endl; // Imprimir en la consola
                inputText = " ";
            }
            else {
                inputText += static_cast<char>(event.text.unicode) ; // Agregar el nuevo car�cter
            }
        }
    }
    return inputText;
}


bool GraphicsManager::buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState) {

    sf::FloatRect button = sf::FloatRect(x, y, width, height); // Posici�n y tama�o 

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // bot�n izquierdo del mouse

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);// Obtener las coordenadas del clic

        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);// Convertir las coordenadas 

        if (button.contains(worldPos)) {// Verificar si el clic est� dentro del �rea del bot�n 
            buttonState = !buttonState;
            cout << " Click!" << endl;
            return buttonState;
        }
    }
    return buttonState;
}

void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height) {

    sf::RectangleShape region(sf::Vector2f(width, height));// Tama�o de la regi�n
    region.setPosition(x, y);// Posici�n de la regi�n
    region.setFillColor(color);// Color de la regi�n

    window.draw(region);// Dibujar la regi�n
}

sf::Color GraphicsManager::hexToColor(const std::string& hex) { //Convertir un color hex a RGB
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}