#include "include/Filament.hpp"
#include <iostream>

#define WIDTH 400
#define HEIGHT 400

int main()
{
	Filament f;
	f.setup(WIDTH, HEIGHT);
	f.run();
	f.cleanup();
}