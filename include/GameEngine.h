#pragma once
#include "SFML/Graphics.hpp"

#include "GameLogic.h"
#include "GameRenderer.h"
#include "GameHandler.h"

class GameEngine {
	sf::RenderWindow window;
	GameLogic logic;
	GameRenderer renderer;
	GameHandler handler;

private:
	void handleClick(const sf::Event& event);

public:
	GameEngine(sf::Vector2u size);
	void run();

};