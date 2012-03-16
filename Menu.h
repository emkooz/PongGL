#include <glfw.h>
#include <string>

#ifndef MENU
#define MENU

namespace NMenu
{

	static unsigned int Width , Height;

	static std::string State;
	static std::string MusicState;
	static std::string SoundState;

class CMenu
{
public:
	

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