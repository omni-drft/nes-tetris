#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Tetromino.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "NES Tetris");
	TetrominoI test(window);
	bool isMovedR = false, isMovedL = false, isMovedD = false;
	bool isRotatedR = false, isRotatedL;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if(!isMovedR)
				test.move(32.0f, 0.0f);
				isMovedR = true;
		}
		else
		{
			isMovedR = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (!isMovedL)
				test.move(-32.0f, 0.0f);
			isMovedL = true;
		}
		else
		{
			isMovedL = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (!isMovedD)
				test.move(0.0f, 32.0f);
			isMovedD = true;
		}
		else
		{
			isMovedD = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			if (!isRotatedR)
				test.rotateRight();
			isRotatedR = true;
		}
		else
		{
			isRotatedR = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			if (!isRotatedL)
				test.rotateLeft();
			isRotatedL = true;
		}
		else
		{
			isRotatedL = false;
		}

		window.clear(sf::Color::Color(61, 61, 61, 255));
		test.draw();
		window.display();

	}
	return 0;
}