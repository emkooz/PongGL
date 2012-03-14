#include "Menu.h"
#include <glfw.h>
#include <SOIL.h>

NMenu::CMenu::CMenu(float X , float W)
{
	State = "Menu";
	
	MenuImg = SOIL_load_OGL_texture
	(
		"img/menu.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	x = X;
	y = Y;

}

void NMenu::CMenu::Draw()
{
	glPushMatrix();
	glTranslatef(x,y,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D , MenuImg); 
	glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex2f(0 , 0);
		
		glTexCoord2f(1,0);
		glVertex2f(x,0);
		
		glTexCoord2f(1,1);
		glVertex2f(x , y);
        
		glTexCoord2f(0,1);
		glVertex2f(0 , y);
		
		
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void NMenu::CMenu::Update()
{
	if (glfwGetMousePos() < 
}


