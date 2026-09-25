#include "Field.h"

class Utils {
	static void print(const Field& tiles) {
		for (auto& row : tiles) {
			for (auto& t : row) {
				char value;
				switch (t) {
				case tileType::Tree: value = 'T'; break;
				case tileType::Tent: value = '^'; break;
				case tileType::TentUnrevealed: value = '*'; break;
				case tileType::None: value = '_'; break;
				}
				std::cout << std::setw(3) << value;
			}
			std::cout << std::endl;
		}
	}
};