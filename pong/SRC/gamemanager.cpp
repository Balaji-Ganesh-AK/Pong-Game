#include "gamemanager.h"
#include <time.h>
using namespace pong_ball;
using namespace pong_paddle;
using namespace game;

game::gamemanager::gamemanager(int x, int y)
{
	srand(time(NULL));
	quit = false;
	width = x; height = y;
	cball = new ball(x/ 2, y / 2);
	cpaddle_1 = new paddle(1 , y/2 - 3);
	cpaddle_2 = new paddle(x-2, y / 2 - 3);
	score_1 = 0;
	score_2 = 0;

}

game::gamemanager::~gamemanager()
{
	delete cball, cpaddle_1, cpaddle_2;
}

void game::gamemanager::scoreCounter(paddle *paddleCheck)
{
	if (paddleCheck == cpaddle_1)
	{
		score_1++;
	}
	else if (paddleCheck == cpaddle_2)
	{
		score_2++;
	}
	cball->reset();
	cpaddle_1->reset();
	cpaddle_2->reset();
}

void game::gamemanager::getValues()
{
	 cballx = cball->getX();
	 cbally = cball->getY();
	 cpaddle_1x = cpaddle_1->getX();
	 cpaddle_1y = cpaddle_1->getY();
	 cpaddle_2x = cpaddle_2->getX();
	 cpaddle_2y = cpaddle_2->getY();
}



void game::gamemanager::draw()
{
	system("cls");
	

	for (int i = 0; i < width + 2; i++)
		std::cout << "\xDB";
	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			getValues();
			if (j == 0)
				std::cout << "\xDB";
			if (cballx ==j && cbally == i)
				std::cout << "O";
			else if (cpaddle_1x == j && cpaddle_1y == i)
				std::cout << "\xBA";
			else if (cpaddle_2x == j && cpaddle_2y == i)
				std::cout << "\xBA";
			else if (cpaddle_1x == j && cpaddle_1y+1 == i)
				std::cout << "\xBA";
			else if (cpaddle_1x == j && cpaddle_1y+2 == i)
				std::cout << "\xBA";
			else if (cpaddle_1x == j && cpaddle_1y+3 == i)
				std::cout << "\xBA";
			else if (cpaddle_2x == j && cpaddle_2y + 1 == i)
				std::cout << "\xBA";
			else if (cpaddle_2x == j && cpaddle_2y + 2 == i)
				std::cout << "\xBA";
			else if (cpaddle_2x == j && cpaddle_2y + 3 == i)
				std::cout << "\xBA";
			else
				std::cout << " ";
			if (j == width-1)
				std::cout << "\xDB";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < width + 2; i++)
		std::cout << "\xDB";
	std::cout << std::endl;

	std::cout << "Score 1 :" << score_1 << "Score 2 :" << score_2 << std::endl;
	
}
void game::gamemanager::input()
{
	cball->move();
	getValues();
	if (_kbhit())
	{
		char currentChar = _getch();//gets the current character pressed
		if (currentChar == up_1)
		{
			if (cpaddle_1y > 0)
				cpaddle_1->moveUp();
		}
		if (currentChar == up_2)
		{
			if (cpaddle_2y > 0)
				cpaddle_2->moveUp();
		}
		if (currentChar == down_1)
		{
			if (cpaddle_1y+4 < height)
				cpaddle_1->moveDown();
		}
		if (currentChar == down_2)
		{
			if (cpaddle_2y+4 < height)
				cpaddle_2->moveDown();
		}
		if (cball->getDirection() == STOP)
		{
			cball->randomDirection();
		}
		if (currentChar == 'q')
			quit = true;

		
	}

}

void gamemanager::logic()
{
	getValues();
	//left paddle
	for (int i = 0; i < 4; i++)
	{
		if (cballx == cpaddle_1x + 1)
		{
			if (cbally== cpaddle_1y+i)
			{
				cball->changeDirection((direction)((rand()%3)+4));
			}
		}
	}
	//right paddle
	for (int i = 0; i < 4; i++)
	{
		if (cballx == cpaddle_2x -1)
		{
			if (cbally == cpaddle_2y + i)
			{
				cball->changeDirection((direction)((rand() % 3) + 1));
			}
		}
	}
	//bottom wall
	if (cbally == height - 1)
		cball->changeDirection(cball->getDirection()== DOWNRIGHT ? UPRIGHT : UPLEFT);
	//top wall
	if (cbally ==0)
		cball->changeDirection(cball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	//right wall
	if (cballx == width - 1)
		scoreCounter(cpaddle_1);
	//left wall
	if (cballx == 0)
		scoreCounter(cpaddle_2);
}
void gamemanager::run()
{
	while (!quit)
	{
		draw();
		input();
		logic();

	}
}
