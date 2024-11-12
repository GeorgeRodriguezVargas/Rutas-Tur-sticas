#include "GraphicsManager.h"
#include "LinkedList.h"

GraphicsManager::GraphicsManager() {

    if (!loadResources()) {
        cout << "Error al cargar las texturas\n";
    }
    else {
        backgroundSprite.setTexture(backgroundTexture);
        alertSprite.setTexture(alertTexture);

        red = hexToColor("#ff6347");
        yellow = hexToColor("#ffde59");
        green = hexToColor("#7ed957");
        blue = hexToColor("#5271ff");
        purple = hexToColor("#cb6ce6");
    }
}

bool GraphicsManager::loadResources() {
    if (!backgroundTexture.loadFromFile(backgroundPath) || !mainFont.loadFromFile(fontPath) ||
        !alertTexture.loadFromFile(alertPath)) {
        return false;
    }
    return true;    
}

//Get Graphic Resources
sf::Sprite& GraphicsManager::getBackgroundSprite() { return backgroundSprite; }
sf::Sprite& GraphicsManager::getErrorAlert() { return alertSprite; }
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

bool GraphicsManager::mouseOver(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState) {
    sf::FloatRect button = sf::FloatRect(x, y, width, height); // Posici�n y tama�o 

    if (event.type == sf::Event::MouseMoved) { // bot�n izquierdo del mouse

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);// Obtener las coordenadas del clic

        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);// Convertir las coordenadas 

        if (button.contains(worldPos)) {// Verificar si el clic est� dentro del �rea del bot�n 
            return true;
        }
    }
    return false;
}

void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height) {

    sf::RectangleShape region(sf::Vector2f(width, height));// Tama�o de la regi�n
    region.setPosition(x, y);// Posici�n de la regi�n
    region.setFillColor(color);// Color de la regi�n
    
    window.draw(region);// Dibujar la regi�n
}

void GraphicsManager::drawTriangle(sf::RenderWindow& window, sf::Color color) {

    
    sf::CircleShape triangle(5, 3);  

    triangle.setPosition(110, 151);  

    triangle.setRotation(180);

    triangle.setFillColor(color);

    window.draw(triangle);// Dibujar la regi�n
}

void GraphicsManager::displayError(sf::RenderWindow& window,sf::Color color, string message) {
  
    alertSprite.setPosition(435, 275);
    sf::Text text = bodyText(12, message, color, 519, 317);

    window.draw(alertSprite);
    window.draw(text);
}

sf::Text GraphicsManager::bodyText(int size, string message, sf::Color color, int x, int y) {
    // Crear un objeto de texto para mostrar la entrada del teclado
    sf::Text text(message, mainFont, size); // 14 = tama�o
    text.setPosition(x, y); // coordenadas x,y
    text.setFillColor(color);
    return text;
}

sf::Color GraphicsManager::hexToColor(const std::string& hex) { //Convertir un color hex a RGB
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}

sf::Color GraphicsManager::colorPalette(sf::RenderWindow& window, sf::Event event, bool& buttonState) {

    int x = 369;
    int width = 16;
    int height = 16;
    
    
    if (buttonEvent(event, window, x, 53, width, height, buttonState)) {
        return red;
    }
    else if (buttonEvent(event, window, x, 72, width, height, buttonState)) {
        return yellow;
    }
    else if (buttonEvent(event, window, x, 91, width, height, buttonState)) {
        return green;
    }
    else if (buttonEvent(event, window, x, 110, width, height, buttonState)) {
        return blue;
    }
    else if(buttonEvent(event, window, x, 129, width, height, buttonState)){
        return purple;
    }

    return sf::Color::Transparent;
}

