#pragma once
#include <iostream>

enum direction
{
	STOP,LEFT,UPLEFT,DOWNLEFT,RIGHT,UPRIGHT,DOWNRIGHT
};
	namespace pong_ball
	{
		class ball
		{
		public:
			int originalX, originalY;// starting values for the ball
			int currentX, currentY;//current position of the ball
			direction dir;
			
			public:
			ball(int x, int y);
			void reset();// reset the position
			
			 int getX();
			 int getY();
			 int getDirection();
			 void randomDirection();
			 void changeDirection(direction d);
			void move();
			
			friend std::ostream& operator<<(std::ostream & stream, ball b);
			
		};
	}

