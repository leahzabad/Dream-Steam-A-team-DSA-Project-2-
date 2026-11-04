//
// Created by Leahz on 10/27/2026.
//

#ifndef DREAM_STEAM_A_TEAM_DSA_PROJECT_2__USERINTERFACE_H
#define DREAM_STEAM_A_TEAM_DSA_PROJECT_2__USERINTERFACE_H
#include <map>
#include <SFML/Graphics.hpp>


class Screen {
public:
    void drawMainWindow(sf::RenderWindow &window);
};

class GameBio {
    sf::Sprite coverImage;
    sf::Text bioText;
    sf::Text titleText;
    sf::RectangleShape background;

    public:
        void draw(sf::RenderWindow &window);
};

class AssetManager {
    std::map<std::string, sf::Texture> textures;
    public:
        void loadTexture(std::string name, sf::Texture &texture);
        void getTexture(std::string name);
};

class Button {
    sf::RectangleShape shape;
    sf::Text text;
    sf::Texture buttonTexture;

    public:
        void drawButton(sf::RenderWindow &window);
        bool isClicked(sf::Vector2i mousePos);
};


#endif //DREAM_STEAM_A_TEAM_DSA_PROJECT_2__USERINTERFACE_H