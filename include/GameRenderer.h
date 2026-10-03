#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"

#define TILE_SIZE 72.f
#define FULL_MAP_SIZE 11


class GameRenderer {
	sf::RenderWindow& window;
	sf::Font font;
	sf::RectangleShape borders;
	sf::Text winLabel;

public:
	GameRenderer(sf::RenderWindow& target);

	void render(
		const Field& field,
		const std::array<int, MAP_SIZE>& rowHints,
		const std::array<int, MAP_SIZE>& colHints
	);
	void renderTile(int row, int col, TileType tile);
	void renderLabel(int row, int col, int value);
	void renderWinLabel(bool isWin);
};