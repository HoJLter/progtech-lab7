#include "Entities.h"
#include <iostream>

Tree::Tree(sf::RenderWindow& window) :
    Entity(window, sf::CircleShape(TILE_SIZE/2, 16))
{
    shape.setFillColor(sf::Color::Green);
}


Camping::Camping(sf::RenderWindow& window) :
    Entity(window, sf::CircleShape(TILE_SIZE/2, 3))
{
    shape.setFillColor(sf::Color::Yellow);
}


Nothing::Nothing(sf::RenderWindow& window) :
    Entity(window, sf::CircleShape(TILE_SIZE/2, 0))
{
}

void Nothing::handleEvent(const sf::Event& event) {
    if (const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2f mousePos{
            static_cast<float>(mouse->position.x),
            static_cast<float>(mouse->position.y)
        };

        if (borders.getGlobalBounds().contains(mousePos))
        {
            std::cout << "WASSUP!";
        }

    }
}


void Entity::setPos(sf::Vector2f coords) {
    shape.setPosition(coords);
    borders.setPosition(coords);
}

void Entity::setScale(float scale) {
    shape.setScale({scale, scale});
    borders.setScale({ scale, scale });
}

void Entity::render() {
    window.draw(shape);
    window.draw(borders);
}