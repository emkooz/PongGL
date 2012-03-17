#include "Sound.h"

using namespace irrklang;


void NSound::PlaySound (const char* filename , bool foo)
{
	if (!NSound::init)
	{
		NSound::init = true;

		NSound::sound = createIrrKlangDevice();
	}
	
	if (foo)
		NSound::sound->play2D(filename , true);
	
	else if (!foo)
		NSound::sound->play2D(filename);
}

