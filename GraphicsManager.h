#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

class GraphicsManager
{
public:

    string inputText(sf::Event event, sf::Font& font);

    bool buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height);

    void drawRectangle(sf::RenderWindow& window, sf::Color color);

    sf::Color hexToColor(const std::string& hex);
};