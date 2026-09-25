#pragma once
#include "SFML/Graphics.hpp"
#include "Entities.h"


class Map {
	sf::RenderWindow& window;

	std::vector<std::vector<Entity>> grid;
	std::vector<int> rowCampCount;
	std::vector<int> colCampCount;

public:
	Map(sf::RenderWindow& window);

	void handleEvent(const sf::Event& event);
	void render();

private:
	
};