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
	float angle = 90.0f;
	double pi = 3.14159265358979323846;

	sf::Vector2f pivotPoint((shape[2].position + shape[3].position) / 2.0f);
	
	double radians = angle * pi / 180.0f;

	double cosA = std::cos(radians);
	double sinA = std::sin(radians);

	for (int i = 0; i < 5; i++)
	{
		sf::Vector2f offset = shape[i].position - pivotPoint;
		shape[i].position.x = pivotPoint.x + offset.x * cosA - offset.y * sinA;
		shape[i].position.y = pivotPoint.y + offset.x * sinA + offset.y * cosA;
	}
}

void TetrominoI::rotateLeft()
{
	{
		float angle = -90.0f;
		double pi = 3.14159265358979323846;

		sf::Vector2f pivotPoint((shape[2].position + shape[3].position) / 2.0f);

		double radians = angle * pi / 180.0f;

		double cosA = std::cos(radians);
		double sinA = std::sin(radians);

		for (int i = 0; i < 5; i++)
		{
			sf::Vector2f offset = shape[i].position - pivotPoint;
			shape[i].position.x = pivotPoint.x + offset.x * cosA - offset.y * sinA;
			shape[i].position.y = pivotPoint.y + offset.x * sinA + offset.y * cosA;
		}
	}
}