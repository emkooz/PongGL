#include "Sound.h"

using namespace irrklang;
//using namespace NSound;

void NSound::PlaySound (const char* filename)
{
	if (!init)
	{
		init = true;

		sound = createIrrKlangDevice();
	}

	sound->PlaySound(filename , true);
}