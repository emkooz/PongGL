#include "Image.h"


using namespace NImage;

void Init()
{
	ilInit();
	std::cout << "\nDevIL has been init'd.\n\n";
}

Image::Image(std::string foo)
{
	ILboolean result = ilLoadImage( foo) ;
}