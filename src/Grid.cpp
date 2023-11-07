#include "Grid.h"



Grid::Grid(sf::RenderWindow& window) : currentWindow(window)
{
	rows = 20;
	cols = 10;
	blockSize = 32.0f;

	Initialise();
	colors = GetCellColors();
}

void Grid::Initialise()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void Grid::Print()
{

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Grid::Draw()
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int cellValue = grid[i][j];
			sf::RectangleShape block;
			block.setSize(sf::Vector2f(blockSize - 1.0f, blockSize - 1.0f));
			block.setPosition(sf::Vector2f(blockSize * j + 1.0f, blockSize * i + 1.0f));
			block.setFillColor(colors.at(cellValue));
			currentWindow.draw(block);
		}
	}
}