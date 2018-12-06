#include "gamemanager.h"
#include "ball.h"

// Controls are w and s For player 1.
// Controls are i and k For player 2.
// Small bugs and flicker are there, trying to fix them.



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