#include"paddle.h"
using namespace pong_paddle;

pong_paddle::paddle::paddle()
{
	currentX = currentY = 0;
}

pong_paddle::paddle::paddle(int x, int y)
{
	this->originalX = x;
	this->originalY = y;
	this->currentX = x;
	this->currentY = y;
}

int paddle::getX()
{
	return currentX;
}

int paddle::getY()
{
	return currentY;
}

void paddle::moveUp()
{
	currentY--;
}

void paddle::moveDown()
{
	currentY++;
}

void paddle::reset()
{
	currentX = originalX;
	currentY = originalY;
}

std::ostream & pong_paddle::operator<<(std::ostream & stream, paddle b)
{
	stream << "Paddle [" << b.currentX << "," << b.currentY << "]";
	return stream;
}
