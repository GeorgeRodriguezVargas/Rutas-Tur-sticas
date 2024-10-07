#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"

#include <iostream>
using namespace std;

class GraphicsManager
{
private:
   
    sf::FloatRect botonInvisible = sf::FloatRect(67, 65, 235, 35); // Posición y tamaño 

public:

    void inputText(sf::Event event) {
        string name;
        static int index = 0; // Mantener el valor entre llamadas
        static char characterString[100] = { 0 }; 
        bool enterPressed = false;

       
        if (event.type == sf::Event::TextEntered && event.text.unicode < 128 && index < 99) {
            
            if (event.text.unicode == 8) { // Si se presiona borrar
                if (index > 0) {
                    index--; 
                    characterString[index] = '\0'; // Asegurarse de que la cadena se termine 
                }
            }
            else {
                characterString[index] = static_cast<char>(event.text.unicode);
                index++;
                characterString[index] = '\0'; // Terminar cadena
            }
        }

        // Verificar si se presiona Enter 
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
         
            for (int i = 0; i < index; i++) {
                name += characterString[i];
            }
            cout << "Nombre ingresado: " << name << endl;

            // Reiniciar variables para una nueva entrada
            index = 0;
            memset(characterString, 0, sizeof(characterString)); // Limpiar el array
        }
        
        

    }

    bool buttonEvent(sf::Event event, sf::RenderWindow& window) {
        // botón izquierdo del mouse
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            // Obtener las coordenadas del clic
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            // Convertir las coordenadas 
            sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

            // Verificar si el clic está dentro del área del botón 
            if (botonInvisible.contains(worldPos))
            {
                
                std::cout << " Click " << std::endl;

                return true;
            }
        }
        return false;
    }

    void drawRectangle(sf::RenderWindow& window, sf::Color color) {
  
        sf::RectangleShape region(sf::Vector2f(180, 15));  // Tamaño de la región
        region.setPosition(80, 75);                       // Posición de la región
        region.setFillColor(color);              // Color de la región

        // Dibujar la región
        window.draw(region);
    }

    sf::Color hexToColor(const std::string& hex) {
        int r = std::stoi(hex.substr(1, 2), nullptr, 16);
        int g = std::stoi(hex.substr(3, 2), nullptr, 16);
        int b = std::stoi(hex.substr(5, 2), nullptr, 16);
        return sf::Color(r, g, b);
    }

};