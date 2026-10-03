#include "GameHandler.h"
#include <iostream>

GameHandler::GameHandler(sf::RenderWindow& window, GameLogic& logic):
	window(window),
	logic(logic)
{
	
}

void GameHandler::handleEvents() {
	while (auto event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window.close();
		handleMouseClick(*event);
	}
}

void GameHandler::handleMouseClick(const sf::Event& event) {
	if (event.is<sf::Event::MouseButtonPressed>()) {
		sf::Vector2i mousePos = event.getIf<sf::Event::MouseButtonPressed>()->position;
		int row = (mousePos.y / TILE_SIZE) - 1;
		int col = (mousePos.x / TILE_SIZE) - 1;
		logic.tentReveal(row, col);		
	}
}