#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

class GraphicsManager
{
private:
    sf::Texture routeTexture;
    sf::Sprite routeSprite;
    string routePath = "C://Users//georg//OneDrive//Documentos//C++//Progra_I//project_II//barra.png";

public:
    GraphicsManager();

    bool loadImages();

    string inputText(sf::Event event, sf::Font& font, string &savedText);

    bool buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState);

    void drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height);

    sf::Color hexToColor(const std::string& hex);

};