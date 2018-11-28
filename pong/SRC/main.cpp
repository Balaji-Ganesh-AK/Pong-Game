#include "gamemanager.h"
#include "ball.h"
#include<GLFW/glfw3.h>
#include <gl/gl.h>




using namespace pong_paddle;
using namespace pong_ball;
using namespace game;

int main()
{	
	//gamemanager g(40, 20);
	//g.run();
	//system("PAUSE");
	GLFWwindow * window;

	glfwInit();

	window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Failed to load windows";
		system("PAUSE");
		return 0;
	}
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_QUADS);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(-0.5f, 0.5f);
		glVertex2d(0.5f, 0.5f);
		glVertex2d(0.5f, -0.5f);
		glEnd();
		glfwPollEvents();
		glfwSwapBuffers(window);

		
	}
	glfwPollEvents();
	
	return 0;

}