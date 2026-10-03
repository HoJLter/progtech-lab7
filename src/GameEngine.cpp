#include "GameEngine.h"


GameEngine::GameEngine(sf::Vector2u size):
window(sf::VideoMode(size), 
    "Forest Game", 
    sf::Style::Titlebar | sf::Style::Close, 
    sf::State::Windowed),
    renderer(window),
    handler(window, logic)
{
    
}



void GameEngine::run() {
    while (window.isOpen())
    {
        handler.handleEvents();

        window.clear();
        renderer.render(
            logic.getField(), 
            logic.getRowHints(), 
            logic.getColHints()
        );
        window.display();
    }
}