#pragma once

#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "Position.h"

class Block
{
public:
	Block(sf::RenderWindow* window);
	void Draw();
	void DrawAt(float x, float y);
	void Move(float x, float y);
	std::vector<Position> GetCellPositions();

	void RotateRight();
	void RotateLeft();
	
	int id;
	std::map<int, std::vector<Position>> cells;
private:
	float cellSize;
	int rotationState;

	sf::RenderWindow* currentWindow;
	std::vector<sf::Color> colors = { sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White, sf::Color::White };
	float xOffset, yOffset;
};

