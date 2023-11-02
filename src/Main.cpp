#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "InputHandling.h"

#include "Tetromino.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "NES Tetris");
	TetrominoI test(window);

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

		inputHandleI(test);

		window.clear(sf::Color::Color(61, 61, 61, 255));
		test.draw();
		window.display();

	}
	return 0;
}