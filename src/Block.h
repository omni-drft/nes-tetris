#pragma once

#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "Position.h"
#include "Colors.h"

class Block
{
public:
	Block(sf::RenderWindow* window);
	void Draw();
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
	std::vector<sf::Color> colors;
	float xOffset, yOffset;
};

