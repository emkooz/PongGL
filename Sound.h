#include <irrKlang.h>

#ifndef SOUND_NAMESPACE
#define SOUND_NAMESPACE

namespace NSound //Gee, why didn't I think of this?
{

	static bool init = false;
	irrklang::ISoundEngine* sound;
	void PlaySound (const char* filename);

}

#endif