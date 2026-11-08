//
// Created by Leahz on 10/27/2026.
//

#ifndef DREAM_STEAM_A_TEAM_DSA_PROJECT_2__USERINTERFACE_H
#define DREAM_STEAM_A_TEAM_DSA_PROJECT_2__USERINTERFACE_H
#include <map>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

void loadMain();
tgui::TextArea::Ptr drawRecommendedGames(tgui::SFML_GRAPHICS::Gui& g, const std::vector<std::string>& gs);

class TextObject {
    std::string fontfile;
    sf::Color colorHexCode;
    std::string textContent;
    int textSize;
    sf::Vector2f position;

    public:
    TextObject(std::string f, sf::Color h, int s, sf::Vector2f p, std::string t) {
        fontfile = f;
        colorHexCode = h;
        textSize = s;
        position = p;
        textContent = t;
    }

    void drawText(sf::RenderWindow &window);

};

class DropMenu {
    sf::Vector2f size;
    sf::Vector2f position;
    std::string title;
    std::vector<tgui::String> options;

public:
    DropMenu(sf::Vector2f s, sf::Vector2f p, std::string t,
        std::vector<tgui::String> o) {
        size = s;
        position = p;
        title = t;
        options = o;
    }

  void drawDropMenu(tgui::SFML_GRAPHICS::Gui& g,  std::string& selectedItem, bool&selected);

};

#endif //DREAM_STEAM_A_TEAM_DSA_PROJECT_2__USERINTERFACE_H