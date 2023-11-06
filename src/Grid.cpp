#include "Grid.h"

Grid::Grid()
{
	rows = 20;
	cols = 10;
	blockSize = 32.0f;
	Initialise();
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