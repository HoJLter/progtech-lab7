#pragma once
#include "SFML/Graphics.hpp"
#include "Map.h"


class GameEngine {
	sf::RenderWindow window;
	Map map;

private:
	void handleEvents();
	void render();

public:
	GameEngine(sf::Vector2u size);
	void run();
};