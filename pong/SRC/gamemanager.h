#include "ball.h"
#include "paddle.h"
#include <io.h>
using namespace pong_ball;
using namespace pong_paddle;
	namespace game
	{
		class gamemanager
		{
		private:
			int width, height;
			
			ball *cball;
			paddle *cpaddle_1;
			paddle *cpaddle_2;
			int score_1, score_2;
			char up_1='w', up_2='i', down_1='s', down_2='k';
			int cballx, cbally, cpaddle_1x, cpaddle_2x, cpaddle_2y, cpaddle_1y;
			
		public:
			bool quit;
			gamemanager(int x,int y);
			~gamemanager();// prevents the memory leaks
			void scoreCounter(paddle *paddleCheck);
			void getValues();
			void draw();
			void input();
			void logic();
			void run();
		};
	}
