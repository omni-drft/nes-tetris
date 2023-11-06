#pragma once

#include <iostream>
#include <vector>

class Grid
{
public:
	
	Grid();
	void Initialise();
	void Print();

	int grid[20][10];
private:
	int rows;
	int cols;
	float blockSize;
	std::vector<sf::Color> colors
};