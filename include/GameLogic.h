#pragma once
#include "Field.h"


class GameLogic {
	Field field;
	std::array<int, MAP_SIZE> rowHints;
	std::array<int, MAP_SIZE> colHints;

	int unrevealedTentsCount;

public:
	GameLogic();

	const Field& getField() const {
		return field;
	}

	const std::array<int, MAP_SIZE>& getRowHints() const {
		return rowHints;
	}

	const std::array<int, MAP_SIZE>& getColHints() const {
		return colHints;
	}

	void tentReveal(int row, int col);
	bool isWinCondition() {
		return unrevealedTentsCount == 0;
	}

private:
	void generateField();
	bool isTile(int row, int col, TileType type) const;
	bool isCanPlaceTent(int row, int col) const;


	int calcHintsForRow(int row);
	int calcHintsForCol(int col);
};

