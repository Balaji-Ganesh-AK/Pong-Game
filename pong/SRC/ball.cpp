#include "ball.h"


using namespace pong_ball;

pong_ball::ball::ball(int x, int y)
{
	this->originalX = x;
	this->originalY = y;
	this->currentX = x;
	this->currentY = y;
	dir = STOP;
}

void ball::reset()
{
	currentX = originalX;
	currentY = originalY;
	dir = STOP;
}



 int ball::getX()
{
	return currentX;
}

int ball::getY()
{
	return currentY;
}

int ball::getDirection()
{
	return dir;
}

void pong_ball::ball::randomDirection()
{
	dir = (direction)((rand() % 6) + 1);
}

void ball::changeDirection(direction d)
{
	dir = d;
}

void ball::move()
{
	switch (dir)
	{
	case STOP:
		break;
	case LEFT:
		currentX--;
		break;
	case UPLEFT:
		currentX--;
		currentY--;
		break;
	case DOWNLEFT:
		currentX--;
		currentY++;
		break;
	case RIGHT:
		currentX++;
		break;
	case UPRIGHT:
		currentX++;
		currentY--;
		break;
	case DOWNRIGHT:
		currentX++;
		currentY--;
		break;
	default:
		break;
	}
}



std::ostream & pong_ball::operator<<(std::ostream & stream, ball b)
{
	stream <<"["<<b.currentX << "," <<b.currentY<<"]["<<b.dir<<"]";
	return stream;
}
