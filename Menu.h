#include <glfw.h>
#include <string>

#ifndef MENU
#define MENU

namespace NMenu
{

	static unsigned int Width , Height;

	
	

class CMenu
{
public:
	std::string State;
	

	float x , y;
	int MouseX , MouseY;

	GLuint MenuImg;
	GLuint BgImg;

	CMenu(float , float);

	void Draw();
	void BgDraw();
	void Update();
	

};






}
#endif