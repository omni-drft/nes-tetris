#include "Tetromino.h"



TetrominoI::TetrominoI(sf::RenderWindow& windowAd) : window(windowAd)
{
	shape.setPrimitiveType(sf::TriangleStrip);
	shape.resize(5);
	shape[0].position = sf::Vector2f(0.0f, 0.0f);
	shape[1].position = sf::Vector2f(128.0f, 0.0f);
	shape[2].position = sf::Vector2f(128.0f, 32.0f);
	shape[3].position = sf::Vector2f(0.0f, 32.0f);
	shape[4].position = sf::Vector2f(0.0f, 0.0f);

	for (int i = 0; i < 5; i++)
		shape[i].color = sf::Color::Color(1, 104, 57, 255);

	position = 1;

}

void TetrominoI::draw() 
{ 
	window.draw(shape); 
}

void TetrominoI::move(float x, float y)
{
	for (int i = 0; i < 5; i++)
	{
		shape[i].position.x += x;
		shape[i].position.y += y;
	}
}

void TetrominoI::setPosition(float x, float y)
{
	for (int i = 0; i < 5; i++)
	{
		shape[i].position.x = x;
		shape[i].position.y = y;
	}
}

void TetrominoI::rotateRight()
{
	;
}

void TetrominoI::rotateLeft()
{
	;
}