#include <glfw.h>
#include <iostream>
#include "ball.h"
#include "Paddle.h"

static unsigned int Width = 800;
static unsigned int Height = 600;

int main()
{
	if (!glfwInit())
	{
		std::cout << "GLFW Couldn't initialize! \n";
		exit(1);
	}

	glfwOpenWindow(Width,Height,0,0,0,0,0,0,GLFW_WINDOW);
	glfwSetWindowTitle("Racist Pong");
	glViewport(0,0,Width,Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,Width,Height,0,0,1);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0,0,1,1);

	Npad::SetScreen(Width , Height);
	Nball::SetScreen(Width, Height);

	Nball::Ball ball;
	Npad::SetCollisions(&ball);

	Npad::Paddle Player(Height - 20 , 60);
	Npad::Paddle Enemy(20 , 60);

	Player.SetControl();

	float LastTime = glfwGetTime();

	while (true)
	{
		float DeltaTime = glfwGetTime() - LastTime;
		LastTime = glfwGetTime();


		if (!glfwGetWindowParam(GLFW_OPENED))
		{
			std::cout << "Window was closed! Exiting...\n";
			exit(0);
		}

		ball.Update (DeltaTime);
		Player.Update (DeltaTime);
		Enemy.Update (DeltaTime);

		glClear(GL_COLOR_BUFFER_BIT);

		ball.Draw();
		Player.Draw();
		Enemy.Draw();

		glfwSwapBuffers();
	}

	return 0;
}