#include "GraphicsManager.h"
#include "LinkedList.h"

GraphicsManager::GraphicsManager() {

    if (!loadResources()) {
        cout << "Error al cargar las texturas\n";
    }
    else {
        backgroundSprite.setTexture(backgroundTexture);
        alertSprite.setTexture(alertTexture);
        resource3Sprite.setTexture(resource3Texture);

        red = hexToColor("#ff6347");
        yellow = hexToColor("#ffde59");
        green = hexToColor("#7ed957");
        blue = hexToColor("#5271ff");
        purple = hexToColor("#cb6ce6");
    }
}


bool GraphicsManager::loadResources() {
    if (!backgroundTexture.loadFromFile(backgroundPath) || !mainFont.loadFromFile(fontPath) ||
        !alertTexture.loadFromFile(alertPath) || !resource3Texture.loadFromFile(resource3Path)) {
        return false;
    }
    return true;    
}


//Get Graphic Resources
sf::Sprite& GraphicsManager::getBackgroundSprite() { return backgroundSprite; }
sf::Sprite& GraphicsManager::getErrorAlert() { return alertSprite; }
sf::Sprite& GraphicsManager::getResource3() { return resource3Sprite; }
sf::Font& GraphicsManager::getMainFont() { return mainFont; }


//Handle text box.
string GraphicsManager::inputText(sf::Event event, string &savedText) {
    static string inputText;
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) { 
            if (event.text.unicode == '\b') { //Backspace.
                if (!inputText.empty()) {
                    inputText.pop_back(); //Delete last character.
                }
            }
            else if (event.text.unicode == '\r') { //Enter.
                savedText = inputText;
                cout << "Texto ingresado: " << savedText << endl;
                inputText = "";
            }
            else {
                inputText += static_cast<char>(event.text.unicode);
            }
        }
    }
    return inputText;
}


//Handle events (button clicked).
bool GraphicsManager::buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState) {
    sf::FloatRect button = sf::FloatRect(x, y, width, height); //Position and size. 

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { 

        sf::Vector2i mousePos = sf::Mouse::getPosition(window); //Click coords.
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //Convert coordinates.

        if (button.contains(worldPos)) { //Check if the click is within the button area
            buttonState = !buttonState;
            return buttonState;
        }
    }
    return buttonState;
}


//Handle event (Mouse Over text).
bool GraphicsManager::mouseOver(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState) {
    sf::FloatRect button = sf::FloatRect(x, y, width, height); //Position and size. 

    if (event.type == sf::Event::MouseMoved) { 

        sf::Vector2i mousePos = sf::Mouse::getPosition(window); //Click coords.
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); //Convert coordinates.

        if (button.contains(worldPos)) { //Check if the click is within the button area
            return true;
        }
    }
    return false;
}


void GraphicsManager::drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height) {

    sf::RectangleShape region(sf::Vector2f(width, height));// Tamaño de la región
    region.setPosition(x, y);// Posición de la región
    region.setFillColor(color);// Color de la región
    
    window.draw(region);// Dibujar la región
}


void GraphicsManager::displayError(sf::RenderWindow& window,sf::Color color, string message) {
    alertSprite.setPosition(435, 275);
    sf::Text text = bodyText(12, message, color, 519, 317);
    window.draw(alertSprite);
    window.draw(text);
}


sf::Text GraphicsManager::bodyText(int size, string message, sf::Color color, int x, int y) {
    sf::Text text(message, mainFont, size); 
    text.setPosition(x, y); 
    text.setFillColor(color);
    return text;
}


//Convert a hexadecimal code to rgb color.
sf::Color GraphicsManager::hexToColor(const std::string& hex) { 
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);
    return sf::Color(r, g, b);
}


sf::Color GraphicsManager::colorPalette(sf::RenderWindow& window, sf::Event event, bool& buttonState) {
    int x = 350;
    int size = 16; //Is a square.
    
    //Draw the squares of the palette.
    drawRectangle(window, red, x, 37, size, size);
    drawRectangle(window, yellow, x, 56, size, size);
    drawRectangle(window, green, x, 75, size, size);
    drawRectangle(window, blue, x, 94, size, size);
    drawRectangle(window, purple, x, 113, size, size);
    
    //Select color with coordenates.
    if (buttonEvent(event, window, x, 37, size, size, buttonState)) {
        return red;
    }
    else if (buttonEvent(event, window, x, 56, size, size, buttonState)) {
        return yellow;
    }
    else if (buttonEvent(event, window, x, 75, size, size, buttonState)) {
        return green;
    }
    else if (buttonEvent(event, window, x, 94, size, size, buttonState)) {
        return blue;
    }
    else if(buttonEvent(event, window, x, 113, size, size, buttonState)){
        return purple;
    }
    return sf::Color::Transparent;
}