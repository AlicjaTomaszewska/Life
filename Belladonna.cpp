#include <iostream>
#include "Belladonna.h"

using namespace std;

Belladonna::Belladonna(int coordinateX, int coordinateY, World* world) : Plant(coordinateX, coordinateY, world, STRENGTH_OF_BELLADONNA, INITIATIVE_OF_BELLADONNA, LETTER_OF_BELLADONNA, NAME_OF_BELLADONNA)
{
}

Belladonna::Belladonna(World* world) : Plant(world, STRENGTH_OF_BELLADONNA, INITIATIVE_OF_BELLADONNA, LETTER_OF_BELLADONNA, NAME_OF_BELLADONNA)
{
}

Belladonna::~Belladonna()
{
}

void Belladonna::draw()
{
	cout << LETTER_OF_BELLADONNA;
}