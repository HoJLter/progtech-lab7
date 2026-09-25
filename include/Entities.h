#pragma once
#include <SFML/Graphics.hpp>
#define TILE_SIZE 64.f

class Entity {
protected:
    sf::CircleShape shape;
    sf::RectangleShape borders;
    sf::RenderWindow& window;

public:
    Entity(sf::RenderWindow& window, sf::CircleShape shape) :
        window(window),
        shape(shape)
    {
        borders.setSize({ TILE_SIZE, TILE_SIZE });
        borders.setFillColor(sf::Color::Transparent);
        borders.setOutlineColor(sf::Color::White);
        borders.setOutlineThickness(3.f);
    }

    virtual ~Entity() = default;

    void setPos(sf::Vector2f coords);
    void setScale(float scale);

    void render();
    virtual void handleEvent(const sf::Event& event) = 0;
};


class Tree : public Entity {
public:
    Tree(sf::RenderWindow& window);

    void handleEvent(const sf::Event& event) override {};
};


class Camping : public Entity {
public:
    Camping(sf::RenderWindow& window);

    void handleEvent(const sf::Event& event) override {};
};


class Nothing : public Entity {
public:
    Nothing(sf::RenderWindow& window);

    void handleEvent(const sf::Event& event) override;
};