#include "Map.h"
#include <cstdlib>
#include <ctime>

Map::Map(sf::RenderWindow& window) :
	window(window)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			entities[i][j] = generateRandomEntity();
			entities[i][j]->setPos({ i * TILE_SIZE, j * TILE_SIZE });
		}
	}
}

Entity* Map::generateRandomEntity() {
	int min = 0;
	int max = 100;
	int randomNumber = min + rand() % (max - min + 1);

	if (randomNumber <= 15) {
		return new Tree(window);
	}
	else return new Nothing(window);
}

void Map::handleEvent(const sf::Event& event) {
	for (auto& row : entities) {
		for (auto& e : row) {
			e->handleEvent(event);
		}
	}
}

void Map::render() {
	for (auto row : entities) {
		for (auto e : row) {
			e->render();
		}
	}
}
