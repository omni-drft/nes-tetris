#pragma once

#include <random>
#include <vector>

#include "Grid.h"
#include "Block.h"
#include "Blocks.cpp"


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

	bool blockCanMove;
	bool blockCanRotate;

	bool gameOver;

	long score;
};

