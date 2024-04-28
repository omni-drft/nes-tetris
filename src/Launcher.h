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
	GameData savedData;
	sf::RenderWindow* window;
};
