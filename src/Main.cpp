#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "NES Tetris");

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
	}
	return 0;
}