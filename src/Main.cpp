#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>


#include "Grid.h"
#include "Blocks.cpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "NES-Tetris");
	Grid grid = Grid(window);
	grid.Print();

	TBlock block = TBlock(window);

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

		window.clear(sf::Color::Color(190, 190, 190, 255));

		grid.Draw();
		block.Draw();

		window.display();
	}
	return 0;
}