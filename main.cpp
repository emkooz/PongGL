#include <glfw.h>
#include <iostream>
#include <irrKlang.h>
#include "ball.h"
#include "Paddle.h"
#include "Menu.h"
#include "Score.h"

using namespace irrklang;

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
	glfwSetWindowTitle("Shazbot Pong");
	glViewport(0,0,Width,Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,Width,Height,0,0,1);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0,0,1,1);

	// start the sound engine with default parameters
   ISoundEngine* sound = createIrrKlangDevice();
		if (!sound)
			return 0;

	NMenu::CMenu Menu(Width , Height);

	CScore score;

	Npad::SetScreen(Width , Height);
	Nball::SetScreen(Width, Height);

	Nball::Ball ball;
	Npad::SetCollisions(&ball);
	ball.SetScore(&score);

	Npad::Paddle Player(Height - 20 , 60);
	Npad::Paddle Enemy(20 , 60);

	Player.SetControl();

	
	float LastTime = glfwGetTime(); // (for deltatime)
	
	
	

	bool EscPressed = false; // thanks naelstrof
	bool EscReleased = true;
	while (true)
	{
		

		float DeltaTime = glfwGetTime() - LastTime; // Deltatime init
		LastTime = glfwGetTime(); // update for deltatime

		if (glfwGetKey(GLFW_KEY_ESC) && EscReleased  && !EscPressed)
		{
			EscReleased = false;
			EscPressed = true;
		}
		

		if (EscPressed && !EscReleased) // if they press escape
		{
			if (NMenu::State == "Playing") //if the state is playing
			{
				NMenu::State = "Paused"; // change it to paused
				std::cout <<"\n\n-----PAUSED-----\n\n";
			}

			else if (NMenu::State == "Paused") // else if the state is paused
				NMenu::State = "Playing"; // change it to playing
	
			EscPressed = false;
		}

		if (!glfwGetKey(GLFW_KEY_ESC))
		{
			EscPressed = false;
			EscReleased = true;
		}
		

		if (!glfwGetWindowParam(GLFW_OPENED))
		{
			std::cout << "Window was closed! Exiting...\n";
			exit(0);
		}

		if (NMenu::State == "Menu")
		{	
			Menu.Update();

			if (NMenu::MusicState == "Playing")
			{
				sound->play2D("sounds/song.ogg" , true);
			}
		}

		if (NMenu::State == "Playing") // if the state is playing update everything
		{
		ball.Update (DeltaTime);
			if (NMenu::SoundState == "Shazbot")
			{
				sound->play2D ("sounds/shazbot.ogg" , true);
				NMenu::SoundState = "\0";
			}


		Player.Update (DeltaTime); // update everything
		Enemy.Update (DeltaTime);
		}
		glClear(GL_COLOR_BUFFER_BIT);

		if (NMenu::State == "Menu")
		{
			Menu.Draw();
		}

		if (NMenu::State == "Playing" || NMenu::State == "Paused")
		{
		Menu.BgDraw();
		ball.Draw();
		Player.Draw(); // draws
		Enemy.Draw();
		}
		glfwSwapBuffers();
	}

	sound->drop();
	return 0;
}