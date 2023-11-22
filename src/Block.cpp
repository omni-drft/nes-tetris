#include "Block.h"

Block::Block(sf::RenderWindow* window) : currentWindow(window)
{
	cellSize = 24.0f;
	rotationState = 0;

	xOffset = 0.0f;
	yOffset = 0.0f;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPositions();

	for (Position item : tiles)
	{
		sf::RectangleShape block;
		block.setSize(sf::Vector2f(cellSize, cellSize));
		block.setPosition(sf::Vector2f(80.0f + item.col * cellSize, 80.0f + item.row * cellSize));
		block.setFillColor(colors.at(id));
		currentWindow->draw(block);
	}
}

void Block::DrawAt(float x, float y)
{
	std::vector<Position> tiles = GetCellPositions();

	for (Position item : tiles)
	{
		sf::RectangleShape block;
		block.setSize(sf::Vector2f(cellSize, cellSize));
		block.setPosition(sf::Vector2f(x + item.col * cellSize, y + item.row * cellSize));
		block.setFillColor(colors.at(id));
		currentWindow->draw(block);
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

void Block::RotateRight()
{
	rotationState++;
	rotationState %= 4;
}

void Block::RotateLeft()
{
	rotationState += 3;
	rotationState %= 4;
}
