//
// Created by Leahz on 10/27/202
#include "userinterface.h"
#include <SFML/Graphics.hpp>


/*-----------------PLAYING AROUND WITH MAIN WINDOW VISUALS----------------------

sf::RenderWindow window(sf::VideoMode({1500, 800}), "Game Dreamer");
sf::Texture background;
if (!background.loadFromFile("assets/background.jpg", false, sf::IntRect({0, 0}, {1500, 800}))) {
    cerr << "Could not load background texture\n";
    return -1;
};
sf::Sprite bgSprite(background);
bgSprite.setScale({2.1f,2.0f});

// program start
while (window.isOpen())
{
    while (const std::optional event = window.pollEvent())
    {
        // close if requested
        if (event->is<sf::Event::Closed>())
            window.close();
    }
    window.clear();
    window.draw(bgSprite);
    window.display();

}
*/