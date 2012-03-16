#include "Menu.h"
#include <glfw.h>
#include <SOIL.h>
#include <iostream>
#include <irrKlang.h>

NMenu::CMenu::CMenu(float X , float Y)
{
	NMenu::State = "Menu";
	NMenu::SoundState = "\0";
	
	MenuImg = SOIL_load_OGL_texture
	(
		"img/menu.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	x = X;
	y = Y;

	BgImg = SOIL_load_OGL_texture
	(
		"img/bg.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	x = X;
	y = Y;

}

void NMenu::CMenu::Draw()
{
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D , MenuImg); 
	glBegin(GL_QUADS);

		glTexCoord2f(0,1);
		glVertex2f(0 , 0);
		
		glTexCoord2f(1,1);
		glVertex2f(x,0);
		
		glTexCoord2f(1,0);
		glVertex2f(x , y);
        
		glTexCoord2f(0,0);
		glVertex2f(0 , y);
		
		
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}

void NMenu::CMenu::BgDraw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D , BgImg); 
	glBegin(GL_QUADS);

		glTexCoord2f(0,1);
		glVertex2f(0 , 0);
		
		glTexCoord2f(1,1);
		glVertex2f(x,0);
		
		glTexCoord2f(1,0);
		glVertex2f(x , y);
        
		glTexCoord2f(0,0);
		glVertex2f(0 , y);
		
		
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}

void NMenu::CMenu::Update()
{
	glfwGetMousePos(&MouseX , &MouseY);

	if (MouseX < 500 && MouseX > 300 && MouseY < 294 && MouseY > 200 && glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT))
	{
		//std::cout << "\nMouseX: " << MouseX << "\nMouseY: " << MouseY;  (only enable for testing)
			NMenu::State = "Playing";
			NMenu::MusicState = "Playing";

			
	}

	if (MouseX < 500 && MouseX > 300 && MouseY < 491 && MouseY > 399 && glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) 
	{
		glfwCloseWindow();
	}
}


