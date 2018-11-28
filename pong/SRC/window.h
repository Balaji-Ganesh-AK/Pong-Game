#pragma once
#include<GLFW/glfw3.h>
#include <iostream>

int pongglfw() {
	GLFWwindow * window;

	

	window = glfwCreateWindow(640,480,"Hello world",NULL,NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Failed to load windows";
		return -1;
	}
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwPollEvents();
	return 0;
}