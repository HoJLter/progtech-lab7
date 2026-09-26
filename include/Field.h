#pragma once
#include <array>
#include <stdexcept>
#define MAP_SIZE 10


enum class TileType {
	Tree,
	Tent,
	TentUnrevealed,
	None
};

class Field {
private:
	std::array<std::array<TileType, MAP_SIZE>, MAP_SIZE> tiles;
	std::array<int, MAP_SIZE> rowHints;
	std::array<int, MAP_SIZE> colHints;

public:
	void setTile(int row, int col, TileType tile) {
		if (row >= 0 && col >= 0 &&
			row < MAP_SIZE && col < MAP_SIZE) {
			tiles[row][col] = tile;
		}
		else {
			throw std::runtime_error("getTile() failed!");
		}
	};

	TileType getTile(int row, int col) const {
		if (row >= 0 && col >= 0 &&
			row < MAP_SIZE && col < MAP_SIZE) {
			return tiles[row][col];
		}
		else {
			throw std::runtime_error("getTile() failed!");
		}
	};

};

