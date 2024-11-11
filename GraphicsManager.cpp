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
                    inputText.pop_back(); // Eliminar el �ltimo car�cter
                }
            }
            else if (event.text.unicode == '\r') { // Manejo de Enter
                savedText = inputText;
                cout << "Texto ingresado: " << savedText << endl; // Imprimir en la consola
                inputText = "";
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

void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color) {

    
    sf::CircleShape triangle(5, 3);  

    triangle.setPosition(110, 151);  

    triangle.setRotation(180);

    triangle.setFillColor(color);

    window.draw(triangle);// Dibujar la regi�n
}

sf::Color GraphicsManager::hexToColor(const std::string& hex) { //Convertir un color hex a RGB
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

