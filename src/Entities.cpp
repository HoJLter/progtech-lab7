#include "Entities.h"

Tree::Tree(sf::RenderWindow& window):
	shape(50.f, 3),
	Entity(window)
{
	shape.setFillColor(sf::Color::Green);
}

void Tree::render() {
	window.draw(shape);
}

Camping::Camping(sf::RenderWindow& window) :
	shape(50.f, 16),
	Entity(window)
{
	shape.setFillColor(sf::Color::Yellow);
}

void Camping::render(){
	window.draw(shape);
}
