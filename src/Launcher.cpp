#include "Launcher.h"

Launcher::Launcher(sf::RenderWindow* window)
	: window(window), startExit(true), isArrowPressed(false), exitFlag(false)
{
	std::string file = "save.bin";
	savedData = loadGameData(file);
	std::cout << savedData.gamesPlayed << std::endl;
	std::cout << savedData.maxScore << std::endl;
	
	font.loadFromFile("fonts/tetrisFont.ttf");

	titleText.setFont(font);
	titleText.setString("NES-Tetris");
	titleText.setCharacterSize(30);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(sf::Vector2f(200.0f, 50.0f));

	maxScoreText.setFont(font);
	maxScoreText.setString("Max Score:");
	maxScoreText.setCharacterSize(24);
	maxScoreText.setFillColor(sf::Color::White);
	maxScoreText.setPosition(sf::Vector2f(80.0f, 140.0f));

	std::string maxScore;

	if (savedData.maxScore < 100)
		maxScore = "0000" + std::to_string(savedData.maxScore);
	else if (savedData.maxScore < 1000)
		maxScore = "000" + std::to_string(savedData.maxScore);
	else if (savedData.maxScore < 10000)
		maxScore = "00" + std::to_string(savedData.maxScore);
	else if (savedData.maxScore < 100000)
		maxScore = "0" + std::to_string(savedData.maxScore);
	else
		maxScore = std::to_string(savedData.maxScore);

	maxScoreNum.setFont(font);
	maxScoreNum.setString(maxScore);
	maxScoreNum.setCharacterSize(24);
	maxScoreNum.setFillColor(sf::Color::White);
	maxScoreNum.setPosition(sf::Vector2f(450.0f, 140.0f));

	gamesPlayedText.setFont(font);
	gamesPlayedText.setString("Games Played:");
	gamesPlayedText.setCharacterSize(24);
	gamesPlayedText.setFillColor(sf::Color::White);
	gamesPlayedText.setPosition(sf::Vector2f(80.0f, 190.0f));

	std::string gamesPlayed;
	if (savedData.gamesPlayed < 10)
		gamesPlayed = "00000" + std::to_string(savedData.gamesPlayed);
	else if (savedData.gamesPlayed < 100)
		gamesPlayed = "0000" + std::to_string(savedData.gamesPlayed);
	else if (savedData.gamesPlayed < 1000)
		gamesPlayed = "000" + std::to_string(savedData.gamesPlayed);
	else if (savedData.gamesPlayed < 10000)
		gamesPlayed = "00" + std::to_string(savedData.gamesPlayed);
	else if (savedData.gamesPlayed < 100000)
		gamesPlayed = "0" + std::to_string(savedData.gamesPlayed);
	else
		gamesPlayed = std::to_string(savedData.gamesPlayed);

	gamesPlayedNum.setFont(font);
	gamesPlayedNum.setString(gamesPlayed);
	gamesPlayedNum.setCharacterSize(24);
	gamesPlayedNum.setFillColor(sf::Color::White);
	gamesPlayedNum.setPosition(sf::Vector2f(450.0f, 190.0f));

	startText.setFont(font);
	startText.setString("Start");
	startText.setCharacterSize(24);
	startText.setFillColor(sf::Color::White);
	startText.setPosition(sf::Vector2f(290.0f, 320.0f));

	exitText.setFont(font);
	exitText.setString("Exit");
	exitText.setCharacterSize(24);
	exitText.setFillColor(sf::Color::White);
	exitText.setPosition(sf::Vector2f(303.0f, 360.0f));

	startArrow.setFont(font);
	startArrow.setString(">");
	startArrow.setCharacterSize(24);
	startArrow.setFillColor(sf::Color::White);
	startArrow.setPosition(sf::Vector2f(240.0f, 320.0f));

	exitArrow.setFont(font);
	exitArrow.setString(">");
	exitArrow.setCharacterSize(24);
	exitArrow.setFillColor(sf::Color::Red);
	exitArrow.setPosition(sf::Vector2f(240.0f, 360.0f));

}

void Launcher::LauncherLoop()
{
	window->draw(titleText);
	window->draw(maxScoreText);
	window->draw(maxScoreNum);
	window->draw(gamesPlayedText);
	window->draw(gamesPlayedNum);

	window->draw(startText);
	window->draw(exitText);

	window->draw(startArrow);
	window->draw(exitArrow);

	if (startExit)
	{
		startArrow.setFillColor(sf::Color::White);
		exitArrow.setFillColor(sf::Color::Black);
	}
	else
	{
		startArrow.setFillColor(sf::Color::Black);
		exitArrow.setFillColor(sf::Color::White);
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !isArrowPressed)
	{
		startExit = !startExit;
		isArrowPressed = true;
	}

	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
		isArrowPressed = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		if (startExit)
			window->close();
		else
			exitFlag = true;
}
