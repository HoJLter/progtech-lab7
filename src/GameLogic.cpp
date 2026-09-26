#include "GameLogic.h"
#include <vector>


bool GameLogic::isCanPlaceTent(int row, int col) {
	auto isTent = [this](int r, int c) {
		if (r < 0 || r > MAP_SIZE ||
			c < 0 || c > MAP_SIZE) {
			return this->field.getTile(r, c) == TileType::Tent;
		}
		return false;
	};

	if (isTent(row, col)) return false;

	std::vector<std::pair<int, int>> directions = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1 },          {0, 1 },
		{1, -1 }, {1, 0 }, {1, 1 }
	};
	bool flag = true;
	for (auto dir : directions) {
		if (isTent(row + dir.first, col + dir.second)) {
			flag = false;
			break;
		}
	}
	return flag;
}