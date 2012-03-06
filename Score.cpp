#include "Score.h"

CScore::CScore()
{
	ai = 0; p1 = 0;
}

void CScore::aiAdd()
{
	ai++;
}

void CScore::p1Add()
{
	p1++;
}

void CScore::Display()
{
	std::cout << "\nAI's score: " << ai << "\nPlayer 1's score: " << p1;
}
