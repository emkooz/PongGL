#include "Sound.h"

using namespace irrklang;
//using namespace NSound;

void NSound::PlaySound (const char* filename)
{
	if (!NSound::init)
	{
		NSound::init = true;

		NSound::sound = createIrrKlangDevice();
	}

	NSound::sound->play2D(filename , true);
}

