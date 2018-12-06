#include "gamemanager.h"
#include "ball.h"





using namespace pong_paddle;
using namespace pong_ball;
using namespace game;

int main()
{	
	gamemanager g(40, 20);
	g.run();
	system("PAUSE");
	
	
	return 0;

}
