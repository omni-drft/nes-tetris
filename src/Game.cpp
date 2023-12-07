#include "Game.h"

Game::Game(sf::RenderWindow* window) : renderWindow(window), grid(Grid(window)), currentBlock(GetRandomBlock()), nextBlock(GetRandomBlock())
{
	blocks = GetAllBlocks();
	blockCanMove = true;
	blockCanRotate = true;
	dropSpeed = 48.0 / 60;

	nextBlockCopy = nextBlock;

	gameOver = false;

	score = 0;
	lines = 0;

	level = 0;

	borders = sf::VertexArray(sf::LineStrip, 5);
	borders[0].position = sf::Vector2f(80.0f, 80.0f);
	borders[1].position = sf::Vector2f(320.0f, 80.0f);
	borders[2].position = sf::Vector2f(320.0f, 560.0f);
	borders[3].position = sf::Vector2f(80.0f, 560.0f);
	borders[4].position = sf::Vector2f(80.0f, 80.0f);

	font.loadFromFile("fonts/tetrisFont.ttf");
	scoreText.setFont(font);
	scoreText.setString("  Score  ");
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(sf::Vector2f(407.0f, 220.0f));

	scoreNumText.setFont(font);
	scoreNumText.setString(std::to_string(score));
	scoreNumText.setCharacterSize(24);
	scoreNumText.setFillColor(sf::Color::White);
	scoreNumText.setPosition(sf::Vector2f(445.0f, 255.0f));

	nextText.setFont(font);
	nextText.setString("  Next  ");
	nextText.setCharacterSize(24);
	nextText.setFillColor(sf::Color::White);
	nextText.setPosition(sf::Vector2f(420.0f, 80.0f));

	levelText.setFont(font);
	levelText.setString("  Level  ");
	levelText.setCharacterSize(24);
	levelText.setFillColor(sf::Color::White);
	levelText.setPosition(sf::Vector2f(407.0f, 300.0f));

	levelNumText.setFont(font);
	levelNumText.setString(std::to_string(level));
	levelNumText.setCharacterSize(24);
	levelNumText.setFillColor(sf::Color::White);
	levelNumText.setPosition(sf::Vector2f(490.0f, 335.0f));

	linesText.setFont(font);
	linesText.setString("  Lines  ");
	linesText.setCharacterSize(24);
	linesText.setFillColor(sf::Color::White);
	linesText.setPosition(sf::Vector2f(407.0f, 380.0f));

	linesNumText.setFont(font);
	linesNumText.setString(std::to_string(lines));
	linesNumText.setCharacterSize(24);
	linesNumText.setFillColor(sf::Color::White);
	linesNumText.setPosition(sf::Vector2f(470.0f, 415.0f));
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
	if (!gameOver)
	{
		for (int i = 0; i < 28; i++)
		{
			if (lines >= levels[i])
			{
				level = i + 1;
			}
		}
		
		dropSpeed = dropSpeeds[level] / 60.0;

		grid.Draw();
		currentBlock.Draw();
	
		// SCORE

		renderWindow->draw(scoreText);

		if (score < 10)
			scoreNumText.setString("00000" + std::to_string(score));
		else if (score < 100)
			scoreNumText.setString("0000" + std::to_string(score));
		else if (score < 1000)
			scoreNumText.setString("000" + std::to_string(score));
		else if (score < 10000)
			scoreNumText.setString("00" + std::to_string(score));
		else if (score < 100000)
			scoreNumText.setString("0" + std::to_string(score));
		else
			scoreNumText.setString(std::to_string(score));


		renderWindow->draw(scoreNumText);
	
		// NEXT BLOCK

		renderWindow->draw(nextText);
		nextBlockCopy.DrawAt(405.0f, 120.0f);

		// LEVEL

		renderWindow->draw(levelText);
		if (level < 10)
			levelNumText.setString("0" + std::to_string(level));
		else 
			levelNumText.setString(std::to_string(level));

		renderWindow->draw(levelNumText);
	
		// LINES

		renderWindow->draw(linesText);

		if (lines < 10)
			linesNumText.setString("000" + std::to_string(lines));
		else if (lines < 100)
			linesNumText.setString("00" + std::to_string(lines));
		else if (lines < 1000)
			linesNumText.setString("0" + std::to_string(lines));
		else
			linesNumText.setString(std::to_string(lines));

		renderWindow->draw(linesNumText);

		// BORDERS

		renderWindow->draw(borders);
	}
	else {
		scoreText.setCharacterSize(40);
		scoreText.setPosition(170.0f, 200.0f);

		scoreNumText.setCharacterSize(40);
		scoreNumText.setPosition(230.0f, 250.0f);

		renderWindow->draw(scoreText);
		renderWindow->draw(scoreNumText);

		//std::cout << "TEST\n";
	}
}

void Game::HandleInput()
{
	if (gameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			gameOver = false;
			grid.Clear();
			score = 0;
			lines = 0;
			level = 0;
			
			scoreText.setCharacterSize(24);
			scoreText.setPosition(sf::Vector2f(407.0f, 220.0f));

			scoreNumText.setCharacterSize(24);
			scoreNumText.setPosition(sf::Vector2f(445.0f, 255.0f));
		}
		else 
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
			score++;
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
	nextBlockCopy = nextBlock;

	grid.ClearFullRows();
	
	if (grid.ClearedRows == 1)
		score += 40 * (level + 1);
	else if (grid.ClearedRows == 2)
		score += 100 * (level + 1);
	else if (grid.ClearedRows == 3)
		score += 300 * (level + 1);
	else if (grid.ClearedRows == 4)
		score += 1200 * (level + 1);

	lines += grid.ClearedRows;
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
