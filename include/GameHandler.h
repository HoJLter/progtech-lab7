#pragma once
#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "GameRenderer.h"

class GameHandler {
	GameLogic& logic;
	sf::RenderWindow& window;
	

	void handleMouseClick(const sf::Event& event);
public:
	GameHandler(sf::RenderWindow& window, GameLogic& logic);
	void handleEvents();
};