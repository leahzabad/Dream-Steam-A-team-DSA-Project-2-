//
// Created by Leahz on 10/27/202
#include "userinterface.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "datasets.h"
#include <sstream>

std::vector<Game> games = loadCSV(string(DATA_DIR) + "all_applications.csv");

//parsing game information for drop down menus
std::vector<tgui::String> getAllGenres() {
    std::set<std::string> ugenres;
    std::vector<tgui::String> genres;
    for (auto & game : games) {
        std::stringstream ss(game.genres);
        std ::string genre;

        while (std::getline(ss, genre, ';')) {
            ugenres.insert(genre);
        }
    }

    for (const auto& genre : ugenres) {
        genres.push_back(genre);
    }

    std::sort(genres.begin(), genres.end());
    return genres;
}

std::vector<tgui::String> getAllCategories() {
    std::set<std::string> uctgs;
    std::vector<tgui::String> ctgs;
    for (auto & game : games) {
        std::stringstream ss(game.categories);
        std ::string category;

        while (std::getline(ss, category, ';')) {
            uctgs.insert(category);
        }
    }

    for (const auto& category : uctgs) {
        ctgs.push_back(category);
    }
    std::sort(ctgs.begin(), ctgs.end());
    return ctgs;
}

std::vector<tgui::String> dropDownGenres = getAllGenres();
std::vector<tgui::String> dropDownCategories = getAllCategories();


//drop menu creation
void DropMenu::drawDropMenu(tgui::SFML_GRAPHICS::Gui& g,  std::string& selectedItem, bool&selected) {

    auto Box = tgui::ComboBox::create();
    Box->setPosition(position.x, position.y);
    Box->setSize(size.x, size.y);
    Box->setDefaultText(title);
    Box->setTextSize(11);
    Box->addItem("--");

    for (int i = 0; i < options.size(); i++) {
        Box->addItem(options[i]);
    }

    Box->setItemsToDisplay(5);

    g.add(Box);

    Box->onItemSelect([Box, &selectedItem, &selected](const tgui::String& item) {
        if (item == "--") {
            Box->deselectItem();
            selectedItem = "";
        }
        else {
            selectedItem = item.toStdString();
        }
        selected = true;
    });
}

void TextObject::drawText(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.openFromFile(fontfile)) {
        std::cerr << "error loading main font" << std::endl;
    }

    sf::Text t(font, textContent);
    t.setFillColor(colorHexCode);
    t.setCharacterSize(textSize);
    t.setPosition(position);

    window.draw(t);
};

tgui::TextArea::Ptr drawRecommendedGames(tgui::SFML_GRAPHICS::Gui& g, const std::vector<std::string>& gs) {
    auto gameText = tgui::TextArea::create();
    gameText->setPosition({370.f,308.f});
    gameText->setSize({732,350});
    gameText->setReadOnly(true);
    gameText->setTextSize(20);


    tgui::String text;

    for (const auto& s: gs) {
        text += s + "\n";
    }

    gameText->setText(text);
    gameText->setVerticalScrollbarValue(0);

    g.add(gameText);
    return gameText;
}

void loadMain(){
    sf::RenderWindow window(sf::VideoMode({1500, 800}), "Game Dreamer");
        tgui::SFML_GRAPHICS::Gui g(window);

    //TEXT

    TextObject titleShadow("Milkyway DEMO.ttf", sf::Color((0xdfbaebFF)), 75, {450, 151},
        "DREAM OF A GAME");
    TextObject title("Milkyway DEMO.ttf", sf::Color((0x4a206fFF)), 75, {443, 153},
        "DREAM OF A GAME");


    //BACKGROUND
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/mainbg.png")) {
        std::cerr << "could not load background texture" << std::endl;
    }

    sf::Sprite background(backgroundTexture);
    background.setOrigin({0.f,0.f});
    background.setScale({0.79f,0.74f});

    sf::RectangleShape gamesBackground;
    gamesBackground.setPosition({370.f, 308.f});
    gamesBackground.setSize({732, 350});
    gamesBackground.setFillColor(sf::Color{255,255,255, 70});

    //DROP DOWN MENUS
    bool changedSelection = true;
        DropMenu genreBox({155.f, 30.f}, {465.f, 255.f}, "Genre", dropDownGenres);
        std::string selectedGenre;
        genreBox.drawDropMenu(g, selectedGenre, changedSelection);

        DropMenu categoryBox({155.f, 30.f}, {658.5f, 255.f}, "Category", dropDownCategories);
        std::string selectedCategory;
        categoryBox.drawDropMenu(g, selectedCategory, changedSelection);

        DropMenu platformBox({155.f, 30.f}, {853.5f, 255.f}, "Platform", {"linux", "mac", "windows"});
        std::string selectedPlatform;
        platformBox.drawDropMenu(g, selectedPlatform, changedSelection);

    //GAME RECOMMENDATIONS
        std::vector<std::string> recommendedGames;
        auto gameText =drawRecommendedGames(g, recommendedGames);

    //WINDOW LOOP
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }

                g.handleEvent(*event);
            }
            //updating game recommendations based on drop down selection
            if (changedSelection) {
                if (!selectedGenre.empty() || !selectedPlatform.empty() || !recommendedGames.empty()) {
                    auto updatedRecommendedGames =
                            loadMostSimilarGames(games, selectedGenre, selectedCategory, selectedPlatform);

                    tgui::String text;

                    for (const auto& s: updatedRecommendedGames) {
                        text += s + "\n";
                    }
                    gameText->setText(text);
                }
                else {
                    gameText->setText("");
                }
                changedSelection = false;
            }

            window.clear();
            window.draw(background);
            titleShadow.drawText(window);
            title.drawText(window);
            window.draw(gamesBackground);
            g.draw();
            window.display();
        }
}
