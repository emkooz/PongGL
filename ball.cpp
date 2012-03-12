#include "ball.h"
#include <SOIL.h>

using namespace Nball;

Ball::Ball()
{
	BallImg = SOIL_load_OGL_texture
	(
		"img/ball.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	x = Width/2;
	y = Height/2;
	vx = 50;
	vy = 50;
}

void Ball::Draw()
{
	glPushMatrix();
	glTranslatef(x,y,0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D , BallImg); std::cout << "\nBallIm TexID:" << BallImg;

	glBegin(GL_QUADS);
		
		glTexCoord2f(0,0);
		glVertex2f(-20,-20);
		
		glTexCoord2f(1,0);
		glVertex2f(20,-20);
		
		glTexCoord2f(1,1);
		glVertex2f(20,20);
		
		glTexCoord2f(0,1);
		glVertex2f(-20,20);
		

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
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