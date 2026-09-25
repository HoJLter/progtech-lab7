#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"

class GameRenderer {
	sf::RenderWindow& window;

public:
	GameRenderer(sf::RenderWindow& target) : 
		window(target) { }

	void render(const Field& field);
};