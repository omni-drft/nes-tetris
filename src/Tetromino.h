#include <SFML/Graphics.hpp>

#pragma once

class TetrominoI
{
public:

	TetrominoI(sf::RenderWindow& windowAd);
	void draw();
	void move(float x, float y);
	void setPosition(float x, float y); 
	void rotateRight();
	void rotateLeft();

private:
	sf::VertexArray shape;
	sf::RenderWindow& window;
	
	// 1 - spawn position
	// 2 - 90 degrees
	// 3 - 180 degrees
	// 4 - 270 degrees
	int position;
};
