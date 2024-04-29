#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "GameData.h"

class Launcher 
{
public:
	Launcher(sf::RenderWindow* window);
	void LauncherLoop();
private:

	sf::Font font;

	sf::Text titleText;

	sf::Text maxScoreText;
	sf::Text maxScoreNum;

	sf::Text gamesPlayedText;
	sf::Text gamesPlayedNum;

	GameData savedData;
	sf::RenderWindow* window;
};
