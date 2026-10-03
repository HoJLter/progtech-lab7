#include "GameRenderer.h"
#include <string>



GameRenderer::GameRenderer(sf::RenderWindow& target) :
	window(target) {
	borders.setFillColor(sf::Color::Transparent);
	borders.setOutlineColor(sf::Color::White);
	borders.setOutlineThickness(3.f);
	borders.setSize({ TILE_SIZE, TILE_SIZE });
	
	if (!font.openFromFile("Tovar.otf")) {
		throw std::runtime_error("Fail while loading font");
	}
}


void GameRenderer::render(
	const Field& field, 
	const std::array<int, MAP_SIZE>& rowHints,
	const std::array<int, MAP_SIZE>& colHints
) {
	for (int row = -1; row < MAP_SIZE; row++) {
		for (int col = -1; col < MAP_SIZE; col++) {
			if (col == -1 && row == -1) {
				continue;
			}
			if (row == -1) {
				renderLabel(row+1, col+1, colHints[col]);
				continue;
			}
			if (col == -1 && row != -1) {
				renderLabel(row+1, col+1, rowHints[row]);
				continue;
			}

			TileType tile = field.getTile(row, col);


			switch (tile) {
				case(TileType::Tree): {
					renderTree(row+1, col+1);
					break;
				}
				case(TileType::Tent): {
					renderTent(row + 1, col + 1);
					break;
				}
				case(TileType::TentUnrevealed): {
					renderTent(row + 1, col + 1);
					break;
				}
				case(TileType::None): {
					renderNone(row + 1, col + 1);
					break;
				}
			}
		}
	}
}

void GameRenderer::renderTree(int row, int col) {\
	borders.setPosition({ col * TILE_SIZE, row * TILE_SIZE });
	sf::CircleShape treeShape(TILE_SIZE/2, 16);
	treeShape.setPosition({col*TILE_SIZE, row*TILE_SIZE});
	treeShape.setFillColor(sf::Color::Green);
	window.draw(treeShape);
	window.draw(borders);
}

void GameRenderer::renderTent(int row, int col) {
	borders.setPosition({ col * TILE_SIZE, row * TILE_SIZE });
	sf::CircleShape tentShape(TILE_SIZE / 2, 3);
	tentShape.setPosition({ col * TILE_SIZE, row * TILE_SIZE });
	tentShape.setFillColor(sf::Color::Yellow);
	window.draw(tentShape);
	window.draw(borders);
}

void GameRenderer::renderNone(int row, int col) {
	borders.setPosition({ col * TILE_SIZE, row * TILE_SIZE });
	window.draw(borders);
}

void GameRenderer::renderLabel(int row, int col, int value) {
	borders.setPosition({col * TILE_SIZE, row * TILE_SIZE});

	sf::Text label(font, std::to_string(value), 64);
	sf::FloatRect bounds = label.getLocalBounds();
	label.setOrigin({
	   bounds.position.x + bounds.size.x / 2.f,
	   bounds.position.y + bounds.size.y / 2.f
	});

	label.setPosition({
		col * TILE_SIZE + TILE_SIZE / 2.f,
		row * TILE_SIZE + TILE_SIZE / 2.f
		});
	label.setFillColor(sf::Color::White);
	window.draw(label);
	window.draw(borders);
}