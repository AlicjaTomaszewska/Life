#include <iostream>
#include <string>
#include "Wolf.h"

using namespace std;

Wolf::Wolf(int coordinateX, int coordinateY, World* world) : Animal(coordinateX, coordinateY, world, STRENGTH_OF_WOLF, INITIATIVE_OF_WOLF, LETTER_OF_WOLF, NAME_OF_WOLF)
{
}

Wolf::Wolf(World* world) : Animal(world, STRENGTH_OF_WOLF, INITIATIVE_OF_WOLF, LETTER_OF_WOLF, NAME_OF_WOLF)
{
}

Wolf::~Wolf()
{
}

void Wolf::draw()
{
	cout << LETTER_OF_WOLF;
}