#pragma once
#include<iostream>
#include <conio.h>


	namespace pong_paddle
	{
		class paddle
		{
		public:
			int originalX, originalY;// starting values for the paddle
			int currentX, currentY;//current position of the paddle

		public:
			paddle();
			paddle(int x,int y);
			int getX();
			int getY();
			void moveUp();
			void moveDown();
			void reset();
			friend std::ostream& operator<<(std::ostream & stream, paddle b);

		};
	}
