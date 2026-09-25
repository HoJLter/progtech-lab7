#pragma once
#include "SFML/Graphics.hpp"
#include "Entities.h"


class Map {
private:
	sf::RenderWindow& window;

	std::array<std::array<Entity*, 10>, 10> entities;

	Entity* generateRandomEntity();
	void generateMap();

public:
	Map(sf::RenderWindow& window);

	void handleEvent(const sf::Event& event);
	void render();
};