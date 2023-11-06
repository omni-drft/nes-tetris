#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Grid.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "NES-Tetris");

	Grid grid = Grid();
	grid.Print();

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

		window.clear(sf::Color::Color(24, 24, 24, 255));
		window.display();
	}
	return 0;
}