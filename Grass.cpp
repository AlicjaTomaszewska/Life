#include <iostream>
#include "Grass.h"

using namespace std;

Grass::Grass(int coordinateX, int coordinateY, World* world) : Plant(coordinateX, coordinateY, world, STRENGTH_OF_GRASS, INITIATIVE_OF_GRASS, LETTER_OF_GRASS, NAME_OF_GRASS)
{
}

Grass::Grass(World* world) : Plant(world, STRENGTH_OF_GRASS, INITIATIVE_OF_GRASS, LETTER_OF_GRASS, NAME_OF_GRASS)
{
}

Grass::~Grass()
{
}

void Grass::draw()
{
	cout << LETTER_OF_GRASS;
}