#include "ball.h"

using namespace Nball;

Ball::Ball()
{
	x = Width/2;
	y = Height/2;
	vx = 50;
	vy = 50;
}

void Ball::Draw()
{
	glPushMatrix();
	glTranslatef(x,y,0);
	glBegin(GL_QUADS);
	glVertex2f(-20,-20);
	glVertex2f(20,-20);
	glVertex2f(20,20);
	glVertex2f(-20,20);
	glEnd();
	glPopMatrix();
}

void Ball::Update(float DeltaTime)
{
	if (glfwGetKey(GLFW_KEY_KP_8)) //go up!
	{
		vy -= 500 * DeltaTime;

	}

	if (glfwGetKey(GLFW_KEY_KP_5)) // go down!
	{
		vy += 500 * DeltaTime;
		
	}

	if (glfwGetKey(GLFW_KEY_KP_4)) // go left!
	{
		vx -= 500 * DeltaTime;
	}

	if (glfwGetKey(GLFW_KEY_KP_6)) //go right!
	{
		vx += 500 * DeltaTime;
	}

	 if (x+20>Width)
    {
        x = Width-20;
        vx *= -1;
    }
	 
	 else if (x-20<0)
    {
        x = 20;
        vx *= -1;
    }

	 if (y - 20 <= 0) // check if it hit the top, if it did add a point for the AI and revert it back to the middle.
	 {
		 Score->p1Add();
		 Score->Display(); // display the new score.
		 x = Width/2;
		 y = Height/2;
	 }

	 if (y + 20 >= Height)
	 {
		 Score->aiAdd();
		 Score->Display();
		 x = Width/2;
		 y = Height/2;
	 }

    x += vx*DeltaTime;
    y += vy*DeltaTime;
	
}

void Nball::SetScreen(unsigned int w, unsigned int h)
{
	Width = w;
	Height = h;
}

void Ball::SetScore(CScore* foo)
{
	Score = foo;
}