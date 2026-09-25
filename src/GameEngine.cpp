#include "GameEngine.h"


GameEngine::GameEngine(sf::Vector2u size):
window(sf::VideoMode(size), 
    "Forest Game", 
    sf::Style::Titlebar | sf::Style::Close, 
    sf::State::Windowed),
    renderer(window, logic.getField())
{

}

void GameEngine::handleEvents() {
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}



void GameEngine::run() {
    while (window.isOpen())
    {
        handleEvents();

        window.clear();
        renderer.render();
        window.display();
    }
}