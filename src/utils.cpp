#include "Utils.h"
#include <iostream>
#include <iomanip>

void Utils::print(const Field& field) {
	for (int row = 0; row < MAP_SIZE; row++) {
		for (int col = 0; col < MAP_SIZE; col++) {
			char value;
			switch (field.getTile(row, col)) {
			case TileType::Tree: value = 'O'; break;
			case TileType::Tent: value = 'T'; break;
			case TileType::TentUnrevealed: value = 'O'; break;
			case TileType::None: value = '-'; break;
			default: value = ' ';
			}
			std::cout << std::setw(3) << value;
		}
		std::cout << std::endl;
	}
}