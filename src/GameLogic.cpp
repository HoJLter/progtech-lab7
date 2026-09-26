#include "GameLogic.h"
#include <vector>
#include <random>
#include "Utils.h"

GameLogic::GameLogic() {
	srand(time(NULL));
	generateField();
	Utils::print(field);
	
	for (int i = 0; i < MAP_SIZE; i++) {
		rowHints[i] = calcHintsForRow(i);
		colHints[i] = calcHintsForCol(i);
	}
}

bool GameLogic::isTile(int r, int c, TileType type) const {
	if (r < 0 || r >= MAP_SIZE ||
		c < 0 || c >= MAP_SIZE) {
		return false;
	}
	return this->field.getTile(r, c) == type;
}


bool GameLogic::isCanPlaceTent(int row, int col) const {


	if (!isTile(row, col, TileType::None)) return false;

	std::vector<std::pair<int, int>> directions = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1 },         {0, 1 },
		{1, -1 }, {1, 0 }, {1, 1}
	};
	for (auto dir : directions) {
		if (isTile(row + dir.first, col + dir.second, TileType::Tent)) {
			return false;
		}
	}
	return true;
}

void GameLogic::generateField() {
	field.clearField();
	std::vector<std::pair<int, int>> directions = {
		   	{-1, 0},
		{0, -1}, {0, 1},
			 {1, 0}
	};

	int chance;
	for (int row = 0; row < MAP_SIZE; row++) {
		for (int col = 0; col < MAP_SIZE; col++) {
			chance = rand() % 100;
			if (chance <= 33) {
				std::vector<std::pair<int, int>> available;
				for (auto dir : directions) {
					if (isCanPlaceTent(row + dir.first, col + dir.second)) {
						available.push_back(dir);
					}
				}
				if (available.empty()) {
					continue;
				}
				else {
					int index = rand() % available.size();
					field.setTile(row, col, TileType::Tree);
					field.setTile(
						row + available[index].first,
						col + available[index].second,
						TileType::Tent);
				}
			}
		}
	}
}

int GameLogic::calcHintsForRow(int row) {
	int sum = 0;
	for (int i = 0; i < MAP_SIZE; i++) {
		if (isTile(row, i, TileType::TentUnrevealed) ||
			isTile(row, i, TileType::Tent)) {
			sum++;
		}
	}
	return sum;
}

int GameLogic::calcHintsForCol(int col) {
	int sum = 0;
	for (int i = 0; i < MAP_SIZE; i++) {
		if (isTile(i, col, TileType::TentUnrevealed) ||
			isTile(i, col, TileType::Tent)) {
			sum++;
		}
	}
	return sum;
}