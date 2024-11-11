#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

class GraphicsManager
{
private:
    //Background image resource
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    string backgroundPath = "/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Recursos/Background.png";
   
    //Main font style
    sf::Font mainFont;
    string fontPath = "/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Recursos/RobotoMono-Regular.ttf";

    //Colors 
    sf::Color textColor;
    sf::Color lightGray;
    sf::Color Blue;

    string textColorHex = "#8b8686";
    string lightGrayHex = "#f2f4f7";
    string BlueHex = "#5e17eb";

public:
    GraphicsManager();

    bool loadResources();

    sf::Sprite& getBackgroundSprite();
    sf::Font& getMainFont();

    string inputText(sf::Event event, string &savedText);

    bool buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState);

    void drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height);

    void drawRectangle(sf::RenderWindow& window, sf::Color color);

    sf::Color hexToColor(const std::string& hex);
};