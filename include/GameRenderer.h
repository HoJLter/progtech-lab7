#pragma once
#include <SFML/Graphics.hpp>
#include "GameLogic.h"

class GameRenderer {
	sf::RenderWindow& window;
	const Field& field;

public:
	GameRenderer(sf::RenderWindow& target, const Field& field) : 
		window(target), 
		field(field) { }

	void render();
};