#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "Colors.h"

class Grid
{
public:
	
	Grid(sf::RenderWindow& window);
	void Initialise();
	void Print();
	void Draw();

	int grid[20][10];
private:

	int rows;
	int cols;
	float blockSize;
	std::vector<sf::Color> colors;

	sf::RenderWindow& currentWindow;
};