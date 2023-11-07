#include "Block.h"
#include "Position.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class IBlock : public Block
{
public:
	IBlock(sf::RenderWindow& window) : Block(window) {
		id = 1;
		cells[0] = { Position(1, 0), Position(1, 1),  Position(1, 2), Position(1, 3) };
		cells[1] = { Position(0, 2), Position(1, 2),  Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1),  Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1),  Position(2, 1), Position(3, 1) };
		Move(-1, 3);
	}
};


class JBlock : public Block
{
public:
	JBlock(sf::RenderWindow& window) : Block(window) {
		id = 2;
		cells[0] = { Position(0, 0), Position(1, 0),  Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(0, 2),  Position(1, 1), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1),  Position(1, 2), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 1),  Position(2, 0), Position(2, 1) };
		Move(0, 3);
	}
};

class LBlock : public Block
{
public:
	LBlock(sf::RenderWindow& window) : Block(window) 
	{
		id = 3;
		cells[0] = { Position(0, 2), Position(1, 0),  Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1),  Position(2, 1), Position(2, 2) };
		cells[2] = { Position(1, 0), Position(1, 1),  Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1),  Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class OBlock : public Block
{
public:
	OBlock(sf::RenderWindow& window) : Block(window)
	{
		id = 4;
		cells[0] = { Position(0, 0), Position(0, 1),  Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 0), Position(0, 1),  Position(1, 0), Position(1, 1) };
		cells[2] = { Position(0, 0), Position(0, 1),  Position(1, 0), Position(1, 1) };
		cells[3] = { Position(0, 0), Position(0, 1),  Position(1, 0), Position(1, 1) };
		Move(0, 4);
	}
};

class SBlock : public Block
{
public:
	SBlock(sf::RenderWindow& window) : Block(window)
	{
		id = 5;
		cells[0] = { Position(0, 1), Position(0, 2),  Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 1), Position(1, 1),  Position(1, 2), Position(2, 2) };
		cells[2] = { Position(1, 1), Position(1, 2),  Position(2, 0), Position(2, 1) };
		cells[3] = { Position(0, 0), Position(1, 0),  Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class TBlock : public Block
{
public:
	TBlock(sf::RenderWindow& window) : Block(window)
	{
		id = 6;
		cells[0] = { Position(0, 1), Position(1, 0),  Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1),  Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1),  Position(1, 2), Position(2, 1) };
		cells[3] = { Position(0, 1), Position(1, 0),  Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class ZBlock : public Block
{
public:
	ZBlock(sf::RenderWindow& window) : Block(window)
	{
		id = 7;
		cells[0] = { Position(0, 0), Position(0, 1),  Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 2), Position(1, 1),  Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1),  Position(2, 1), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 0),  Position(1, 1), Position(2, 0) };
		Move(0, 3);
	}
};
