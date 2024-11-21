#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsManager.h"
#include <iostream>
using namespace std;

class GraphicsManager
{
private:
    //image resources
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    string backgroundPath = "/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Recursos/Background.png";
    sf::Texture alertTexture;
    sf::Sprite alertSprite;
    string alertPath = "/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Recursos/alert.png";
    sf::Texture resource3Texture;
    sf::Sprite resource3Sprite;
    string resource3Path = "/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Recursos/resource3.png";


    //Main font style
    sf::Font mainFont;
    string fontPath = "/Users/georg/OneDrive/Documentos/C++/Progra_I/project_II/Recursos/RobotoMono-Regular.ttf";

    //Colors 
    sf::Color red;
    sf::Color yellow;
    sf::Color green;
    sf::Color blue;
    sf::Color purple ;

public:
    GraphicsManager();

    bool loadResources();

    //Getters.
    sf::Sprite& getBackgroundSprite();
    sf::Sprite& getErrorAlert();
    sf::Sprite& getResource3();
    sf::Font& getMainFont();

    //Methods.
    string inputText(sf::Event event, string &savedText);

    bool buttonEvent(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState);

    bool mouseOver(sf::Event event, sf::RenderWindow& window, int x, int y, int width, int height, bool& buttonState);

    void drawRectangle(sf::RenderWindow& window, sf::Color color, int x, int y, int width, int height);

    void displayError(sf::RenderWindow& window, sf::Color color, string message);

    sf::Text bodyText(int size, string message, sf::Color color, int c, int y);

    sf::Color hexToColor(const std::string& hex);

    sf::Color colorPalette(sf::RenderWindow& window, sf::Event event, bool& buttonState);
};