#pragma once
#include "SFML/Graphics.hpp"

class Entity {
protected:
	sf::RenderWindow& window;
public:
	Entity(sf::RenderWindow& window) : window(window) {};

	virtual void render();
	virtual void handleEvent(const sf::Event& event);
};

class Tree : Entity {
	sf::CircleShape shape;
	Tree(sf::RenderWindow& window);

	void render();
	void handleEvent(const sf::Event& event);
};

class Camping : Entity {
	sf::CircleShape shape;
	Camping(sf::RenderWindow& window);

	void render();
	void handleEvent(const sf::Event& event);
};