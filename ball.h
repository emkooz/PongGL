#include <glfw.h>

#ifndef BALL
#define BALL

namespace Nball
{

	static  unsigned int Width, Height;
	void SetScreen(unsigned int , unsigned int);

	class Ball
	{
	public:
		float x, y, vx , vy;	
	
		Ball();
		void Draw();
		void Update(float);
	};
}
#endif