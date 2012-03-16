#include <irrKlang.h>

namespace NSound //Gee, why didn't I think of this?
{

	static bool init = false;
	static ISoundEngine* sound;
	void PlaySound (const char* filename);

}