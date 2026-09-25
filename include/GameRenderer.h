#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"

class GameRenderer {
	sf::RenderWindow& window;
	const Field& field;

public:
	GameRenderer(sf::RenderWindow& target) : 
		window(target), 
		field(field) { }

	void render(const Field& field);
};