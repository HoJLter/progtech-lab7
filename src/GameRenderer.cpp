#include "GameRenderer.h"
#include <string>



GameRenderer::GameRenderer(sf::RenderWindow& target) :
	window(target),
	winLabel(font, "YOU WON", 144) {
	borders.setFillColor(sf::Color::Transparent);
	borders.setOutlineColor(sf::Color::White);
	borders.setOutlineThickness(3.f);
	borders.setSize({ TILE_SIZE, TILE_SIZE });
	
	if (!font.openFromFile("Tovar.otf")) {
		throw std::runtime_error("Fail while loading font");
	}

	winLabel.setFillColor(sf::Color(255, 215, 0));
	winLabel.setOutlineColor(sf::Color(40, 20, 80));
	winLabel.setOutlineThickness(3.f);

	const auto bounds = winLabel.getLocalBounds();
	winLabel.setOrigin({
		bounds.position.x + bounds.size.x / 2.f,
		bounds.position.y + bounds.size.y / 2.f
		});

	winLabel.setPosition({
		window.getSize().x / 2.f,
		window.getSize().y / 2.f
		});
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
					renderTile(row+1, col+1, TileType::Tree);
					break;
				}
				case(TileType::Tent): {
					renderTile(row + 1, col + 1, TileType::Tent);
					break;
				}
				case(TileType::TentUnrevealed): {
					renderTile(row + 1, col + 1, TileType::Tent);
					break;
				}
				case(TileType::None): {
					renderTile(row + 1, col + 1, TileType::None);
					break;
				}
			}
		}
	}
}

void GameRenderer::renderTile(int row, int col, TileType tile)
{
	borders.setPosition({ col * TILE_SIZE, row * TILE_SIZE });

	switch (tile)
	{
	case TileType::Tree:
	{
		sf::CircleShape shape(TILE_SIZE / 2.f, 16);
		shape.setPosition({ col * TILE_SIZE, row * TILE_SIZE });
		shape.setFillColor(sf::Color::Green);
		window.draw(shape);
		break;
	}

	case TileType::Tent:
	case TileType::TentUnrevealed:
	{
		sf::CircleShape shape(TILE_SIZE / 2.f, 3);
		shape.setPosition({ col * TILE_SIZE, row * TILE_SIZE });
		shape.setFillColor(sf::Color::Yellow);
		window.draw(shape);
		break;
	}

	case TileType::None:
		break;
	}

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

void GameRenderer::renderWinLabel(bool isWin) {
	if (isWin) {
		window.draw(winLabel);
	}
}