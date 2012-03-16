#include "Paddle.h"
#include <SOIL.h>
#include <irrKlang.h>



using namespace irrklang;
using namespace Npad;

Paddle::Paddle(float Y , float W)
{
	PadImg = SOIL_load_OGL_texture
	(
		"img/pad.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D , PadImg); 
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex2f(-w,-10);
		
		glTexCoord2f(1,0);
		glVertex2f(w,-10);
		
		glTexCoord2f(1,1);
		glVertex2f(w,10);
        
		glTexCoord2f(0,1);
		glVertex2f(-w,10);
		
		
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
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