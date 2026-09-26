#pragma once
#include "Field.h"


class GameLogic {
	Field field;
	std::array<int, MAP_SIZE> rowHints;
	std::array<int, MAP_SIZE> colHints;

public:
	GameLogic();

	const Field& getField() const {
		return field;
	}

private:
	void generateField();
	bool isTile(int row, int col, TileType type) const;
	bool isCanPlaceTent(int row, int col) const;

	int calcHintsForRow(int row);
	int calcHintsForCol(int col);
};

