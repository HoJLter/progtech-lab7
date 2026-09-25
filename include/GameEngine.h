#pragma once
#include "SFML/Graphics.hpp"

#include "GameLogic.h"
#include "GameRenderer.h"

class GameEngine {
	sf::RenderWindow window;
	GameLogic logic;
	GameRenderer renderer;

private:
	void handleEvents();

public:
	GameEngine(sf::Vector2u size);
	void run();

};