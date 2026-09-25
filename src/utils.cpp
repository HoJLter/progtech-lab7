#include "Field.h"
#include <iostream>
#include <iomanip>

class Utils {
public:
	static void print(const Field& field) {
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				char value;
				switch (field.getTile(i, j)) {
				case TileType::Tree: value = 'T'; break;
				case TileType::Tent: value = '^'; break;
				case TileType::TentUnrevealed: value = '*'; break;
				case TileType::None: value = '_'; break;
				}
				std::cout << std::setw(3) << value;
			}
			std::cout << std::endl;
		}
	}
};