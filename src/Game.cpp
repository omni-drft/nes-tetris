#include "Game.h"

Game::Game(sf::RenderWindow* window) : renderWindow(window), grid(Grid(window)), currentBlock(GetRandomBlock()), nextBlock(GetRandomBlock())
{
	blocks = GetAllBlocks();
	blockCanMove = true;
	blockCanRotate = true;
	dropSpeed = 1.0;

	gameOver = false;
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}

	int randInd = rand() % blocks.size();
	Block block = blocks.at(randInd);

	blocks.erase(blocks.begin() + randInd);

	return block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(renderWindow), JBlock(renderWindow), LBlock(renderWindow), OBlock(renderWindow), SBlock(renderWindow), TBlock(renderWindow), ZBlock(renderWindow) };
}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw();
}

void Game::HandleInput()
{
	if (gameOver)
	{
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (blockCanMove)
		{
			MoveBlockLeft();
			blockCanMove = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (blockCanMove)
		{
			MoveBlockRight();
			blockCanMove = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (blockCanMove)
		{
			MoveBlockDown();
			blockCanMove = false;
		}
	}
	else
	{
		blockCanMove = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		if (blockCanRotate)
		{
			RotateBlockLeft();
			blockCanRotate = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (blockCanRotate)
		{
			RotateBlockRight();
			blockCanRotate = false;
		}
	}
	else
	{
		blockCanRotate = true;
	}
}

void Game::MoveBlockLeft()
{
	currentBlock.Move(0, -1);
	if (IsBlockOutside() || !BlockFits())
	{
		currentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight()
{
	currentBlock.Move(0, 1);
	if (IsBlockOutside() || !BlockFits())
	{
		currentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown()
{
	currentBlock.Move(1, 0);
	if (IsBlockOutside() || !BlockFits())
	{
		currentBlock.Move(-1, 0);
		LockBlock();
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.col))
		{
			return true;
		}
	}

	return false;
}

void Game::RotateBlockRight()
{
	currentBlock.RotateRight();
	if (IsBlockOutside() || !BlockFits())
	{
		currentBlock.RotateLeft();
	}
}

void Game::RotateBlockLeft()
{
	currentBlock.RotateLeft();
	if (IsBlockOutside() || !BlockFits())
	{
		currentBlock.RotateRight();
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.col] = currentBlock.id;
	}
	currentBlock = nextBlock;

	if (!BlockFits())
	{
		gameOver = true;
	}

	nextBlock = GetRandomBlock();

	grid.ClearFullRows();
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (!grid.IsCellEmpty(item.row, item.col))
		{
			return false;
		}
	}
	return true;
}
