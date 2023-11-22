#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <Windows.h>
#include <iostream>

#include "Game.h"

int main()
{
	FreeConsole();
	sf::RenderWindow window(sf::VideoMode(700, 640), "NES-Tetris");
	Game game = Game(&window);

	//game.dropSpeed = 0.1;

	sf::Clock clock;
	sf::Time targetFrameTime = sf::seconds(1.0f / 60.0f);

	sf::Clock dropClock;
	sf::Time dropTimeInterval = sf::Time::Zero;

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

		sf::Time elapsedTime = clock.getElapsedTime();
		if (elapsedTime >= targetFrameTime)
		{

			game.HandleInput();

			window.clear(sf::Color::Black);
		
			game.Draw();

			window.display();

			dropTimeInterval = dropClock.getElapsedTime();
			if (dropTimeInterval.asSeconds() >= game.dropSpeed)
			{
				dropClock.restart();
				game.MoveBlockDown();
			}
			
		}
		
	}
	return 0;
}