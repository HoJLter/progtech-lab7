#pragma once
#include <array>
#include <iostream>
#include <iomanip>


enum class tileType {
	Tree,
	Tent,
	TentUnrevealed,
	None
};

class Field {
private:
	std::array<std::array<tileType, 10>, 10> tiles;
	std::array<int, 10> rowHints;
	std::array<int, 10> colHints;

public:
	void setTile(int i, int j, tileType tile) {
		tiles[i][j] = tile;
	};

	tileType getTile(int row, int col) const {
		if ((0 <= row < 10) && (0 <= col <= 10)) {
			return tiles[row][col];
		}
	};

};

