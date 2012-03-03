#ifndef PADDLE
#define PADDLE
#include <glfw.h>
#include "ball.h"



namespace Npad
{
	static unsigned int Width,Height;
    void SetScreen(unsigned int, unsigned int);
    static Nball::Ball* CollisionBall;
    void SetCollisions(Nball::Ball*);

class Paddle
{
public:
	bool IsControlled;
	void SetControl();

	float x, y, vx , vy, w;

	Paddle (float , float);

	void Draw();
	void Update(float);

};

}
#endif