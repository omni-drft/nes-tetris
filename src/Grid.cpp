#include "Grid.h"



Grid::Grid(sf::RenderWindow* window) : currentWindow(window)
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
			block.setSize(sf::Vector2f(blockSize, blockSize));
			block.setPosition(sf::Vector2f(blockSize * j, blockSize * i));
			block.setFillColor(colors.at(cellValue));
			currentWindow->draw(block);
		}
	}
}

bool Grid::IsCellOutside(int row, int col)
{
	return !(row >= 0 && row < rows && col >= 0 && col < cols);
}

bool Grid::IsCellEmpty(int row, int col)
{
	return !(grid[row][col]);
}

int Grid::ClearFullRows()
{
	int cleared = 0;
	for (int i = rows - 1; i >= 0; i--)
	{
		if (isRowFull(i))
		{
			ClearRow(i);
			cleared++;
		}
		else if (cleared > 0)
		{
			MoveRowDown(i, cleared);
		}
	}
	return cleared;
}

bool Grid::isRowFull(int row)
{
	for (int i = 0; i < cols; i++)
	{
		if (!grid[row][i])
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int i = 0; i < cols; i++)
	{
		grid[row][i] = 0;
	}
}

void Grid::MoveRowDown(int row, int numOfRows)
{
	for (int i = 0; i < cols; i++)
	{
		grid[row + numOfRows][i] = grid[row][i];
		grid[row][i] = 0;
	}
}
