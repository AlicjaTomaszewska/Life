#include <iostream>
#include "Sheep.h"

using namespace std;

Sheep::Sheep(int coordinateX, int coordinateY, World* world) : Animal(coordinateX, coordinateY, world, STRENGTH_OF_SHEEP, INITIATIVE_OF_SHEEP, LETTER_OF_SHEEP, NAME_OF_SHEEP)
{
}

Sheep::Sheep(World* world) : Animal(world, STRENGTH_OF_SHEEP, INITIATIVE_OF_SHEEP, LETTER_OF_SHEEP, NAME_OF_SHEEP)
{
}

Sheep::~Sheep()
{
}

void Sheep::draw()
{
	cout << LETTER_OF_SHEEP;
}
