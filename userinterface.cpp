//
// Created by Leahz on 10/27/202
#include "userinterface.h"
#include <SFML/Graphics.hpp>


/*-----------------PLAYING AROUND WITH MAIN WINDOW VISUALS----------------------

sf::RenderWindow window(sf::VideoMode({800, 600}), "TGUI Window");
    tgui::Gui gui(window);

    auto comboBox = tgui::ComboBox::create();
    comboBox->setPosition(100, 100);
    comboBox->setSize(200, 30);
    comboBox->addItem("Option 1");
    comboBox->addItem("Option 2");
    comboBox->setSelectedItem("Option 1");

    comboBox->onItemSelect([](const tgui::String& item) {
        std::cout << "Selected: " << item.toStdString() << std::endl;
    });

    gui.add(comboBox);

    while (window.isOpen()) {
        // 2. Fix the Event constructor error using SFML 3's type-safe event polling
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Forward the event to TGUI
            gui.handleEvent(*event);
        }

        window.clear();
        gui.draw();
        window.display();
    }
}
*/