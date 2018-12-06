#include "gamemanager.h"
#include "ball.h"
#include<GLFW/glfw3.h>
#include <gl/gl.h>




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
