#pragma once

#include <random>
#include <vector>

#include "Grid.h"
#include "Block.h"
#include "Blocks.cpp"
#include "GameData.h"

#include <SFML/Graphics.hpp>	


class Game
{
public:
	Game(sf::RenderWindow* window);
	
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();

	void Draw();

	void HandleInput();

	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();

	long score;
	int lines;
	int level;
	

	Grid grid;

	double dropSpeed;

private:
	bool IsBlockOutside();
	void RotateBlockRight();
	void RotateBlockLeft();

	void LockBlock();
	bool BlockFits();


	std::vector<Block> blocks;
	sf::RenderWindow* renderWindow;

	Block currentBlock;
	Block nextBlock;
	Block nextBlockCopy = Block(renderWindow);

	sf::VertexArray borders;

	int levels[28] = {
		10,   30,   60,   100,  210,
		280,  370,  450,  550,  650,
		750,  850,  950,  1050, 1150,
		1250, 1360, 1480, 1610, 1750,
		1910, 2080, 2260, 2450, 2650,
		2850, 3050, 3250
	};

	int dropSpeeds[30] = {
		48, 43, 38, 33, 28,
		23, 18, 13,  8,  6,
		 5,  5,  5,  4,  4,
		 4,  3,  3,  3,  2, 
		 2,  2,  2,  2,  2,
		 2,  2,  2,  2,  1
	};

	bool blockCanMove;
	bool blockCanRotate;

	bool gameOver;

	
	sf::Font font;
	sf::Text nextText;

	sf::Text scoreText;
	sf::Text scoreNumText;

	sf::Text levelText;
	sf::Text levelNumText;

	sf::Text linesText;
	sf::Text linesNumText;

};

