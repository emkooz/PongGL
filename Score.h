#include <glfw.h>
#include <iostream>

#ifndef SCORE
#define SCORE

class CScore
{
public:
	CScore();
	void aiAdd();
	void p1Add();
	void Display();

	int ai, p1;
};



#endif