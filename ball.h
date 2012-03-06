#include <glfw.h>
#include "Score.h"

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
		CScore* Score;
	
		Ball();
		void Draw();
		void Update(float);
		void SetScore(CScore*);

	};
}
#endif