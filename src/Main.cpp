#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <windows.h>

#include <iostream>

#include "Game.h"
#include "Launcher.h"

int main()
{
	FreeConsole();

	while (true)
	{


	sf::RenderWindow startWindow(sf::VideoMode(700, 450), "NES-Tetris Launcher");
	Launcher launcherWindow(&startWindow);

	while (startWindow.isOpen())
	{
		sf::Event event;
		while (startWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				startWindow.close();
				return 0;
			}
		}
		startWindow.clear(sf::Color::Black);
		launcherWindow.LauncherLoop();
		startWindow.display();

		if (launcherWindow.getExitFlag())
			return 0;

	}

	startWindow.close();

	sf::RenderWindow window(sf::VideoMode(700, 640), "NES-Tetris");
	Game game = Game(&window);

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
	window.close();
	}
	return 0;
}