#include "Paddle.h"

using namespace Npad;

Paddle::Paddle(float Y , float W)
{
	x = Width/2;
	vx = 0;
	y = Y;
	w = W;
	IsControlled = false;
}

void Paddle::SetControl()
{
	IsControlled = true;
}

void Paddle::Draw()
{
	glPushMatrix();
	glTranslatef(x,y,0);
	glBegin(GL_QUADS);
			glColor3f(1.0f , 1.0f , 0.0f);
		glVertex2f(-w,-10);
		 	
		glVertex2f(w,-10);
		glColor3f(18.0f, 1.0f, 1.0f);
		glVertex2f(w,10);
	
		glVertex2f(-w,10);
		glColor3f(0.0f , 0.0f , 0.0f);

	glEnd();
	glPopMatrix();
}

void Paddle::Update(float DeltaTime)
{
	if (IsControlled)
	{
		if (glfwGetKey(GLFW_KEY_LEFT))
		{
			vx -= 3000 * DeltaTime;
		}

		else if (glfwGetKey(GLFW_KEY_RIGHT))
		{
			vx += 3000 * DeltaTime;
		}
	}

	else 
	{
		if (x < CollisionBall->x)
		{
			vx += 3000 * DeltaTime;
		}

		else if (x > CollisionBall->x)
		{
			vx -= 3000 * DeltaTime;
		}
	}

	x += vx * DeltaTime;
	vx *= 1 - (5 * DeltaTime);

	if (x + w > Width)
	{
		x = Width - w;
		vx = 0;
	}

	else if (x - w < 0)
	{
		x = w;
		vx = 0;
	}


	if (CollisionBall->y - 20 < y + 20 && CollisionBall->y + 20 > y - 20)
	{
		if (CollisionBall->x - 20 < x + w && CollisionBall->x + 20 > x - w)
		{
			CollisionBall->vx = (CollisionBall->x - x) * 5;
			CollisionBall->vy *= -1;

			if (CollisionBall->y > y)
			{
				CollisionBall->y = y + 40;
			}

			else 
			{
				CollisionBall->y = y - 40;
			}
		}
	}

	if (glfwGetKey(GLFW_KEY_ESC))
	{
		glfwCloseWindow();
	}

}

void Npad::SetScreen(unsigned int w , unsigned int h)
{
	Width = w;
	Height = h;
}

void Npad::SetCollisions (Nball::Ball* foo)
{
	CollisionBall = foo;
}