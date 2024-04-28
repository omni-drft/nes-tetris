#include "Launcher.h"

Launcher::Launcher(sf::RenderWindow* window)
	: window(window) 
{
	std::string file = "save.bin";
	savedData = loadGameData(file);
	std::cout << savedData.gamesPlayed << std::endl;
	std::cout << savedData.maxScore << std::endl;
}

void Launcher::LauncherLoop()
{

}
