#include "GraphicsManager.h"
#include "LinkedList.h"

GraphicsManager::GraphicsManager() {

    if (!loadResources()) {
        cout << "Error al cargar las texturas\n";
    }
    else {
        backgroundSprite.setTexture(backgroundTexture);

    }
}

bool GraphicsManager::loadResources() {
    if (!backgroundTexture.loadFromFile(backgroundPath) || !mainFont.loadFromFile(fontPath)) {
        return false;
    }
    return true;    
}

//Get Graphic Resources
sf::Sprite& GraphicsManager::getBackgroundSprite() { return backgroundSprite; }
sf::Font& GraphicsManager::getMainFont() { return mainFont; }

string GraphicsManager::inputText(sf::Event event, string &savedText) {
   
    static string inputText;

    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) { // Solo caracteres ASCII
            if (event.text.unicode == '\b') { // Manejo de backspace
                if (!inputText.empty()) {
                    inputText.pop_back(); // Eliminar el último carácter
                }
            }
            else if (event.text.unicode == '\r') { // Manejo de Enter
                savedText = inputText;
                cout << "Texto ingresado: " << savedText << endl; // Imprimir en la consola
                inputText = "";
            }
            else {
                inputText += static_cast<char>(event.text.unicode) ; // Agregar el nuevo carácter
            }
        }
    }
    return inputText;
}


bool GraphicsManager::buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState) {

    sf::FloatRect button = sf::FloatRect(x, y, width, height); // Posición y tamaño 

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // botón izquierdo del mouse

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);// Obtener las coordenadas del clic

        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);// Convertir las coordenadas 

        if (button.contains(worldPos)) {// Verificar si el clic está dentro del área del botón 
            buttonState = !buttonState;
            cout << " Click!" << endl;
            return buttonState;
        }
    }
    return buttonState;
}

void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height) {

    sf::RectangleShape region(sf::Vector2f(width, height));// Tamaño de la región
    region.setPosition(x, y);// Posición de la región
    region.setFillColor(color);// Color de la región
    
    window.draw(region);// Dibujar la región
}

void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color) {

    
    sf::CircleShape triangle(5, 3);  

    triangle.setPosition(110, 151);  

    triangle.setRotation(180);

    triangle.setFillColor(color);

    window.draw(triangle);// Dibujar la región
}

sf::Color GraphicsManager::hexToColor(const std::string& hex) { //Convertir un color hex a RGB
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

