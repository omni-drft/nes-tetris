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
	bool getExitFlag() { return exitFlag; }
private:

	sf::Font font;

	sf::Text titleText;

	sf::Text maxScoreText;
	sf::Text maxScoreNum;

	sf::Text gamesPlayedText;
	sf::Text gamesPlayedNum;

	sf::Text startText;
	sf::Text exitText;

	sf::Text startArrow;
	sf::Text exitArrow;

	GameData savedData;
	sf::RenderWindow* window;

	bool startExit;
	bool isArrowPressed;
	bool exitFlag;
};
