#include <iostream>
#include "Guarana.h"

using namespace std;

Guarana::Guarana(int coordinateX, int coordinateY, World* world) : Plant(coordinateX, coordinateY, world, STRENGTH_OF_GUARANA, INITIATIVE_OF_GUARANA, LETTER_OF_GUARANA, NAME_OF_GUARANA)
{
}

Guarana::Guarana(World* world) : Plant(world, STRENGTH_OF_GUARANA, INITIATIVE_OF_GUARANA, LETTER_OF_GUARANA, NAME_OF_GUARANA)
{
}

Guarana::~Guarana()
{
}

void Guarana::draw()
{
	cout << LETTER_OF_GUARANA;
}