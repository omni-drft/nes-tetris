#include "Block.h"

Block::Block(sf::RenderWindow& window) : currentWindow(window)
{
	cellSize = 32.0f;
	rotationState = 0;
	colors = GetCellColors();

	xOffset = 0.0f;
	yOffset = 0.0f;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		sf::RectangleShape block;
		block.setSize(sf::Vector2f(cellSize - 1.0f, cellSize- 1.0f));
		block.setPosition(sf::Vector2f(item.col * cellSize + 1.0f, item.row * cellSize + 1.0f));
		block.setFillColor(colors.at(id));
		currentWindow.draw(block);
	}
}

void Block::Move(float x, float y)
{
	xOffset += x;
	yOffset += y;
}

std::vector<Position> Block::GetCellPositions()
{
	std::vector<Position> tiles = cells.at(rotationState);
	std::vector<Position> movedTiles;

	for (Position item : tiles)
	{
		Position newPosition = Position(item.row + xOffset, item.col + yOffset);
		movedTiles.push_back(newPosition);
	}

	return movedTiles;
}
