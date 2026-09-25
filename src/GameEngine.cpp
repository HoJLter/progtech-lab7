#include "GameEngine.h"


GameEngine::GameEngine(sf::Vector2u size):
window(sf::VideoMode(size), "Forest Game"),
map(window)
{

}

void GameEngine::handleEvents() {
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();

        map.handleEvent(*event);
    }
}


void GameEngine::render() {
    window.clear();
    
    map.render();

    window.display();
}

void GameEngine::run() {
    while (window.isOpen())
    {
        handleEvents();
        render();
    }
}