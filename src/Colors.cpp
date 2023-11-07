#include "Colors.h"

const sf::Color gray = sf::Color::Color(26, 31, 40, 255);
const sf::Color cyan = sf::Color::Color(1, 241, 240, 255);
const sf::Color blue = sf::Color::Color(1, 0, 241, 255);
const sf::Color orange = sf::Color::Color(240, 160, 0, 255);
const sf::Color yellow = sf::Color::Color(241, 240, 1, 255);
const sf::Color green = sf::Color::Color(0, 240, 0, 255);
const sf::Color purple = sf::Color::Color(161, 1, 240, 255);
const sf::Color red = sf::Color::Color(241, 0, 1, 255);

std::vector<sf::Color> GetCellColors()
{
	return { gray, cyan, blue, orange, yellow, green, purple, red };
}