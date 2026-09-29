#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"

class GameRenderer {
	sf::RenderWindow& window;
	sf::Font font;
	sf::RectangleShape borders;

public:
	GameRenderer(sf::RenderWindow& target);

	void render(
		const Field& field,
		const std::array<int, MAP_SIZE>& rowHints,
		const std::array<int, MAP_SIZE>& colHints
	);
	void renderTree(int row, int col);
	void renderTent(int row, int col);
	void renderNone(int row, int col);
	void renderLabel(int row, int col, int value);
};