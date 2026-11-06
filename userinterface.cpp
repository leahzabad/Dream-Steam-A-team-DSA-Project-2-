//
// Created by Leahz on 10/27/202
#include "userinterface.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

void DropMenu::drawDropMenu(tgui::SFML_GRAPHICS::Gui& g) {
    auto Box = tgui::ComboBox::create();
    Box->setPosition(position.x, position.y);
    Box->setSize(size.x, size.y);
    Box->setDefaultText(title);
    Box->addItem("--");

    for (int i = 0; i < options.size(); i++) {
        Box->addItem(options[i]);
    }

    Box->setItemsToDisplay(5);

    g.add(Box);

    Box->onItemSelect([Box](const tgui::String& item) {
        if (item == "--") {
            Box->deselectItem();
        }
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
        DropMenu genreBox({155.f, 30.f}, {403.f, 255.f}, "Genre", {"Fantasy", "Horror",
        "Comedy", "RogueLike", "MMO", "play", "1"});
        genreBox.drawDropMenu(g);

        DropMenu categoryBox({155.f, 30.f}, {570.5f, 255.f}, "Category", {"1", "2","3","4","5","6","7"});
        categoryBox.drawDropMenu(g);

        DropMenu platformBox({155.f, 30.f}, {745.5f, 255.f}, "Platform", {"1", "2"});
        platformBox.drawDropMenu(g);

        DropMenu publisherBox({155.f,30.f}, {913.f,255.f}, "Publisher", {"1", "2"});
        publisherBox.drawDropMenu(g);

    //WINDOW LOOP
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }

                /*handling selection
                genreBox->onItemSelect([](const tgui::String& item) {
                    std::cout << "Selected: " << item.toStdString() << std::endl;
                }); */

                g.handleEvent(*event);
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

